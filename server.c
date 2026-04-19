#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int votosA = 0;
int votosB = 0;

int server() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Servidor aguardando conexões...\n");

    while(1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        read(client_socket, buffer, 1024);
        printf("Voto recebido: %s\n", buffer);

        if(strcmp(buffer, "A") == 0) votosA++;
        else if(strcmp(buffer, "B") == 0) votosB++;

        char resposta[100];
        sprintf(resposta, "Votos -> A: %d | B: %d", votosA, votosB);

        send(client_socket, resposta, strlen(resposta), 0);

        close(client_socket);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}