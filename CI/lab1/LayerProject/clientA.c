/* Library for close */
#include <unistd.h>

#include "ModbusAP.h"

// 1 byte = 8 bits

#define IP "127.0.0.1"
#define PORT 502


// Debug instructions
#define DEBUG

int main(){
    
    // Buffer to store the read registers
    // Registers have 16 bits each = 2 bytes
    int16_t A[4]; 
    int16_t B[1]; 
    int16_t C[1];
    
    int check_error;
    int16_t soma[1] = {0x41};

    check_error = write_multiple_regs(IP, PORT, 121, 1, &soma);
    if (check_error < 0)
    {   
        #ifdef DEBUG
        printf("Error: write_multiple_regs (%d)\n", check_error);
        #endif
    }
    printf("result = %d\n",check_error);

    
    check_error = read_h_regs(IP, PORT, 122, 4, A);
    if (check_error < 0)
    {   
        #ifdef DEBUG
        printf("Error: Reading_h_regs (%d)\n", check_error);
        #endif
    }
    printf("result = %d\n",check_error);

    check_error = read_h_regs(IP, PORT, 126, 1, B);
    if (check_error < 0)
    {   
        #ifdef DEBUG
        printf("Error: Reading_h_regs (%d)\n", check_error);
        #endif
    }
    printf("result = %d\n",check_error);

    if (B[0] == 0)
    {
        C[0] = 9999;
    } else{
        C[0] = A[0] + A[3];
    }

    check_error = write_multiple_regs(IP, PORT, 127, 1, &C);
    if (check_error < 0)
    {   
        #ifdef DEBUG
        printf("Error: write_multiple_regs (%d)\n", check_error);
        #endif
    }
    printf("result = %d\n",check_error);

    check_error = write_multiple_regs("10.227.113.1", PORT, 127, 1, &C);
    if (check_error < 0)
    {   
        #ifdef DEBUG
        printf("Error: write_multiple_regs (%d)\n", check_error);
        #endif
    }
    printf("result = %d\n",check_error);

    #ifdef DEBUG
    printf("Read Registers: \n");
    for (int i = 0; i < 4; i++)
    printf("A[%d] = %d\n",i , A[i]);
    printf("B[0] = %d\n", B[0]);
    printf("C = %ls\n", C);
    #endif
    
    return 0;
}