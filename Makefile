CC=gcc
# CC=clang
CFLAGS=-Wall
TARGET=ipcalc
MAIN=main.c
SRC=src
BLD=build

all:
	$(CC) $(CFALGS) $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)

debug:
	$(CC) -g $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)


clean:
	rm ./build/*
