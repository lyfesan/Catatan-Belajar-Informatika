#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    char username[100];
    char containerName[100];
    char imageName[100];
    char command[200];
    char volume[200];
} ServiceRequest;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    ServiceRequest request;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Kesalahan pembuatan socket \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nAlamat tidak valid/Alamat tidak didukung \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nKoneksi Gagal \n");
        return -1;
    }

    printf("Masukkan nama pengguna (ketik 'exit' untuk keluar): ");
    scanf("%s", request.username);
    if (strcmp(request.username, "exit") == 0 || strcmp(request.username, "quit") == 0) {
        printf("Keluar...\n");
        close(sock);
        return 0;
    }
    send(sock, request.username, strlen(request.username), 0);

    while (1) {
        printf("Masukkan nama container: ");
        scanf("%s", request.containerName);
        printf("Masukkan nama gambar: ");
        scanf("%s", request.imageName);
        printf("Masukkan perintah awal: ");
        scanf(" %[^\n]%*c", request.command);
        printf("Masukkan volume: ");
        scanf("%s", request.volume);

        send(sock, &request, sizeof(ServiceRequest), 0);

        printf("Permintaan layanan telah dikirim.\n");

        printf("Masukkan layanan lain atau ketik 'exit' untuk keluar: ");
        scanf("%s", request.username);
        if (strcmp(request.username, "exit") == 0 || strcmp(request.username, "quit") == 0) {
            printf("Keluar...\n");
            break;
        }
    }

    close(sock);
    return 0;
}
