
default: all

clean:
	rm *.exe
	
all: client

client : clientA.c
	gcc -o clientA  clientA.c ModbusAP.c ModbusAP.h ModbusTCP.c ModbusTCP.h  -llibmodbus -Wall -L /usr/local/lib

