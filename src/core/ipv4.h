#/*
 * ipv4 addresses related functions, ...
 *	struct ipv4_addr
 *	struct netmask
 *	
 *	typedef struct netmask nmask
 *	typedef struct ipv4_addr ip_addr
 *	
 *	function_name			description
 *	v4_print_bytes()		...
 *	v4_cidr_to_bytes()		...
 *	v4_is_valid_addr()		...
 *	v4_is_valid_byte()		...
 *	v4_are_valid_bytes()	...
 *	v4_bytes_cpy()			...
 *	v4_addr_cpy()			...
 *	v4_str_to_ip()			...
 *	v4_addr_cmp()			...
 *	v4_get_net_addr()		...
 **/

#ifndef IPV4_H 
#define IPV4_H

#define V4_BYTE_SIZE 4
#define V4_MAX_BYTE_VAL 255


enum { ONE = 0, TWO = 1, THR = 2, FOR = 3 };

struct netmask {
	uint8_t byte[V4_BYTE_SIZE];
	uint8_t cidr;
};

struct ipv4_addr {
	uint8_t byte[V4_BYTE_SIZE];
	struct netmask subnet_m;
};

typedef struct netmask nmask;
typedef struct ipv4_addr ip_addr;

void v4_print_bytes(uint8_t byte[V4_BYTE_SIZE]) {
	for(int i=0; i<V4_BYTE_SIZE; i++) {
			printf("%d", byte[i]);
		if(i < V4_BYTE_SIZE - 1)
			printf(".");
	}
	printf("\n");
}

const short int lookup_cidr_bytes[33] = {
//	0		1		2		3		4		5		6		7
	0,		128,	192,	224,	240,	248,	252,	254,

//	8		9		10		11		12		13		14		15
	255,	383,	447,	479,	495,	503,	507,	509,

//	16		17		18		19		20		21		22		23
	510,	638,	702,	734,	750,	758,	762,	764,

//	24		25		26		27		28		29		30		31
	765,	893,	957,	989,	1005,	1013,	1017,	1019,

//	32
	1020
};

void v4_cidr_to_bytes(const int cidr, uint8_t bytes[V4_BYTE_SIZE]) {
	int bytes_sum = lookup_cidr_bytes[cidr];
	for(int i=0; i<V4_BYTE_SIZE; i++) {
		if(bytes_sum > V4_MAX_BYTE_VAL)
			bytes[i] = V4_MAX_BYTE_VAL;
		else {
			bytes[i] = (uint8_t) bytes_sum;
			return;
		}
		bytes_sum -= V4_MAX_BYTE_VAL;
	}
}

// TODO: fihish implementation after basic functionality
bool v4_is_valid_addr(const char *str_ia) {
	// check if `str_ia` is 4 fields separated by '.'
	// check if the fields are: >= 0 && < 256
	// check if it has CIDR field (/24)
	// check if the CIDR <= 32 (max CIDR value)
	return true;
}

// TODO: check for other conditions 
bool v4_is_valid_byte(uint8_t byte) {
	return (byte <= V4_MAX_BYTE_VAL);
}

bool v4_are_valid_bytes(uint8_t byte[V4_BYTE_SIZE]) {
	for(int i=0; i<V4_BYTE_SIZE; i++) {
		if(!v4_is_valid_byte(byte[i]))
			return false;
	}
	return true;
}

void v4_bytes_cpy(uint8_t dst_bytes[V4_BYTE_SIZE], uint8_t src_bytes[V4_BYTE_SIZE]) {
	for(int i=0; i<V4_BYTE_SIZE; i++)
		dst_bytes[i] = src_bytes[i];
}

// TODO: implement `v4_addr_cpy()`
void v4_addr_cpy(ip_addr dst_ia, ip_addr src_ia);

ip_addr v4_str_to_ip(const char *str_ia) {
	uint8_t byte[V4_BYTE_SIZE];
	ip_addr ia = {
		{0, 0, 0, 0}, // The IP bytes
		{
			{0, 0, 0, 0}, // subnet mask
			0 // CIDR
		}
	};
	sscanf(str_ia, "%hhu.%hhu.%hhu.%hhu", &byte[ONE], &byte[TWO], &byte[THR], &byte[FOR]);
	if(!v4_are_valid_bytes(byte))
		fprintf(stderr, "Invalid IPv4 address\n");
	else
		v4_bytes_cpy(ia.byte, byte);
	return ia;
}

ip_addr v4_get_net_addr(const uint8_t addr[V4_BYTE_SIZE], const uint8_t subnet[V4_BYTE_SIZE]) {
	ip_addr net_addr;

	for(int i=0; i<V4_BYTE_SIZE; i++)
		net_addr.byte[i] = addr[i] & subnet[i];

	return net_addr;
}

bool v4_addr_cmp(ip_addr first_ia, ip_addr second_ia) {
	for(int i=0; i<V4_BYTE_SIZE; i++) {
		if(first_ia.byte[i] != second_ia.byte[i])
			return false;
	}
	return true;
}


#endif // IPV4_H
