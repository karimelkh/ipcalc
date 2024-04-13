CC=gcc
# CC=clang
CFLAGS=-Wall
TARGET=ipcalc
MAIN=main.c
SRC=src
BLD=build

all:
	$(CC) $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)

clean:
	rm ./build/*
