/*
 * common includes and functions, ...
 *	opt_got_arg()
 *	
 *	
 *	
 *	
 *	
 *	
 * */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>	// printf, sscanf
#include <stdbool.h> // true, false
#include <string.h> // strcat, strcmp
#include <stdlib.h> // exit
#include <getopt.h>	// getopt
#include <stdint.h>	// uint8_t
#include <arpa/inet.h> // inet_pton
#include <netinet/in.h> // struct in_addr, struct in6_addr
#include <stdarg.h> // va_list, va_start, va_arg, va_end

#define ERRINFO(str) printf("%s:%d:%s: %s\n", __FILE__, __LINE__, __func__, str)

int opterr = 0; // disable `getopt` default error messages

/*
 * @brief check if argv contains an option and returns its argument
 * @param argc argument count
 * @param argv array of arguments
 * @param lookup_opt option to look for
 * @see
 * @return	argument of the lookup_opt
 *			NULL if does not have an argument
 * */
// TODO: make `optind` to point to the old index. Bc it was updated and `optarg` too.
const char* opt_got_arg(int argc, char* argv[], const char* lookup_opt) {
	int opt;
	while ((opt = getopt(argc, argv, lookup_opt)) != -1) {
		if (opt == lookup_opt[0])
			return optarg;
	}
	return NULL;
}

#endif
