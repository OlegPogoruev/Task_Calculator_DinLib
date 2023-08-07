#цель: зависимость
#[tab] команда

DIN_LIB_WAY = PlaginLib
DIN_LIB_NAME_1 = func_sum
DIN_LIB_NAME_2 = func_subtraction
DIN_LIB_NAME_3 = func_multiplication
DIN_LIB_NAME_4 = func_division

BIN = plug_program
SOURCES = main.c
HEADERS = main.h
CC := gcc
#MAKRO_KEY = LD_LIBRARY_PATH=$PWD

all:
#	$(CC) -fPIC PlaginLib/$(DIN_LIB_NAME).c -c PlaginLib/$(DIN_LIB_NAME).o
	$(CC) -fPIC -c $(DIN_LIB_WAY)/$(DIN_LIB_NAME_1).c -o $(DIN_LIB_WAY)/$(DIN_LIB_NAME_1).o
	$(CC) -shared -o $(DIN_LIB_WAY)/lib$(DIN_LIB_NAME_1).so $(DIN_LIB_WAY)/$(DIN_LIB_NAME_1).o
#
	$(CC) -fPIC -c $(DIN_LIB_WAY)/$(DIN_LIB_NAME_2).c -o $(DIN_LIB_WAY)/$(DIN_LIB_NAME_2).o
	$(CC) -shared -o $(DIN_LIB_WAY)/lib$(DIN_LIB_NAME_2).so $(DIN_LIB_WAY)/$(DIN_LIB_NAME_2).o
#
	$(CC) -fPIC -c $(DIN_LIB_WAY)/$(DIN_LIB_NAME_3).c -o $(DIN_LIB_WAY)/$(DIN_LIB_NAME_3).o
	$(CC) -shared -o $(DIN_LIB_WAY)/lib$(DIN_LIB_NAME_3).so $(DIN_LIB_WAY)/$(DIN_LIB_NAME_3).o
#
	$(CC) -fPIC -c $(DIN_LIB_WAY)/$(DIN_LIB_NAME_4).c -o $(DIN_LIB_WAY)/$(DIN_LIB_NAME_4).o
	$(CC) -shared -o $(DIN_LIB_WAY)/lib$(DIN_LIB_NAME_4).so $(DIN_LIB_WAY)/$(DIN_LIB_NAME_4).o
#
	$(CC) $(SOURCES) -ldl -o $(BIN).out
$(BIN): $(HEADERS)

run: all
	LD_LIBRARY_PATH=$$PWD/$(DIN_LIB_WAY) ./$(BIN).out

#clean:
#	rm -rf $(BIN) *.o $(BIN).out



















