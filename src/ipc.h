#ifndef IPC_H
#define IPC_H

#include "common/common.h"
#include "common/log.h"

#include "core/ipv4.h"
#include "core/ipv6.h"


/*
 * @brief print the binary version of a decimal IP address
 * @param 
 * @param
 * @see
 * @return void
 */
void ipc_bin(const char *ip_addr, int ip_ver) {
	struct in_addr ipv4;
	struct in6_addr ipv6;

	if (ip_ver == 4) {
		if (inet_pton(AF_INET, ip_addr, &ipv4) != 1) {
			fprintf(stderr, "Invalid IPv4 address: %s\n", ip_addr);
			exit(EXIT_FAILURE);
		}
		printf("Binary version of %s (IPv4): ", ip_addr);
		for (int i = 0; i < 4; i++) {
			printf("%08b ", (int)(ipv4.s_addr >> (i * 8)) & 0xFF);
		}
		printf("\n");
	} else if (ip_ver == 6) {
		if (inet_pton(AF_INET6, ip_addr, &ipv6) != 1) {
			fprintf(stderr, "Invalid IPv6 address: %s\n", ip_addr);
			exit(EXIT_FAILURE);
		}
		printf("Binary version of %s (IPv6): ", ip_addr);
		for (int i = 0; i < 16; i++) {
			printf("%08b ", (int)(ipv6.s6_addr[i]) & 0xFF);
		}
		printf("\n");
	} else {
		fprintf(stderr, "Invalid IP version: %d\n", ip_ver);
		exit(EXIT_FAILURE);
	}
}

#endif // IPC_H
