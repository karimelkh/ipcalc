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

#define ANSI_CLR_RED "\x1b[31m"
#define ANSI_CLR_RES "\x1b[0m"

#define BIN_STR_LEN 8

// print help
void print_help(void)
{
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

// Print ERRor
void
perr(const char* err)
{
	fprintf(stderr, ANSI_CLR_RED "%s\n" ANSI_CLR_RES, err);
}

// log message to stdout
void
log_msg(char* msg)
{
	printf("%s\n", msg);
}

// decimal to binary string
char*
dtob(unsigned int dec)
{
	char* bin = (char*) malloc(sizeof(char) * BIN_STR_LEN + 1);
	int cbit = BIN_STR_LEN - 1;
	bin[BIN_STR_LEN] = '\0';
	while(cbit >= 0)
	{
		bin[cbit--] = (dec % 2 == 0) ? '0' : '1';
		dec = dec / 2;
	}
	return bin;
}

// decimal ipv4 to binary string
void
to_bin(char* dec_addr)
{
	unsigned int fst_oct, sec_oct, trd_oct, fth_oct, nmask;
	sscanf(dec_addr, "%u.%u.%u.%u/%u", &fst_oct, &sec_oct, &trd_oct, &fth_oct, &nmask);
	printf("%s\n%s.%s.%s.%s\n", dec_addr, dtob(fst_oct), dtob(sec_oct), dtob(trd_oct), dtob(fth_oct));
}
