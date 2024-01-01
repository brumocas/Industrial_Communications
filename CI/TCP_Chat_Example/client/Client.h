#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define IP "192.168.1.110"
#define BUFFER_SIZE 1024


char *ip = IP;
int port = PORT;

int sock;
struct sockaddr_in addr;
socklen_t addr_size;
char buffer[BUFFER_SIZE];
int n;