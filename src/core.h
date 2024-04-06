#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
// #include <unistd.h>
#include <stdint.h>

#define CMD_NAME "ipcalc"
// #define CMD_DESC "convert between decimal and binary versions of IPv4 and IPv6 addresses"
#define CMD_DESC "perform some calculations on IP addresses"
#define CMD_USAGE "usage:\n\t-b, --bin=DEC\tconvert decimal to binary\n\t-d, --dec=BIN\tconvert binary to decimal\n\t-h, --help\tprint this help"
#define CMD_VER "v0.0"
#define CMD_AUTH "karimelk"
#define CMD_REPO "https://github.com/karimelkh/ipcalc)"

#define M_OCT 255
#define M_MASK 32

#define ANSI_RED "\x1b[31m"
#define ANSI_RES "\x1b[0m"

#define BIN_STR_LEN 8

#define CMP_OCT(x, y) ((x.oct[0] == y.oct[0]) && (x.oct[1] == y.oct[1]) && (x.oct[2] == y.oct[2]) && (x.oct[3] == y.oct[3]))

// print help
void print_help(void);

// Print ERRor
void perr(const char* err);

// log message to stdout
void log_msg(char* msg);

// decimal to binary string
char* utob(unsigned int dec);

// decimal ipv4 to binary string
void get_bin(char* dec_addr);

//
// int mask_cmp(nmask fm, nmask sm);

//
// int addr_cmp(addr_ip f_addr, addr_ip s_addr);
