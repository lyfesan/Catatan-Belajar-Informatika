#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080

typedef struct {
    char username[100];
    char containerName[100];
    char imageName[100];
    char command[200];
    char volume[200];
} ServiceRequest;

void runDockerCompose() {
    // Menjalankan Docker Compose
    int pid = fork();
    if (pid == 0) {
        execlp("docker-compose", "docker-compose", "-f", "docker-compose.yml", "up", "--force-recreate", NULL);
        perror("Gagal menjalankan docker-compose");
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Tunggu docker-compose selesai
    printf("Docker Compose telah dijalankan.\n");
}

int main() {
    int server_fd, client_sock, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int max_clients, i;
    ServiceRequest services[5];  // Asumsi maksimal 5 klien
    char buffer[1024] = {0};
    FILE *fp;

    printf("Masukkan jumlah klien yang akan dilayani (1-5): ");
    scanf("%d", &max_clients);

    printf("Masukkan nama pengguna yang valid:\n");
    char* valid_usernames[max_clients];
    for (i = 0; i < max_clients; i++) {
        valid_usernames[i] = malloc(100 * sizeof(char));
        printf("Username %d: ", i + 1);
        scanf("%s", valid_usernames[i]);
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Gagal membuat soket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Gagal melakukan bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, max_clients) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        for (i = 0; i < max_clients; i++) {
            if ((client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            int found = 0;
            read(client_sock, buffer, 1024);  // Baca nama pengguna dari klien
            for (int j = 0; j < max_clients; j++) {
                if (strcmp(buffer, valid_usernames[j]) == 0) {
                    found = 1;
                    read(client_sock, &services[i], sizeof(ServiceRequest));
                    printf("Permintaan layanan diterima dari %s\n", services[i].username);
                    break;
                }
            }
            if (!found) {
                send(client_sock, "INVALID", strlen("INVALID"), 0);
                i--;  // Kurangi hitungan untuk mencoba nama pengguna yang valid lagi
            }
        }

        fp = fopen("docker-compose.yml", "w");
        fprintf(fp, "version: '3'\nservices:\n");
        for (i = 0; i < max_clients; i++) {
            fprintf(fp, "  %s:\n", services[i].containerName);
            fprintf(fp, "    image: %s\n", services[i].imageName);
            fprintf(fp, "    command: %s\n", services[i].command);
            fprintf(fp, "    volumes:\n");
            fprintf(fp, "      - %s\n", services[i].volume);
        }
        fclose(fp);
        runDockerCompose();
    }

    for (i = 0; i < max_clients; i++) {
        free(valid_usernames[i]);
    }

    return 0;
}
