CC=gcc
CF=-Wall -Wextra -Werror -Wpedantic -Wconversion
SRC=src
BLD=build
MAIN=main.c
TARGET=ipcalc
IDIR=/usr/local/bin

all:
	$(CC) $(CF) -o $(BLD)/$(TARGET) $(SRC)/$(MAIN)

init:
	scripts/init.sh

test:
	$(CC) -o $(BLD)/$(TARGET) $(SRC)/$(MAIN)

run: test
	clear -x
	$(BLD)/$(TARGET)

clean:
	rm $(BLD)/*

install: all
	cp $(BLD)/$(TARGET) $(IDIR)

uninstall:
	rm $(IDIR)/$(TARGET)
