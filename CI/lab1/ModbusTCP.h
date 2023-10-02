#include <stdio.h>
#include <stdint.h>


int send_modbus_request(char* server_add, unsigned int port, uint8_t* APDU, uint16_t APDUlen, uint8_t* APDU_r);

