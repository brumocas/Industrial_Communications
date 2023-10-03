
default: all

clean:
	rm *.exe
	
all: client

client : client.c
	gcc -o client  client.c ModbusAP.c ModbusAP.h ModbusTCP.c ModbusTCP.h  -llibmodbus -Wall -L /usr/local/lib

