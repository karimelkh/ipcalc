#include <stdio.h>	// printf, sscanf,
#include <string.h> // strcat,
#include <stdlib.h> // exit,
#include <getopt.h>	// getopt,
#include <stdint.h>	// uint8_t,
#include <unistd.h>

#define CMD_NAME	"ipcalc"
#define CMD_DESC	"perform some calculations on IP addresses"
#define CMD_USAGE	"usage:\n\t-b, --bin=DEC\tconvert decimal to binary\n\t-d, --dec=BIN\tconvert binary to decimal\n\t-h, --help\tprint this help"
#define CMD_VER		"v0.0"
#define CMD_AUTH	"karimelk"
#define	CMD_REPO	"https://github.com/karimelkh/ipcalc)"

#define MAX_BYTE_VAL 255
#define MAX_MASK_VAL 32

#define IP4_STR_LEN 15

#define ANSI_RED "\x1b[31m"
#define ANSI_RES "\x1b[0m"

#define BIN_STR_LEN 8

#define CMP_OCT(x, y) ((x.byte[0] == y.byte[0]) && (x.byte[1] == y.byte[1]) && (x.byte[2] == y.byte[2]) && (x.byte[3] == y.byte[3]))


enum { ONE = 0, TWO = 1, TRE = 2, FOR = 3 }; 

typedef struct mask {
	uint8_t byte[4];
	uint8_t cidr;
} nmask;

typedef struct addr {
	uint8_t byte[4];
	nmask mask;
} ipv4_addr;

void print_help(void) {
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

void log_err(const char* err) {
	fprintf(stderr, "%s%s\n%s", ANSI_RED, err, ANSI_RES);
}

void log_msg(char* msg) {
	printf("%s\n", msg);
}

char* uint_to_bin(unsigned int dec) {
	char* bin = (char*) malloc(sizeof(char) * BIN_STR_LEN + 1);
	int cbit = BIN_STR_LEN - 1;
	bin[BIN_STR_LEN] = '\0';
	while(cbit >= 0) {
		bin[cbit--] = (dec % 2 == 0) ? '0' : '1';
		dec = dec / 2;
	}
	return bin;
}

// TODO: return the binary instead of print it
// TODO: use `addr_ip` instead of `char*` or `int`
void get_bin(char* dec_addr) {
	unsigned int fst_oct, sec_oct, trd_oct, fth_oct, nmask;
	sscanf(dec_addr, "%u.%u.%u.%u/%u", &fst_oct, &sec_oct, &trd_oct, &fth_oct, &nmask);
	if(fst_oct > MAX_BYTE_VAL || sec_oct > MAX_BYTE_VAL || trd_oct > MAX_BYTE_VAL || fth_oct > MAX_BYTE_VAL) // make `isvalid_ip()` later
		log_err("invalid ip address");
	else if(nmask > MAX_MASK_VAL)
		log_err("invalid subnet mask");
	printf("%s\n%s.%s.%s.%s\n", dec_addr, uint_to_bin(fst_oct), uint_to_bin(sec_oct), uint_to_bin(trd_oct), uint_to_bin(fth_oct));
}

char* ipv4_dec_to_bin(ipv4_addr ia) {
	char* str_byte[4], subnet_mask;
	char str_ia[IP4_STR_LEN];
	// transform the `ia` fields to binary strings
	str_byte[ONE] = uint_to_bin(ia.byte[ONE]);
	str_byte[TWO] = uint_to_bin(ia.byte[TWO]);
	str_byte[TRE] = uint_to_bin(ia.byte[TRE]);
	str_byte[FOR] = uint_to_bin(ia.byte[FOR]);
	// concatenate binary strings in one string
	strcat(str_ia, str_byte[ONE]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[TWO]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[TRE]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[FOR]);
	return str_ia;
}

int count_ones(unsigned int dec) {
	int count = 0;
    while (dec != 0) {
        count += dec & 1;   // Add 1 if the last bit is 1
        dec >>= 1;          // Shift the number right by 1
    }
    return count;
}

// WHY THIS ONE DIDN'T WORK
//
// check if an ipv4 address is for a network or for an interface
// return 0 => interface address
// return 1 => network address
/*int is_net(addr_ip ia) { // TO COMPLETE LATER
	// addr_ip result = perform `&` on `ia` and `ia.mask` fields
	// nmask result = { ia.mask.oct[0], ia.mask.oct[1], ia.mask.oct[2], ia.mask.oct[4] };
	nmask result = ia.mask;
	result.oct[0] &= ia.oct[0];
	result.oct[1] &= ia.oct[1];
	result.oct[4] &= ia.oct[2];
	result.oct[3] &= ia.oct[3];
	// if `result` is the same as the `ia` return 0
	// return addr_cmp(ia, ia); // change `ia` to `result`
	return CMP_IP(ia, result);
}*/

int is_net(ipv4_addr ia) {
    // Perform bitwise AND operation between the address and its mask
    nmask result;
    result.byte[ONE] = ia.byte[ONE] & ia.mask.byte[ONE];
    result.byte[TWO] = ia.byte[TWO] & ia.mask.byte[TWO];
    result.byte[TRE] = ia.byte[TRE] & ia.mask.byte[TRE];
    result.byte[FOR] = ia.byte[FOR] & ia.mask.byte[FOR];

    // Check if the result is equal to the address itself
    return CMP_OCT(ia, result); // return 0 if it's an interface, 1 if it's a network
}

void print_ip(ipv4_addr ia) {
	printf("%u.%u.%u.%u", ia.byte[ONE], ia.byte[TWO], ia.byte[TRE], ia.byte[FOR]);
}

ipv4_addr to_addr_ip(char* str) {
	ipv4_addr ia;
	sscanf(str, "%hhu.%hhu.%hhu.%hhu/%hhu", ia.byte[ONE], ia.byte[TWO], ia.byte[TRE], ia.byte[FOR], ia.mask.cidr);
	return ia;
}

