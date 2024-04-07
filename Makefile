CC=gcc
CFLAGS=-Wall
TARGET=ipcalc
CORE=src/core.c
MAIN=src/main.c

all: core.o main.o
	$(CC) core.o main.o -o $(TARGET)

main.o:
	$(CC) -c $(MAIN) -o main.o

core.o:
	$(CC) -c $(CORE) -o core.o

clean:
	rm ./build/*
