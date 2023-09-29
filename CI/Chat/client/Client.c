#include "Client.h"


int main(){

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
    addr.sin_port = htons(port); // TODO: Use funtions to convert high byte to low byte
    addr.sin_addr.s_addr = inet_addr(ip); // Set bit sequence //Set TCP network byte order

    // Connect to the server
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        // Report Error
        perror("[-]Server not available\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server\n");

    while (1)
    {
        // Clear buffer to send data
        bzero(buffer, BUFFER_SIZE);
        printf("Client:");
        fgets(buffer,sizeof(buffer),stdin);
        
        // Send to the server
        ssize_t bytes_send =  send(sock, buffer, strlen(buffer), 0);
        if (bytes_send < 0)
        {
            perror("[-]Client failed send\n");
            exit(EXIT_FAILURE);
        }
    
        // Receive response from the server
        bzero(buffer, BUFFER_SIZE);
        ssize_t bytes_rec = recv(sock, buffer, sizeof(buffer),0);
        if (bytes_rec < 0)
        {
            perror("[-]Client failed recv\n");
            exit(EXIT_FAILURE);
        }
        printf("Server:%s", buffer);

    }
    
    // Close connection
    close(sock);
    printf("Disconnected from the server\n");

    return 0;

}