#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int send_modbus_request(char* server_addr, unsigned int port, uint8_t* APDU, uint16_t APDUlen, uint8_t* APDU_r);

