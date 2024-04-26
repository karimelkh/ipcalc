/*
 * logs-related functions, ...
 * log_help()
 * log_msg()
 * log_err
 *
 * */
#ifndef LOG_H
#define LOG_H

/* help message info */
#define CMD_NAME	"ipcalc"
#define CMD_DESC	"perform some calculations on IP addresses"
#define CMD_USAGE	"usage:\n\t-b, --bin=VER\tconvert decimal to binary\n\t\
--isnet=ADDR\tcheck if it is a network address\n\t--isint=ADDR\tcheck if it is\
an interface address\n\t-h, --help\tprint this help"
#define CMD_VER		"v0.0"
#define CMD_AUTH	"karimelk"
#define	CMD_REPO	"https://github.com/karimelkh/ipcalc)"

// TO MOVE TO ipv4.h
#define MAX_BYTE_VAL 255
#define MAX_MASK_VAL 32

#define ANSI_RED "\x1b[31m"
#define ANSI_RES "\x1b[0m"


void log_help(void) {
	printf("%s - %s\n\n%s\n\n%s\n%s\n%s\n", CMD_NAME, CMD_DESC, CMD_USAGE, CMD_VER, CMD_AUTH, CMD_REPO);
}

void log_msg(char* msg) {
	printf("%s\n", msg);
}

void log_err(const char* err) {
	fprintf(stderr, "%s%s\n%s", ANSI_RED, err, ANSI_RES);
}

// TO MOVE TO ipv4.h
//void print_ip(ipv4_addr ia) {
//	printf("%u.%u.%u.%u", ia.byte[ONE], ia.byte[TWO], ia.byte[TRE], ia.byte[FOR]);
//}

#endif // LOG_H
