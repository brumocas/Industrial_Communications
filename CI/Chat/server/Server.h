#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define IP "127.0.0.1"
#define BUFFER_SIZE 1024

char *ip = "127.0.0.1"; 
int port = 8080;

int server_sock, client_sock;
struct sockaddr_in server_addr, client_addr;
socklen_t addr_size;
char buffer[BUFFER_SIZE];
int n;