
default: all

clean:
	rm *.exe
	
all: Server

Server: Server.c
	gcc -o Server Server.c  -llibmodbus -Wall -L /usr/local/lib

