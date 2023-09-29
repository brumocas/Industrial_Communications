#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>


void stringToUpper(char *str);

int main(){

    char *ip = "127.0.0.1";
    int port = 1025;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;
    
    // Try to establish connection
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    server_addr.sin_port = htons(port);
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

    // Listen to clients requests
    listen(server_sock, 5); // Maximum number of pending connections
    printf("Listening...\n");

    while (1)
    {   
        // Accept client connection
        client_sock = accept(server_sock, (struct sockadrr*)&client_addr, &addr_size);
        printf("[+]Client Connected\n");

        // Receive the information from the client
        bzero(buffer, 1024);
        ssize_t bytes_recv = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_recv < 0)
        {
            perror("[-]Server failled to receive\n");
            exit(EXIT_FAILURE);
        }
        printf("Client: %s\n",buffer);

        // Respond to the client
        stringToUpper(buffer);
        printf("Server: %s\n",buffer);

        // Send to the client
        ssize_t bytes_send = send(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_send < 0)
        {
            perror("[-]Server failled to send\n");
            exit(EXIT_FAILURE);
        }
        
        // Client Disconnected
        close(client_sock);
        printf("[+]Client disconnected\n\n");

    }
    return 0;
}   

void stringToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}