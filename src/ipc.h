#ifndef IPC_H
#define IPC_H

#include "common/common.h"
#include "common/log.h"

#include "core/ipv4.h"
#include "core/ipv6.h"


/*
 * @brief print the binary version of a decimal IP address
 * @param ia ip address 
 * @param iv ip vesrion or family
 * @see
 * @return void
 */
void ipc_bin(const char *ia, int iv) {
	struct in_addr ipv4;
	struct in6_addr ipv6;

	if (iv == 4) {
		if (inet_pton(AF_INET, ia, &ipv4) != 1) {
			fprintf(stderr, "Invalid IPv4 address: %s\n", ia);
			exit(EXIT_FAILURE);
		}
		// printf("Binary version of %s (IPv4): ", ia);
		for (int i = 0; i < 4; i++) {
			printf("%08b ", (int)(ipv4.s_addr >> (i * 8)) & 0xFF);
		}
		printf("\n");
	} else if (iv == 6) {
		if (inet_pton(AF_INET6, ia, &ipv6) != 1) {
			fprintf(stderr, "Invalid IPv6 address: %s\n", ia);
			exit(EXIT_FAILURE);
		}
		// printf("Binary version of %s (IPv6): ", ia);
		for (int i = 0; i < 16; i++) {
			printf("%08b ", (int)(ipv6.s6_addr[i]) & 0xFF);
		}
		printf("\n");
	} else {
		fprintf(stderr, "Invalid IP version: %d\n", iv);
		exit(EXIT_FAILURE);
	}
}


/* -- FOR IPv4 ONLY (FOR NOW) --
 * @brief check if the ip address is for a network
 * @param
 * @param
 * @see
 * @return void
 * */
// TODO: manage to get the subnet mask that will be used to get the network address
// TODO: be more descriptive in the last printf
void ipc_isnet(const char *str_ia) {
	// check if `str_ia` is valid ipv4 address
	// if (!v4_is_valid_addr(str_ia))
		// print ERROR
	// convert string `str_ia` to struct `ip_addr ia`
	ip_addr ia = v4_str_to_ip(str_ia);
	// get `nia`, the network address of `ia`
	ip_addr nia = v4_get_net_addr(ia.byte, ia.subnet_m.byte);
	// compare between `ia` and `nia`
	// print results
	printf("%s\n", v4_addr_cmp(ia, nia) ? "Yes" : "No");
}

#endif // IPC_H
