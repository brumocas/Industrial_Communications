#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){

    char *ip = "127.0.0.1";
    int port = 5566;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;
    
    // Try to establish connection
    server_sock = socket(AF_INET, SOCK_STREAM, SOL_IP);
    if (server_sock < 0)
    {   
        // Report Error
        perror("[-]Socket Error\n");
        exit(EXIT_FAILURE);
    }

    // Conection established correctly
    printf("[+]TCP Server socket Created\n");
    
    // Clear memmory for server_addr structure
    memset(&server_addr, 0, sizeof(server_addr));
    // Add server_addr information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // The bind function is used to associate a socket with a specific network address, such as an IP address and port number.
    n = bind(server_sock, (struct sockadrr*)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        // Report Error
        perror("[-]Bind Error\n");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("[+]Bind to the port number: %d\n", port);

    // Listen for clients requests
    listen(server_sock, 5); // Maximum number of pending connections
    printf("Listening...\n");

    while (1)
    {
        client_sock = accept(server_sock, (struct sockadrr*)&client_addr, &addr_size);
        printf("[+]Client Connected\n");

        // Receive the information
        bzero(buffer, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        printf("Client: %s\n",buffer);

        bzero(buffer, 1024);
        strcpy(buffer, "Hi, this is the server talking\n");
        printf("Client: %s\n",buffer);
        send(server_sock, buffer, sizeof(buffer), 0);
        
        close(client_sock);
        printf("[+]Client disconected\n\n");

    }
    

    return 0;
}   