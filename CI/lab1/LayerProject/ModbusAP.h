#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "ModbusTCP.h"


/*  Read Holding Registers Modbus API function
    params:
        char * server_addr  // Server IP identifier
        unsigned int port   // Server Port
        uint16_t st_r       // Starting register of where you are going to read less 1;
        uint16_t n_r        // Number of registers that you are going to read
        int16_t* buffer     // Buffer to store the values that you are going to read

    return:
        -10 // RECV TIMEOUT
        -1  // IMPLEMENTATION ERROR 
        0   // OK
        1   // ILLEGAL FUNCTION
        2   // ILLEGAL DATA ADDRESS
        3   // ILLEGAL DATA VALUE
        4   // SERVER DEVICE FAILURE
        5   // ACKNOWLEDGE
        6   // SERVER DEVICE BUSY
        7   // MEMORY PARITY ERROR
*/ 
int read_h_regs(char* server_addr, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer);


/*  Write Multiple Registers Modbus API function
    params:
        char * server_addr  // Server IP identifier
        unsigned int port   // Server Port
        uint16_t st_r       // Starting register of where you are going to write less 1;
        uint16_t n_r        // Number of registers that you are going to write
        int16_t* buffer     // Buffer with the values that you are going to write

    return:
        -10 // RECV TIMEOUT
        -1  // IMPLEMENTATION ERROR 
        0   // OK
        1   // ILLEGAL FUNCTION
        2   // ILLEGAL DATA ADDRESS
        3   // ILLEGAL DATA VALUE
        4   // SERVER DEVICE FAILURE
        5   // ACKNOWLEDGE
        6   // SERVER DEVICE BUSY
        7   // MEMORY PARITY ERROR
*/
int write_multiple_regs(char* server_addr, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer);
