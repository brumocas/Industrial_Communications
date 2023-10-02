/* Library for close */
#include <unistd.h>

#include "ModbusAP.h"

// 1 byte = 8 bits

#define IP "127.0.0.1"
#define PORT 502
#define NUMBER_OF_READS 2
#define NUMBER_OF_WRITES 1

int main(){

    // Buuffer to store the read registers
    // Registers have 16 bits each = 2 bytes
    int16_t buffer_regs[NUMBER_OF_READS]; 
    int check_error;

    // Clear buffer memmory
    memset(buffer_regs, 0, NUMBER_OF_READS * sizeof(int16_t));

    check_error = read_h_regs(IP, PORT, 0, NUMBER_OF_READS, buffer_regs);
    if (check_error < 0)
    {
        printf("Error: Reading_h_regs (%d)\n", check_error);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < NUMBER_OF_READS; i++)
    printf("%d ", buffer_regs[i]);
    printf("\n");    
    
    uint16_t soma = buffer_regs[0] + buffer_regs[1];

    check_error = write_multiple_regs(IP, PORT, 1, NUMBER_OF_WRITES, &soma);
    if (check_error < 0)
    {
        printf("Error: write_multiple_regs (%d)\n", check_error);
        exit(EXIT_FAILURE);
    }
    

    return 0;
}