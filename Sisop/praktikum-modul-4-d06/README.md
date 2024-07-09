[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/J5rciaaA)
<div align=center>

|    NRP     |      Name      |
| :--------: | :------------: |
| 5025221193 | Alief Gilang Permana Putra |
| 5025221203 | Muhammad Choirun Ni'am |

# Praktikum Modul 4 _(Module 4 Lab Work)_

</div>

### Daftar Soal _(Task List)_

- [Task 1 - TrashOps](/task-1/)

- [Task 2 - Fu53enC0d3D==](/task-2/)

- [Task 3 - MengOS](/task-3/)

# Laporan Resmi Praktikum Modul 4 _(Module 4 Lab Work Report)_

## 1. TrashOps
Pada soal ini kita diminta untuk mengimplementasikan fungsi trash sehingga file yang dihapus tidak langsung dihapus secara permanen melainkan melalui direktori trash yang dapat di restore kembali. Karena kode untuk soal ini lumayan panjang, maka pembahasannya akan dilakukan per fungsi dalam ```fuse_operations``` yang digunakan dan telah mencakup subtask a-f. Berikut adalah daftar ```fuse_operation``` yang digunakan:
```c
static struct fuse_operations xmp_oper = {
    .init = xmp_init,
    .getattr = xmp_getattr,
    .readdir = xmp_readdir,
    .mkdir = xmp_mkdir,
    .unlink = xmp_unlink,
    .rmdir = xmp_rmdir,
    .rename = xmp_rename,
    .chmod = xmp_chmod,
    .chown = xmp_chown,
    .read = xmp_read,
    .open = xmp_open,
};
```
Terdapat beberapa const yang digunakan untuk mendefinisikan direktori yang digunakan yaitu ```dirpath``` sebagai root path, ```trashpath``` sebagai path untuk trash, ```trashdata``` untuk menyimpan informasi file yang ada di dalam trash, dan ```trashlog``` yaitu direktori file ```trash.log``` yang digunakan untuk mencatat action.

Selain itu terdapat beberapa fungsi bantu yang digunakan, yaitu ```check_trash_dir``` untuk mengecek apakah direktori berada di dalam trash atau terdapat kata trash di dalamnya, dan ```log_action``` untuk mencatat action yang dilakukan ke dalam ```trash.log```
```c
//Function to log activity to file
int log_action(char *logs){
    time_t this_time = time(0);
    // Create a time structure to hold the formatted time
    struct tm *local_time = localtime(&this_time);
    // Define the format string
    char current_time[20]; // Allocate enough space for the formatted string
    strftime(current_time, sizeof(current_time), "%y%m%d-%H:%M:%S ", local_time);
    
    printf("Check time\n"); 
    printf("time: %s\n", current_time);

    int fd = open(trashlog, O_APPEND | O_WRONLY | O_CREAT, S_IRWXU);
    if(fd == -1 && errno != ENOENT) return -errno;
    
    write(fd,current_time,strlen(current_time));
    write(fd,logs,strlen(logs));
    //write(fd,"\n",strlen("\n"));
    printf("Logging action fuse\n");
    close(fd);
    return 0;
}

// Function to check trash
int check_trash_dir(const char *path){
    if(strstr(path,trashpath) != NULL || strstr(trashpath,path) != NULL) return -1;
    else if(strstr(path,"trash")) return -1;
    else return 0;
}
```
Pada ```fuse_operation```, fungsi pertama yang dipanggil saat program dijalankan adalah ```xmp_init``` yang berfungsi untuk menginisialisasi *fuse filesystem* dan sekaligus membuat direktori ```.trash``` yang terdapat di dalam direktori trash sebagai tempat menyimpan informasi file yaitu path dan *permission* awal file yang ada di dalam trash sebelum dihapus.
```c
static void *xmp_init(struct fuse_conn_info *conn) {
	(void) conn;
    mkdir(trashdata,0700);
	return NULL;
}
```
Berikutnya adalah fungsi ```xmp_getattr``` yang digunakan untuk mendapatkan informasi dan atribut file
```c
static int xmp_getattr(const char *path, struct stat *stbuf) {
    int res;
    char fpath[1000]="";
    if(strcmp(path,"/") == 0) {
        path=dirpath;
        snprintf(fpath,sizeof(fpath),"%s",path);
    }
    else snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);  
    //printf("get attribute of %s\n", fpath);
    res = lstat(fpath, stbuf);
    if (res == -1) return -errno;

    return 0;
}
```
Kemudian fungsi ```xmp_readdir``` dan ```xmp_read``` digunakan untuk membaca direktori dan file target
```c
// Function to read directory
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    char fpath[1000]="";
    if(strcmp(path,"/") == 0) {
        path=dirpath;
        snprintf(fpath,sizeof(fpath),"%s",path);
    }
    else snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path); 
    
    DIR *dp;
    struct dirent *de;
    (void) offset;
    (void) fi;

    dp = opendir(fpath);

    if (dp == NULL) return -errno;

    while ((de = readdir(dp)) != NULL) {
        struct stat st;

        memset(&st, 0, sizeof(st));

        st.st_ino = de->d_ino;
        st.st_mode = de->d_type << 12;

        if(filler(buf, de->d_name, &st, 0)) break;
    }
    closedir(dp);
    return 0;
}

// Function to read file
static int xmp_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    char fpath[1000]=""; 
    if(strcmp(path,"/") == 0) {
        path=dirpath;
        snprintf(fpath,sizeof(fpath),"%s",path);
    }
    else snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path); 
    
    printf("Check xmp_read\n");
    (void) fi;

    int fd = open(fpath, O_RDONLY);
    if (fd == -1) return -errno;

    int res = pread(fd, buf, size, offset);
    if (res == -1) res = -errno;

    close(fd);
    return res;
}
```
Lalu terdapat fungsi ```xmp_mkdir``` yang digunakan untuk membuat direktori. Pada fungsi ini dilakukan modifikasi apabila terdapat kata ```restore``` atau ```trash``` dalam direktori baru yang ingin dibuat, maka fungsi akan return ```-EACCES``` yang berarti action ditolak dan akan di log dalam ```trash.log```
```c
// Function to create directory
static int xmp_mkdir(const char *path, mode_t mode) {
    char fpath[1000]="";
    if(strcmp(path,"/") == 0) {
        path=dirpath;
        snprintf(fpath,sizeof(fpath),"%s",path);
    }
    else snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);
    
    if(check_trash_dir(fpath) !=0 || strstr(fpath,"restore") != NULL){
        int ec;
        if(strstr(fpath,"restore") != NULL){
            ec = log_action("FAILED TO CREATE RESTORE DIRECTORY\n");
            if (ec !=0) return ec;
        }
        else{
            ec = log_action("FAILED TO CREATE TRASH DIRECTORY\n");
            if (ec !=0) return ec;
        }
        
        return -EACCES;
    }
    
    int res = mkdir(fpath, mode);
    if (res == -1) return -errno;

    return 0;
}
```
Untuk membuka file, kita menggunakan fungsi ```xmp_open```
```c
// Open file
int xmp_open(const char *path, struct fuse_file_info *fi) {
    char fpath[1000]="";
    if(strcmp(path,"/") == 0) {
        path=dirpath;
        snprintf(fpath,sizeof(fpath),"%s",path);
    }
    else snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);
    printf("Checking %s flags %d\n", fpath, fi->flags);
    int res = open(fpath, fi->flags);
    if(res == -1) return -errno;
    return 0;
}
```
Fungsi ```xmp_rename``` merupakan salah satu fungsi krusial dalam implementasi trash pada soal ini, karena digunakan oleh perintah ```mv``` untuk memindahkan file keluar direktori trash dengan dua pilihan, yaitu ```restore``` untuk mengembalikannya ke tempat semula atau ke direktori baru tujuan di luar trash. Apabila direktori asal tidak ada ketika melakukan ```restore```, maka fungsi ini akan membuat baru direktori asal tersebut. Di dalam fungsi ini juga terdapat pencegahan untuk memindah direktori trash ataupun memindah file yang ada di dalam trash ke direktori lain tetapi masih di dalam trash tersebut. Semua percobaan tersebut akan dicatat ke dalam log dengan memanfaatkan fungsi ```log_action``` dengan parameter string yang akan di log. 
```c
//Function to rename file, used by mv,cp 
static int xmp_rename(const char *oldpath, const char *newpath) {
    int res;
    char oldfpath[1000]="";
    char newfpath[1000]="";
    snprintf(oldfpath, sizeof(oldfpath), "%s%s", dirpath, oldpath);
    snprintf(newfpath, sizeof(newfpath), "%s%s", dirpath, newpath);
    printf("%s\n", oldfpath);
    printf("%s\n", newfpath);
    char ftrashdata[1000]="";
    strcat(ftrashdata,trashdata);

    //Jika ingin memindah path trash
    if(strcmp(oldfpath,trashpath)==0) {
        int ec;
        ec = log_action("FAILED TO MOVE/RENAME TRASH DIRECTORY\n");
        if (ec !=0) return ec;
        
        return -EACCES;
    }
    //Cek oldfpath di dalam trash
    if(check_trash_dir(oldfpath) != 0){
        printf("%s\n", ftrashdata);
        char *tmpfiledata = strstr(oldpath,"/trash") + strlen("/trash");
        printf("%s\n",tmpfiledata);
        strcat(ftrashdata,tmpfiledata);
        printf("%s\n", ftrashdata);
        
        int fd = open(ftrashdata, O_RDONLY);
        if(fd == -1) return -errno;
        char buftmp[1010]="";
        read(fd,buftmp,sizeof(buftmp));
        //printf("%s\n", buftmp);
        char *pos = strchr(buftmp,'\n');
        char *tmpmode = strrchr(buftmp,'\n');
    
        mode_t restoremode = strtol(tmpmode,0,8);
        printf("%d\n",restoremode);

        // Apabila mencoba memindah file di dalam trash
        if(check_trash_dir(newfpath) != 0 && strcmp(newpath,"/trash/restore") != 0){
            int ec;
            char log_str[1000]="";
            snprintf(log_str,sizeof(log_str),"FAILED TO RENAME %s\n", oldfpath);
        
            ec = log_action(log_str);
            if (ec !=0) return ec;
            return -EACCES;
        }
        // Apabila memindah file di dalam trash ke luar/restore
        else { 
            //Restore file
            if(strcmp(newpath,"/trash/restore") == 0){
                // Return the substring up to the newline (excluding the newline)
                size_t len = pos - buftmp;
                char *restorepath = malloc(len + 1);
                if (restorepath == NULL) {
                    perror("malloc");
                    return -errno;
                }
                strncpy(restorepath, buftmp, len);
                restorepath[len] = '\0';
                
                printf("%s\n", restorepath);

                int res = chmod(oldfpath,restoremode);
                if(res == -1) return -errno;
                printf("Chmod restore\n");
                printf("restore path : %s\n", restorepath);
                res = rename(oldfpath,restorepath);
                if(res == -1){
                    if(errno == ENOENT){
                        char restoredir[strlen(restorepath)]; // Allocate enough space for the substring

                        // Find the length of the substring (excluding filename)
                        len = strrchr(restorepath, '/') - restorepath;

                        // Copy the substring to the result array
                        strncpy(restoredir, restorepath, len);
                        restoredir[len] = '\0'; // Null terminate the copied substring

                        printf("Print directory %s\n", restoredir);
                        //Create dir if not exist
                        res = mkdir(restoredir, 0755);
                        if (res == -1) return -errno;
                        res = rename(oldfpath,restorepath);
                        if (res == -1) return -errno;
                    }
                    else return -errno;
                } 
                int ec;
                char log_str[1000]="";
                snprintf(log_str,sizeof(log_str),"RESTORED %s FROM TRASH TO %s\n", oldfpath, newfpath);

                ec = log_action(log_str);
                if (ec !=0) return ec;

                printf("mv restore file\n");
                res = unlink(ftrashdata);
                if(res == -1) return -errno;
            }
            else{

                int res = chmod(oldfpath,restoremode);
                if(res == -1) return -errno;
                printf("%s\n", oldfpath);
                printf("%s\n", newfpath);
                res = rename(oldfpath, newfpath);
                if(res == -1) return -errno;
                int ec;
                char log_str[1000]="";
                snprintf(log_str,sizeof(log_str),"RESTORED %s FROM TRASH TO %s\n", oldfpath, newfpath);

                ec = log_action(log_str);
                if (ec !=0) return ec;

                printf("mv restore file\n");
                res = unlink(ftrashdata);
                if(res == -1) return -errno;
                //Restore file
            }
        }
        close(fd);
    } 
    // Apabila oldfpath tidak di dalam trash
    else {
        // Apabila newpath didalam trash
        if(check_trash_dir(newfpath) != 0){
            return -EACCES;
        }
        // Apabila oldfpath dan newfpathtidak di dalam trash
        else{
            res = rename(oldfpath, newfpath);
            if(res == -1) return -errno;
        }
    }
    return 0; 
}
```
Untuk mengubah permission dan kepemilikan file, digunakan fungsi ```xmp_chmod``` dan ```xmp_chown```. Pada kedua fungsi ini juga dilakukan modifikasi yang mencegah dilakukannya ```chmod``` dan ```chown``` di dalam direktori trash dengan return ```-EACCES```. Percobaan ini juga akan di log ke dalam ```trash.log```
```c
//Change permission of file
static int xmp_chmod(const char *path, mode_t mode){
    char fpath[1000];
    snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);
    
    if(check_trash_dir(fpath) == 0) {
        int res = chmod(fpath, mode);
        if(res == -1) return -errno;    
    }
    else {
        int ec;
        char log_str[1000]="";
        snprintf(log_str,sizeof(log_str),"FAILED TO CHMOD %s\n", fpath);
        
        ec = log_action(log_str);
        if (ec !=0) return ec;
        
        return -EACCES;
    }

    return 0;
}

//Change ownership of file
static int xmp_chown(const char *path, uid_t uid, gid_t gid){
    char fpath[1000]="";
    snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);
    
    if(check_trash_dir(fpath) == 0) {
        int res = chown(fpath, uid, gid);
        if(res == -1) return -errno;
    }
    else {
        int ec;
        char log_str[1000]="";
        snprintf(log_str,sizeof(log_str),"FAILED TO CHOWN %s\n", fpath);
        
        ec = log_action(log_str);
        if (ec !=0) return ec;
        return -EACCES;
    }

    return 0;
}
```
Selanjutnya merupakan fungsi inti dalam penerapan fitur trash, yaitu ```xmp_unlink``` yang akan memindahkan file ke dalam direktori trash dan mengubah permission menjadi 000 ketika perintah ```rm``` dijalankan dan membuat file dengan nama file yang dihapus ke dalam ```.trash``` yang berfungsi untuk menyimpan informasi path asal serta permission awal dari file yang dihapus tersebut. Apabila ```rm``` dijalankan di dalam file yang ada di trash, maka file akan dihapus beserta file yang berisi informasi asal file tersebut. Selain itu, apabila mencoba menghapus direktori trash maka akan return ```-EACCES``` untuk mencegah direktori trash terhapus.
```c
// Function to delete file
static int xmp_unlink(const char *path) {
    char fpath[1000]="";

    if(strstr(path,dirpath) == NULL){
        snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);   
    }
    else snprintf(fpath, sizeof(fpath), "%s", path);

    int res;
    struct stat statbuf;
    char *filename = strrchr(fpath, '/');
    char filedir[1000]="";

    strcpy(filedir,trashdata);
    printf("Check stat %s\n", fpath);
    stat(fpath, &statbuf);
    strcat(filedir,"/");
    strcat(filedir,filename);

    char tmp[1000]="";
    sprintf(tmp, "%s%s", trashdata,filename);
    printf("%s\n",tmp);
    
    // Check if try to remove trash
    if(strcmp(fpath,trashpath)==0) {
        int ec;
        ec = log_action("FAILED TO REMOVE TRASH DIRECTORY\n");
        if (ec !=0) return ec;
        
        return -EACCES;
    }

    // Check if file inside trash
    if(strstr(fpath,"trash") != NULL){
        // Permanently remove file inside trash
        if(check_trash_dir(fpath) != 0) {
            res = unlink(fpath);
            if(res == -1) return -errno;
            printf("Removing trash file\n");
            res = unlink(tmp);
            if(res == -1) return -errno;
            printf("Removing trash data file\n");

            int ec;
            char log_str[1000]="";
            snprintf(log_str,sizeof(log_str),"PERMANENTLY REMOVED %s\n", fpath);
        
            ec = log_action(log_str);
            if (ec !=0) return ec;
            
        }
        else return -1;
    }
    // If file not inside trash directory
    else {
        char newfilepath[1000]="";
        strcat(newfilepath, trashpath);
        strcat(newfilepath,filename);
        printf("file trash baru %s\n", newfilepath);
        printf("%s\n", fpath);

        res = rename(fpath, newfilepath);
        if(res == -1 ) return -errno;
        printf("Sudah dipindah ke trash\n");
        
        int fd = open(tmp, O_WRONLY | O_CREAT, S_IRUSR);
        if(fd == -1 && errno != ENOENT) return -errno;
        printf("File created\n");
        printf("Check fd open file\n");
        char *filedata = fpath;
        strcat(filedata,"\n");
        char filemode[20]="";
        snprintf(filemode,sizeof(filemode), "%o", statbuf.st_mode);
        write(fd,filedata,strlen(filedata));
        write(fd,filemode,strlen(filemode));
        
        char perm[]= "00000";
        int permission = strtol(perm, 0, 8);
        res = chmod(newfilepath, permission);
        printf("Changing permission %s\n", newfilepath);
        if (res == -1) return -errno;

        int ec;
        char log_str[1000]="";
        snprintf(log_str,sizeof(log_str),"MOVED %s TO TRASH\n", fpath);
        
        ec = log_action(log_str);
        if (ec !=0) return ec;

        close(fd);
    }
    return 0;
}
```
Fungsi terakhir adalah ```xmp_rmdir``` yang digunakan untuk menghapus direktori, cara kerjanya sama seperti ```xmp_unlink``` akan tetapi ini berlaku untuk direktori, serta ditambahkan fungsi untuk menghapus secara rekursif file-file yang ada di dalam direktori apabila masih terdapat isi di dalamnya.
```c
// Function to delete directory
static int xmp_rmdir(const char *path) {
    char fpath[1000]="";

    if(strstr(path,dirpath) == NULL){
        snprintf(fpath, sizeof(fpath), "%s%s", dirpath, path);
    }
    else snprintf(fpath, sizeof(fpath), "%s", path);
    
    int res;
    struct stat statbuf;
    char *filename = strrchr(fpath, '/');
    char filedir[1000]="";

    strcpy(filedir,trashdata);

    printf("Check stat %s\n", fpath);
    stat(fpath, &statbuf);
    strcat(filedir,"/");
    strcat(filedir,filename);

    char tmp[1000]="";
    sprintf(tmp, "%s%s", trashdata,filename);
    printf("%s\n",tmp);

    //Jika mencoba remove trash directory
    if(strcmp(fpath,trashpath)==0) {
        int ec;
        ec = log_action("FAILED TO REMOVE TRASH DIRECTORY\n");
        if (ec !=0) return ec;
        
        return -EACCES;
    }
    //Jika path terdapat trash
    if(strstr(fpath,"trash") != NULL){
        //Jika file di dalam trash
        if(check_trash_dir(fpath) != 0) {
            chmod(fpath,0700);
            //Remove directory and its content recursively
            DIR *dir = opendir(fpath);
            if (dir == NULL) {
                return -errno; // Handle errors (e.g., ENOENT)
            }
            printf("Open dir fpath\n");
            // Iterate over directory entries (excluding "." and "..")
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                printf("Removing recursively\n");
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
                printf("subpath\n");
                // Construct full path for subdirectory/file
                char subpath[1010]="";
                snprintf(subpath, sizeof(subpath), "%s/%s", fpath, entry->d_name);
                // Use stat to determine entry type (file or directory)
                struct stat statbuff;
                printf("Statbuff subpath %s\n", subpath);
                
                if (lstat(subpath, &statbuff) == -1 && errno != ENOENT) {
                    closedir(dir);
                    return -errno; // Handle errors
                }
                
                printf("Statbuff\n");
                // Handle subdirectory recursively
                
                if (S_ISDIR(statbuff.st_mode)) {
                    printf("Recursive call subpath\n");
                    int ret = xmp_rmdir(subpath); // Recursive call
                    if (ret != 0 && errno != ENOENT) {
                        closedir(dir);
                        return ret; // Propagate error up
                    }
                } 
                else {
                    printf("File deletion\n");
                    // Handle file deletion (e.g., using unlink)
                    if (unlink(subpath) == -1 && errno != ENOENT) {
                        closedir(dir);
                        return -errno; // Handle errors
                    }
                    
                }
            }

            res = rmdir(fpath);
            if(res == -1) return -errno;
            printf("Removing trash file\n");
            res = unlink(tmp);
            if(res == -1) return -errno;
            printf("Removing trash data file\n");
            
            int ec;
            char log_str[1000]="";
            snprintf(log_str,sizeof(log_str),"PERMANENTLY REMOVED %s\n", fpath);
        
            ec = log_action(log_str);
            if (ec !=0) return ec;
            closedir(dir);
        }
        else return -1;
    }
    //Jika tidak di trash, maka pindahkan ke trash
    else {
        char newfilepath[1000]="";
        strcat(newfilepath, trashpath);
        strcat(newfilepath,filename);
        printf("file trash baru %s\n", newfilepath);
        printf("%s\n", fpath);

        res = rename(fpath, newfilepath);   
        if(res == -1 ) return -errno;
        printf("Sudah direname\n");
        int fd = open(tmp, O_WRONLY | O_CREAT, S_IRUSR);
        if(fd == -1 && errno != ENOENT) return -errno;
        printf("File trash created\n");
        char *filedata = fpath;
        strcat(filedata,"\n");
        char filemode[20]="";

        snprintf(filemode,sizeof(filemode), "%o", statbuf.st_mode);
        write(fd,filedata,strlen(filedata));
        write(fd,filemode,strlen(filemode));
        //close(fd);
        char perm[]= "00000";
        int permission = strtol(perm, 0, 8);
        res = chmod(newfilepath, permission);
        printf("Changing permission %s\n", newfilepath);
        if (res == -1) return -errno;

            int ec;
            char log_str[1000]="";
            snprintf(log_str,sizeof(log_str),"MOVED %s TO TRASH\n", fpath);
        
            ec = log_action(log_str);
            if (ec !=0) return ec;
        close(fd);
    }
    return 0;
}
```