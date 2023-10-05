#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write

#define SERVER_PORT 5502
#define IN_BUF_LEN 100


int main()
{
	int socket_desc , new_socket , c, in, out;
	struct sockaddr_in server , client;
	char in_buf[IN_BUF_LEN], *out_buf;
	
	//Create socket
	socket_desc = socket(PF_INET , SOCK_STREAM , IPPROTO_TCP);
	if (socket_desc == -1)
	{
		printf("Could not create socket...\n");
		return -1;
	}
	else
		printf("Socket successfully created...\n");
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(SERVER_PORT);
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("Bind failed...\n");
		return 1;
	}
	else
		printf("Bind done...\n");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	printf("Waiting for incoming connections at port %d...\n", SERVER_PORT);
	
	c = sizeof(struct sockaddr_in);
	if( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) < 0 )
	{
		
		printf("Accept failed...\n");
		return -1;
	}
	else
		printf("Connection accepted: Client: %s, Port: %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			
	
	bzero(in_buf, IN_BUF_LEN);
	
	// Waiting data from the client
	
	in = recv(new_socket, in_buf , IN_BUF_LEN, 0);
	if( in < 0)
	{
		printf("Recv failed..\n");
		return -1;
		
	}
	else
		printf("Received data (%d bytes): %s\n", in, in_buf);
	
	//Send a reply to the client
	
	// Convert to uppercase
	out_buf = strupr(in_buf);
	out = send(new_socket , out_buf , strlen(out_buf) , 0);
	
	if( out < 0)
	{
		printf("Send failed..\n");
		return -1;
	}
	else
		printf("Sent data (%d bytes): %s\n", out, out_buf);
	
	close(socket_desc);
	
	return 0;
}