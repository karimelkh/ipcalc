CC				=gcc
CFLAGS 			=-Wall -Werror -Wpedantic -Wextra -Wconversion
CFLAGS_DEBUG	=-g -O0
CFLAGS_RELEASE	=-O3

TARGET			=ipcalc
MAIN			=main.c
SRC				=./src
BLD				=./build

INIT			=./scripts/init.sh
NOC				=./scripts/noc.sh
NOC_DIR			=./noc_src

all:
	$(CC) $(CFLAGS) $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)

debug:
	$(CC) $(CFLAGS_DEBUG) $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)

release:
	$(CC) $(CFLAGS_RELEASE) $(SRC)/$(MAIN) -o $(BLD)/$(TARGET)

init:
	$(INIT)

nocmts:
	$(NOC)

clean:
	rm -rf $(BLD)/* $(NOC_DIR)
