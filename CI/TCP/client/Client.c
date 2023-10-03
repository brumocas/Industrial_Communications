#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){

    char *ip = "127.0.0.1";
    int port = 502;

    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    // Try to establish connection
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        // Report Error
        perror("[-]Server not available\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server\n");

    // Clear buffer to send data
    bzero(buffer, 1024);
    strcpy(buffer, "Hello World");

    // Send to the server
    ssize_t bytes_send =  send(sock, buffer, strlen(buffer), 0);
    if (bytes_send < 0)
    {
        perror("[-]Client failled send\n");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from the server
    bzero(buffer, 1024);
    ssize_t bytes_rec = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_rec < 0)
    {
        perror("[-]Client failled recv\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // Close connection
    close(sock);
    printf("Disconnected from the server\n");

    return 0;

}