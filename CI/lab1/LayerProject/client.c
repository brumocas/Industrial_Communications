/* Library for close */
#include <unistd.h>

#include "ModbusAP.h"

// 1 byte = 8 bits

#define IP "127.0.0.1"
#define PORT 502
#define NUMBER_OF_READS 3
#define NUMBER_OF_WRITES 3

// Debug instructions
#define DEBUG

int main(){
    
    // Buffer to store the read registers
    // Registers have 16 bits each = 2 bytes
    int16_t buffer_regs[NUMBER_OF_READS]; 
    int check_error;

    uint16_t soma[3] = {10 ,20, 30};

    check_error = write_multiple_regs(IP, PORT, 0, NUMBER_OF_WRITES, &soma);
    if (check_error < 0)
    {
        printf("Error: write_multiple_regs (%d)\n", check_error);
        exit(EXIT_FAILURE);
    }

    check_error = read_h_regs(IP, PORT, 0, NUMBER_OF_READS, buffer_regs);
    if (check_error < 0)
    {
        printf("Error: Reading_h_regs (%d)\n", check_error);
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    printf("Read Registers: ");
    for (int i = 0; i < NUMBER_OF_READS; i++)
    printf("%d ", buffer_regs[i]);
    printf("\n");    
    #endif

    return 0;
}