/*
 * ipcalc main functions
 *		ipc_bin()
 *		ipc_isnet()
 *		ipc_isint()
 **/

#ifndef IPC_H
#define IPC_H

#include "common/common.h"
#include "common/log.h"

#include "core/ipv4.h"
#include "core/ipv6.h"


// TODO: to re-implement: don't use `inet_pton`, ...
/*
 * @brief print the binary version of a decimal IP address
 * @param ia ip address 
 * @param iv ip vesrion or family
 * @return void
 */
void ipc_bin(const char *ia, int iv) {
	struct in_addr ipv4;
	struct in6_addr ipv6;

	if (iv == 4) {
		if (inet_pton(AF_INET, ia, &ipv4) != 1) {
			fprintf(stderr, "Invalid IPv4 address: %s\n", ia);
//			log_err(2, "Invalid IPv4 address: ", ia);
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < 4; i++) {
			printf("%08b ", (int)(ipv4.s_addr >> (i * 8)) & 0xFF);
		}
		printf("\n");
	} else if (iv == 6) {
		if (inet_pton(AF_INET6, ia, &ipv6) != 1) {
			fprintf(stderr, "Invalid IPv6 address: %s\n", ia);
//			log_err(2, "Invalid IPv6 address: ", ia);
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < 16; i++) {
			printf("%08b ", (int)(ipv6.s6_addr[i]) & 0xFF);
		}
		printf("\n");
	} else {
		fprintf(stderr, "Invalid IP version: %d\n", iv);
//		log_err(2, "Invalid IP version: ", iv);
		exit(EXIT_FAILURE);
	}
}


// -- FOR IPv4 ONLY (FOR NOW) --
// NOTE: str_subnet is in CIDR form for now. DEAL WITH MULTIPLE FORMS LATER
// TODO: manage to get the subnet mask that will be used to get the network address
// TODO: be more descriptive in the last printf
/*
 * @brief check if the ip address is for a network
 * @param str_ia ip address as a string
 * @param str_subnet subnet mask as a string
 * @see v4_str_to_ip
 * @see v4_cidr_to_bytes
 * @see v4_get_net_addr
 * @see v4_addr_cmp
 * @return void
 * */
void ipc_isnet(const char *str_ia, const char *str_subnet) {
	// check if `str_ia` is valid ipv4 address
	// if (!v4_is_valid_addr(str_ia))
		// print ERROR
	// convert string `str_ia` to struct `ip_addr ia`
	// and assign `str_subnet` to `ia.subnet_m.cidr`
	// and transform from CIDR to BYTES form
	ip_addr ia = v4_str_to_ip(str_ia);
	// TODO: safely from `char` to `uint9_t`
	ia.subnet_m.cidr = atoi(str_subnet);
	// printf("ipc_isnet:cidr = %d", ia.subnet_m.cidr);
	v4_cidr_to_bytes(ia.subnet_m.cidr, ia.subnet_m.byte);
	// get `nia`, the network address of `ia`
	ip_addr nia = v4_get_net_addr(ia.byte, ia.subnet_m.byte);
	// compare between `ia` and `nia`
	// print results
	printf("%s\n", v4_addr_cmp(ia, nia) ? "Yes" : "No");
}

// -- FOR IPv4 ONLY (FOR NOW) --
// NOTE: str_subnet is in CIDR form for now. DEAL WITH MULTIPLE FORMS LATER
// TODO: manage to get the subnet mask that will be used to get the network address
// TODO: be more descriptive in the last printf
/*
 * @brief check if the ip address is for an interface
 * @param str_ia ip address as a string
 * @param str_subnet subnet mask as a string
 * @see v4_str_to_ip
 * @see v4_cidr_to_bytes
 * @see v4_get_net_addr
 * @see v4_addr_cmp
 * @return void
 * */
void ipc_isint(const char *str_ia, const char *str_subnet) {
	ip_addr ia = v4_str_to_ip(str_ia);
	ia.subnet_m.cidr = atoi(str_subnet);
	v4_cidr_to_bytes(ia.subnet_m.cidr, ia.subnet_m.byte);
	ip_addr nia = v4_get_net_addr(ia.byte, ia.subnet_m.byte);
	printf("%s\n", !v4_addr_cmp(ia, nia) ? "Yes" : "No");
}

#endif // IPC_H
