#ifndef LOG_H
#define LOG_H

#define CMD_NAME	"ipcalc"
#define CMD_DESC	"perform some calculations on IP addresses"
#define CMD_USAGE	"usage:\n\t-b, --bin=DEC\tconvert decimal to binary\n\t-d, --dec=BIN\tconvert binary to decimal\n\t-h, --help\tprint this help"
#define CMD_VER		"v0.0"
#define CMD_AUTH	"karimelk"
#define	CMD_REPO	"https://github.com/karimelkh/ipcalc)"

#define MAX_BYTE_VAL 255
#define MAX_MASK_VAL 32

#define ANSI_RED "\x1b[31m"
#define ANSI_RES "\x1b[0m"


void print_help(void) {
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

void log_err(const char* err) {
	fprintf(stderr, "%s%s\n%s", ANSI_RED, err, ANSI_RES);
}

void log_msg(char* msg) {
	printf("%s\n", msg);
}

// TO MOVE TO ipv4.h
void print_ip(ipv4_addr ia) {
	printf("%u.%u.%u.%u", ia.byte[ONE], ia.byte[TWO], ia.byte[TRE], ia.byte[FOR]);
}

#endif // LOG_H
