#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char voto[10];
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // COLOQUE O IP DO SERVIDOR AQUI
    inet_pton(AF_INET, "172.16.20.23", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Digite seu voto (A ou B): ");
    scanf("%s", voto);

    send(sock, voto, strlen(voto), 0);

    read(sock, buffer, 1024);
    printf("Resposta do servidor: %s\n", buffer);

    close(sock);

    return 0;
}