/*
 * logs-related functions, ...
 * log_help()
 * log_msg()
 * log_err()
 * log_err_info()
 * */

#ifndef LOG_H
#define LOG_H

/* help message info */
#define CMD_NAME	"ipcalc"
#define CMD_DESC	"perform some calculations on IP addresses"
#define CMD_USAGE	"usage:\n\
\t-b, --bin\tconvert decimal to binary\n\
\t-t, --type\tnetwork type: INTERFACE or NETWORK\n\
\t-n, --net\tget network address\n\
\t-h, --help\tprint this help\n\
\t--isnet\tcheck if it is a network address\n\
\t--isint\tcheck if it is an interface address"
#define CMD_VER		"v0.0"
#define CMD_AUTH	"karimelk"
#define	CMD_REPO	"https://github.com/karimelkh/ipcalc"

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

// TODO: make `log_err()` and `log_err_info()` to accept formatting, if possible
void log_err(int wc, ...) {
	va_list ap;
	va_start(ap, wc);
	fprintf(stderr, ANSI_RED);
	for(int i=0; i<wc; i++)
		fprintf(stderr, "%s ", va_arg(ap, char*));
	fprintf(stderr, ANSI_RES);
	va_end(ap);
	fprintf(stderr, "\n");
}

// TODO: find a way to make info related to where call is (using a macro, ...)
void log_err_info(int wc, ...) {
	va_list ap;
	va_start(ap, wc);
	// fprintf(stderr, "%s:%d\t\t%s\t\t", __FILE__, __LINE__, __func__);
	fprintf(stderr, ANSI_RED);
	for(int i=0; i<wc; i++)
		fprintf(stderr, "%s ", va_arg(ap, char*));
	fprintf(stderr, ANSI_RES);
	va_end(ap);
	fprintf(stderr, "\n");
}

// TO MOVE TO ipv4.h
//void print_ip(ipv4_addr ia) {
//	printf("%u.%u.%u.%u", ia.byte[ONE], ia.byte[TWO], ia.byte[TRE], ia.byte[FOR]);
//}

#endif // LOG_H
