#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_NAME "ipcalc"
#define CMD_DESC "convert between decimal and binary versions of IPv4 and IPv6 addresses"
#define CMD_USAGE "usage:\n\t-b, --bin=DEC\tconvert decimal to binary\n\t-d, --dec=BIN\tconvert binary to decimal\n\t-h, --help\tprint this help"
#define CMD_VER "v0.0"
#define CMD_AUTH "karimelk"
#define CMD_REPO "https://github.com/karimelkh/ip2bin)"

#define M_OCT 255
#define M_MASK 32

#define ANSI_RED "\x1b[31m"
#define ANSI_RES "\x1b[0m"

#define BIN_STR_LEN 8

// print help
void print_help(void);

// Print ERRor
void perr(const char* err);

// log message to stdout
void log_msg(char* msg);

// decimal to binary string
char* dtob(unsigned int dec);

// decimal ipv4 to binary string
void to_bin(char* dec_addr);
