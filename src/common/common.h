#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>	// printf, sscanf,
#include <string.h> // strcat,
#include <stdlib.h> // exit,
#include <getopt.h>	// getopt,
#include <stdint.h>	// uint8_t,
#include <arpa/inet.h> // inet_pton
#include <netinet/in.h> // struct in_addr, struct in6_addr

int opterr = 0; // disable `getopt` default error messages

#endif
