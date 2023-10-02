#include "ModbusTCP.h"


int send_modbus_request(char* server_addr, unsigned int port, uint8_t* APDU, uint16_t APDUlen, uint8_t* APDU_r){
    
    int sock, i;
    struct sockaddr_in server;

    // Create socket:
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("[TCP] Error: creating socket\n");
        return -1;
    }

    printf("[TCP] Socket created\n");
    printf("%d\n",port);
    printf("%s\n",server_addr);

    memset(&server, 0, sizeof(server));
    
    // Set port and IP of the server
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(server_addr);

    // Try connecting with the server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {   
        printf("[TCP] Error: connecting to server\n");
        return -1;
    }
    
    printf("[TCP] Successful connection to the server\n");

    // Build MBAPDU header
    
    

    return 0;
}