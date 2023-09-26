
default: all

clean:
	rm *.exe
	
all: Client

Client: Client.c
	gcc -o Client Client.c  -llibmodbus -Wall -L /usr/local/lib

