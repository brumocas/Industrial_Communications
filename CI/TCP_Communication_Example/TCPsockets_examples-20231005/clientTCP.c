#include <stdio.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 5502
#define IN_BUF_LEN 100


int main()
{
	int socket_desc, out, in;
	struct sockaddr_in server;
	char *out_buf, in_buf[IN_BUF_LEN];
	
	//Create socket
	socket_desc = socket(PF_INET , SOCK_STREAM , IPPROTO_TCP);
	if (socket_desc == -1)
	{
		printf("Socket creation failed...\n");
		return -1;
	}
	else
		printf("Socket successfully created...\n");
		
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	server.sin_port = htons(SERVER_PORT);

	//Connect to remote server
	
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("Connection with the server failed...\n"); 
		return 1;
	}
	else
		printf("Connected to the server at address (%s) port (%d)...\n", SERVER_ADDR, SERVER_PORT); 	
	
	
	//Send data to the server
	
	printf("Input data: "); 
	gets(out_buf);

	out = send(socket_desc , out_buf , strlen(out_buf) , 0);
	if( out < 0)
	{
		printf("Send failed..\n");
		return -1;
	}
	else
		printf("Sent data (%d bytes): %s\n", out, out_buf);
	
	//Receive a reply from the server
	
	bzero(in_buf, IN_BUF_LEN);
	in = recv(socket_desc, in_buf , IN_BUF_LEN, 0);
	if( in < 0)
	{
		printf("Recv failed..\n");
		return -1;
		
	}
	else
		printf("Received data (%d bytes): %s\n", in, in_buf);
	
	close(socket_desc);
	
	return 0;
}