#include "core.h"

typedef struct {
	uint8_t oct[4];
	uint8_t cidr;
} nmask;

typedef struct {
	uint8_t oct[4];
	nmask mask;
} addr_ip;

void print_help(void) {
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

void perr(const char* err) {
	fprintf(stderr, "%s%s\n%s", ANSI_RED, err, ANSI_RES);
}

void log_msg(char* msg) {
	printf("%s\n", msg);
}

char* utob(unsigned int dec) {
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
	if(fst_oct > M_OCT || sec_oct > M_OCT || trd_oct > M_OCT || fth_oct > M_OCT) // make `isvalid_ip()` later
		perr("invalid ip address");
	else if(nmask > M_MASK)
		perr("invalid subnet mask");
	printf("%s\n%s.%s.%s.%s\n", dec_addr, utob(fst_oct), utob(sec_oct), utob(trd_oct), utob(fth_oct));
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

int is_net(addr_ip ia) {
    // Perform bitwise AND operation between the address and its mask
    nmask result;
    result.oct[0] = ia.oct[0] & ia.mask.oct[0];
    result.oct[1] = ia.oct[1] & ia.mask.oct[1];
    result.oct[2] = ia.oct[2] & ia.mask.oct[2];
    result.oct[3] = ia.oct[3] & ia.mask.oct[3];

    // Check if the result is equal to the address itself
    return CMP_OCT(ia, result); // return 0 if it's an interface, 1 if it's a network
}

void print_ip(addr_ip ia) {
	printf("%u.%u.%u.%u", ia.oct[0], ia.oct[1], ia.oct[2], ia.oct[3]);
}

addr_ip to_addr_ip(char* str) {
	addr_ip ip;
	sscanf(str, "%hhu.%hhu.%hhu.%hhu/%hhu", ip.oct[0], ip.oct[1], ip.oct[2], ip.oct[3], ip.mask.cidr);
	return ip;
}



















