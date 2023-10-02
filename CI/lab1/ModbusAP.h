#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ModbusTCP.h"



int read_h_regs(char* server_add, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer);



int write_multiple_regs(char* server_add, unsigned int port, uint16_t st_r, uint16_t n_r, int16_t* buffer);