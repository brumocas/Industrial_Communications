#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){

    char *ip = "127.0.0.1";
    int port = 5566;

    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    // Try to establish connection
    sock = socket(AF_INET, SOCK_STREAM, SOL_IP);
    if (sock < 0)
    {   
        // Report Error
        perror("[-]Socket Error\n");
        exit(EXIT_FAILURE);
    }

    // Conection established correctly
    printf("[+]TCP Server socket Created\n");
    
    // Clear memmory for server_addr structure
    memset(&addr, 0, sizeof(addr));
    // Add server_addr information
    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    printf("Connected to the server");

    bzero(buffer, 1024);
    strcpy(buffer, "Hello this is client\n");
    printf("Client: %s\n", buffer);
    send(sock, buffer, strlen(buffer), 0);

    bzero(buffer, 1024);
    recv(sock, buffer, sizeof(buffer),0);
    printf("Server: %s\n", buffer);

    close(sock);
    printf("Disconected from the server\n");

    return 0;

}