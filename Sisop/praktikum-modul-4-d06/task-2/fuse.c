#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <ctype.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

// Constants
static const char *repo_url = "https://github.com/hqlco/target";
static const char *clone_dir = "/home/cchoirun/Documents/sisop/prak4/task2_new/target";

// Function to clone repository
void clone_repository() {
    char command[256];
    snprintf(command, sizeof(command), "git clone %s %s", repo_url, clone_dir);
    system(command);
}

// Function to create users and set permissions
void create_users_and_set_permissions() {
    char *usernames[] = {"andi", "budi", "cony", "deni"};
    char *dirs[] = {"/home/cchoirun/Documents/sisop/prak4/task2_new/target/andi", "/home/cchoirun/Documents/sisop/prak4/task2_new/target/budi", "/home/cchoirun/Documents/sisop/prak4/task2_new/target/cony", "/home/cchoirun/Documents/sisop/prak4/task2_new/target/deni"};
    char *password = "password123";

    for (int i = 0; i < 4; i++) {
        char command[256];

        // Tambahkan user baru
        snprintf(command, sizeof(command), "sudo adduser %s --disabled-password --gecos \"\"", usernames[i]);
        system(command);

        // Set password user
        snprintf(command, sizeof(command), "echo '%s:%s' | sudo chpasswd", usernames[i], password);
        system(command);

        // Ubah pemilik dan grup dari direktori
        snprintf(command, sizeof(command), "sudo chown -R %s:%s %s", usernames[i], usernames[i], dirs[i]);
        system(command);

        // Atur izin untuk direktori
        snprintf(command, sizeof(command), "sudo chmod 755 %s", dirs[i]);
        system(command);

        // Tambahkan izin untuk grup dan others
        snprintf(command, sizeof(command), "sudo chmod -R g+r,o+r %s", dirs[i]);
        system(command);
    }
}

// Base64 Encoding
static char *base64_encode(const char *input, int length) {
    BIO *b64, *bmem;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);

    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    char *buff = (char *)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;

    BIO_free_all(b64);

    return buff;
}

// Base64 Decoding
static char *base64_decode(const char *input, int length, int *out_length) {
    BIO *b64, *bmem;
    char *buffer = (char *)malloc(length);
    memset(buffer, 0, length);

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);

    *out_length = BIO_read(bmem, buffer, length);
    BIO_free_all(bmem);

    return buffer;
}

// Function to get file attributes
static int xmp_getattr(const char *path, struct stat *stbuf) {
    int res;
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);

    res = lstat(fpath, stbuf);
    if (res == -1) return -errno;

    return 0;
}

// Function to read directory
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    char fpath[1000];
    if (strcmp(path, "/") == 0) {
        path = clone_dir;
        snprintf(fpath, sizeof(fpath), "%s", path);
    } else {
        snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);
    }

    int res = 0;
    DIR *dp;
    struct dirent *de;

    dp = opendir(fpath);
    if (dp == NULL) return -errno;

    while ((de = readdir(dp)) != NULL) {
        struct stat st;
        memset(&st, 0, sizeof(st));
        st.st_ino = de->d_ino;
        st.st_mode = de->d_type << 12;
        res = (filler(buf, de->d_name, &st, 0));
        if (res != 0) break;
    }

    closedir(dp);
    return 0;
}

// Function to open file
static int xmp_open(const char *path, struct fuse_file_info *fi) {
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);

    int fd = open(fpath, fi->flags);
    if (fd == -1) return -errno;

    fi->fh = fd;
    return 0;
}

// Function to read file
static int xmp_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    int fd = fi->fh;
    int res = pread(fd, buf, size, offset);
    if (res == -1) return -errno;

    close(fd);

    // Encode the content using Base64
    char *encoded = base64_encode(buf, res);
    strncpy(buf, encoded, size);
    res = strlen(encoded);
    free(encoded);

    return res;
}

// Function to write to file
static int xmp_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    int fd = fi->fh;
    char *decoded;
    int decoded_length;

    decoded = base64_decode(buf, size, &decoded_length);

    int res = pwrite(fd, decoded, decoded_length, offset);
    if (res == -1) res = -errno;

    // Set file permissions
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);
    chmod(fpath, 0644);

    close(fd);
    free(decoded);
    return res;
}

// Function to create directory
static int xmp_mkdir(const char *path, mode_t mode) {
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);

    int res = mkdir(fpath, mode);
    if (res == -1) return -errno;

    return 0;
}

// Function to delete file
static int xmp_unlink(const char *path) {
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);

    int res = unlink(fpath);
    if (res == -1) return -errno;

    return 0;
}

// Function to delete directory
static int xmp_rmdir(const char *path) {
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", clone_dir, path);

    int res = rmdir(fpath);
    if (res == -1) return -errno;

    return 0;
}

// Fuse operations structure
static struct fuse_operations xmp_oper = {
    .getattr = xmp_getattr,
    .readdir = xmp_readdir,
    .open = xmp_open,
    .read = xmp_read,
    .write = xmp_write,
    .mkdir = xmp_mkdir,
    .unlink = xmp_unlink,
    .rmdir = xmp_rmdir,
};

int main(int argc, char *argv[]) {
    umask(0);
    clone_repository();
    create_users_and_set_permissions();
    return fuse_main(argc, argv, &xmp_oper, NULL);
}
