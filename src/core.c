#include "core.h"

// print help
void print_help(void)
{
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

// Print ERRor
void
perr(const char* err)
{
	// fprintf(stderr, ANSI_CLR_RED "%s\n" ANSI_CLR_RES, err);
	fprintf(stderr, "%s %s\n %s", ANSI_RED, err, ANSI_RES);
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
	if(fst_oct > M_OCT || sec_oct > M_OCT || trd_oct > M_OCT || fth_oct > M_OCT) // make `isvalid_ip()` later
		perr("invalid ip address");
	else if(nmask > M_MASK)
		perr("invalid subnet mask");
	printf("%s\n%s.%s.%s.%s\n", dec_addr, dtob(fst_oct), dtob(sec_oct), dtob(trd_oct), dtob(fth_oct));
}
