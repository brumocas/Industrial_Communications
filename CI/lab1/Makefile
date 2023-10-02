
default: all

clean:
	rm *.exe
	
all: test 

test : test.c
	gcc -o test  test.c ModbusAP.c ModbusAP.h ModbusTCP.c ModbusTCP.h  -llibmodbus -Wall -L /usr/local/lib

