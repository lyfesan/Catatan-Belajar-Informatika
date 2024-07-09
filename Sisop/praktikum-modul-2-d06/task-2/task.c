#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h> // Tambahkan ini untuk deklarasi fungsi-fungsi waktu

void log_task_completion(const char *name, int task_id, int jumlah, const char *kategori, const char *resolusi) {
    time_t rawtime;
    struct tm *timeinfo;
    char time_str[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);

    FILE *recap_file = fopen("recap.txt", "a");
    if (recap_file != NULL) {
        fprintf(recap_file, "[%s]-[%s] Task %d completed, download %d %s images with %s resolution\n", time_str, name, task_id, jumlah, kategori, resolusi);
        fclose(recap_file);
    } else {
        perror("fopen");
    }
}

void extract_and_download(const char *name, int task_id, int jumlah, const char *kategori, const char *resolusi) {
    char task_folder[50];
    char task_file[50]; // Deklarasikan task_file di sini

    // Membuat nama folder task
    sprintf(task_folder, "%s/task%d", name, task_id);

    // Mengekstrak file zip
    pid_t extract_id = fork();
    if (extract_id == 0) {
        sprintf(task_file, "task/task_%d_*.txt", task_id); // Tentukan task_file di sini
        char *argv[] = {"unzip", "-q", task_file, "-d", task_folder, NULL};
        execv("/usr/bin/unzip", argv);
        perror("execv");
        exit(EXIT_FAILURE);
    }

    int extract_status;
    wait(&extract_status);

    // Mengunduh gambar sesuai petunjuk
    // Implementasikan unduhan gambar dari unsplash.com sesuai petunjuk

    // Catat log setiap kali selesai melakukan task
    log_task_completion(name, task_id, jumlah, kategori, resolusi);
}


int main(){
	pid_t download_file_id;
	int download_status;

	download_file_id = fork();

	char url_link[] = "https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0";

	if(download_file_id < 0){
		exit(EXIT_FAILURE);
	}

	if(download_file_id == 0){
		char *argv[] = {"wget","-qO","task_sisop.zip", url_link, NULL};
		execv("/bin/wget", argv);
	}

	wait(&download_status);    

    //extract zip
    pid_t extract_id;
	int extract_status;

	extract_id = fork();

	char filename[] = "task_sisop.zip";
	char direc[] = "/home/cchoirun/sisop/prak2/soal2/";

	if (extract_id < 0){
		exit(EXIT_FAILURE);
	}

    if (extract_id == 0){
		char *argv[] = {"unzip", "-q", filename, "-d", direc, NULL};
		execv("/bin/unzip", argv);
	}

	wait(&extract_status);

     if (remove(filename) == 0) {
        printf("File zip berhasil dihapus.\n");
    } else {
        perror("remove");
        exit(EXIT_FAILURE);
    }

//Make directory
pid_t make_dir;
	int makedir_status;

	make_dir = fork();

	if (make_dir < 0){
		exit(EXIT_FAILURE);
	}

    if (make_dir == 0){
		char *argv[] = {"mkdir", "task", NULL};
		execv("/bin/mkdir", argv);

	}

	wait(&makedir_status);

//Find file "task_{id}.txt

 pid_t movetask_id;
	int moveir_status;
	
	movetask_id = fork();

	if (movetask_id < 0){
		exit(EXIT_FAILURE);
	}

    if (movetask_id == 0){
		char *argv[] = {"find", ".", "-type","f","-name","task_*.txt","-exec","mv","{}","/home/cchoirun/sisop/prak2/soal2/task", ";",NULL};
		execv("/bin/find", argv);
	}

 	wait(&moveir_status);

	


    for (int i = 0; i < 10; i++) {
        // Bagi tugas antara Yuan dan Bubu
        char *yuan_name = "Yuan";
        char *bubu_name = "Bubu";
        int yuan_task = i;
        int bubu_task = 19 - i;

        // Petunjuk dari file task .txt
        int jumlah;
        char resolusi[20];
        char kategori[20];
        char task_file[50]; // Deklarasikan task_file di sini

        sprintf(task_file, "task/task_%d_*.txt", yuan_task); // Deklarasikan task_file di sini
        FILE *file = fopen(task_file, "r");
        if (file != NULL) {
            fscanf(file, "%d %s %s", &jumlah, resolusi, kategori);
            fclose(file);
        } else {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        // Proses mengerjakan task untuk Yuan dan Bubu secara bersamaan (overlapping)
        pid_t yuan_pid = fork();
        if (yuan_pid == 0) {
            extract_and_download(yuan_name, yuan_task, jumlah, kategori, resolusi);
            exit(EXIT_SUCCESS);
        }

        pid_t bubu_pid = fork();
        if (bubu_pid == 0) {
            extract_and_download(bubu_name, bubu_task, jumlah, kategori, resolusi);
            exit(EXIT_SUCCESS);
        }

        // Tunggu kedua proses selesai
        int status;
        waitpid(yuan_pid, &status, 0);
        waitpid(bubu_pid, &status, 0);
    }


    return 0;
}    
