#include <stdio.h>
#include <unistd.h>

#include "ModbusAP.h"

#define MAX_APDU 256
#define FC_WMR 16   // Function code for WMR
#define FC_RHR 3    // Function code for RHR
#define MAX_WR_REGS 123 // max number of registers that can be written
#define MAX_RHR_REGS 126 // max number of registers that can be read


int read_h_regs(char* server_add, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer){

    // check consistency of parameters


    // assembles APDU (MODBUS PDU)


    // Send request
    //send_modbus_request();

    // Check the response


    return  0;
}

int write_multiple_regs(char* server_add, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer){
    
    uint8_t APDU[MAX_APDU];
    int i;

    // verify if parameters are within proper ranges
    if (n_r > MAX_WR_REGS)
    {
        printf("[AP,WMR] Error: too many registers\n");
        return -1;
    }

    // build header of APDU
    APDU[0] = (uint8_t) FC_WMR;         // function code
    APDU[1] = (uint8_t) (st_r >> 8);    // high byte of start address st_r
    APDU[2] = (uint8_t) (st_r & 0xFF);  // low byte of start address st_r
    APDU[3] = (uint8_t) (n_r >> 8);     // high byte of number of regs n_r
    APDU[4] = (uint8_t) (n_r & 0xFF);   // low byte number of regs n_r
    APDU[5] = (uint8_t) 2*n_r;          // number of bytes in buffer (2B/reg)

    // bulid the payload with the values to be written in the registers
    for ( i = 0; i < n_r; i++)
    {
        // High byte
        APDU[6 + 2*i] = (uint8_t) (buffer[i] >> 8);
        // Low byte
        APDU[7 + 2*i] = (uint8_t) (buffer[i] & 0xFF);
    }
    
    // Get APDU lenght
    uint16_t APDUlen = 6 + 2*n_r;

    // Show APDU
    printf("[AP,WMR] APDU to be sent\n");
    for ( i = 0; i < APDUlen; i++) printf("%.2x ",APDU[i]);
    printf("\n");
    
    // send APDU for the server
    i = send_modbus_request(server_add, port, APDU, APDUlen, APDU);

    // Check non modbus error
    if ( i < 0 )
    {
       printf("[AP,WMR] Error from send_modbus_request\n");
       return -1;
    }

    // Check modbus error - exception
    if (APDU[0] & 0x80)
    {
        printf("[AP,WMR] Modbus exception %d\n", APDU[1]);
        return APDU[1];
    }

    //else return 0 - successful
    return 0;
     
}
