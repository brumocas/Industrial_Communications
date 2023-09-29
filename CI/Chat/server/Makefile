
default: all

clean:
	rm *.exe
	
all: Server

Server: Server.c
	gcc -o Server Server.c Server.h -llibmodbus -Wall -L /usr/local/lib

