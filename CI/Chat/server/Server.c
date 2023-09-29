#include "Server.h"

int main(){
    
    // Try to establish connection
    server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    server_addr.sin_port = htons(port); // htons(port) for convertion
    server_addr.sin_addr.s_addr = inet_addr(ip); // 32 bits network byte order dot.decimal -> 32bits  // INADDR_ANY - any network interface

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
        // Accept client connection and let server_sock available for other connections
        client_sock = accept(server_sock, (struct sockadrr*)&client_addr,(socklen_t *)&addr_size);
        if(client_sock < 0){
                // Return Error
                perror("[-]Server failed to accept client\n");
                exit(EXIT_FAILURE);
        }
        printf("[+]Client Connected\n");

        while (1)
        {
        
            // Receive the information from the client
            bzero(buffer, BUFFER_SIZE);
            ssize_t bytes_recv = recv(client_sock, buffer, sizeof(buffer), 0);
            if (bytes_recv < 0)
            {
                perror("[-]Server failed to receive\n");
                exit(EXIT_FAILURE);
            }
            printf("Client:%s",buffer);

            // Respond to the client
            bzero(buffer, BUFFER_SIZE);
            printf("Server:");
            fgets(buffer, sizeof(buffer), stdin);

            // Send to the client
            ssize_t bytes_send = send(client_sock, buffer, sizeof(buffer), 0);
            if (bytes_send < 0)
            {
                perror("[-]Server failed to send\n");
                exit(EXIT_FAILURE);
            }

        }

        // Client Disconnected
        close(client_sock);
        printf("[+]Client disconnected\n\n");

    }

    return 0;
}   