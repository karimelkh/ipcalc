#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define CMD_NAME "ipcalc"
#define CMD_DESC "convert between decimal and binary versions of IPv4 and IPv6 addresses"
#define CMD_USAGE "usage:\n\t-b, --bin=DEC	convert decimal to binary\n\t-d, --dec=BIN	convert binary to decimal"
#define CMD_VER "v0.0"
#define CMD_AUTH "karimelk"
#define CMD_REPO "https://github.com/karimelkh/ip2bin)"

void print_help()
{
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

/*
 * you can use `inet_pton` from `arpa/inet.h` to convert from IP to binary
 * check manual: `man 3 inet_pton`
 * alt: `man 3 ares_inet_pton`
 * */


/*
char* to_bin(char* dec_addr)
{
	char* bin_addr = "BIN_ADDR";
	unsigned int fst_oct, sec_oct, trd_oct, fth_oct, nmask;
	sscanf(dec_addr, "%u.%u.%u.%u/%u", &fst_oct, &sec_oct, &trd_oct, &fth_oct, &nmask);
	printf("%u\n%u\n%u\n%u\n%u\n", fst_oct, sec_oct, trd_oct, fth_oct, nmask);
	return bin_addr;
}
*/

/*
 * you can use `inet_nton` from `arpa/inet.h` to convert from binary to IP
 * check manual: `man 3 inet_nton`
 * */
/*
char* to_ipv4(char* arg) { return arg; }

char* to_ipv6(char* arg) { return arg; }
*/
