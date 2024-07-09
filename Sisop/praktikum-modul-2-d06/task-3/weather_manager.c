#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // download zip
    pid_t download_id;
    int download_status;

    download_id = fork();
    char url_link[] = "https://drive.usercontent.google.com/u/0/uc?id=1U1-9v9pJeX5MoofwoBHCcD9nA7YWy_np&export=download";

    if (download_id < 0) {
        exit(EXIT_FAILURE);
    }

    if (download_id == 0) {
        char *argv[] = {"wget", url_link, "-qO", "weathers.zip", NULL};
        execv("/bin/wget", argv);
    }

    wait(&download_status);

    // create weather folder
    pid_t mkdir_id;
    int mkdir_status;

    mkdir_id = fork();

    if (mkdir_id < 0) {
        exit(EXIT_FAILURE);
    }

    if (mkdir_id == 0) {
        char *argv[] = {"mkdir", "weather", NULL};
        execv("/bin/mkdir", argv);
    }

    wait(&mkdir_status);

    // extract zip
    pid_t zip_player;
    int extract_status;

    zip_player = fork();

    if (zip_player < 0) {
        exit(EXIT_FAILURE);
    }

    if (zip_player == 0) {
        char *argv[] = {"unzip", "weathers.zip", "-d", "weather", NULL};
        execv("/bin/unzip", argv);
    }

    wait(&extract_status);

    // Menghapus weathers.zip
    pid_t delzip;
    int delzip_status;

    delzip = fork();

    if (delzip < 0) {
        exit(EXIT_FAILURE);
    }

    if (delzip == 0) {
        char *argv[] = {"rm", "-r", "weathers.zip", NULL};
        execv("/bin/rm", argv);
    }

    wait(&delzip_status);

    return 0;
}
