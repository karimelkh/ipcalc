#ifndef CONVERT_H
#define CONVERT_H

#include "utils.h" // count_ones(), 

char* uint_to_bin(unsigned int dec) {
	char* bin = (char*) malloc(sizeof(char) * BIN_STR_LEN + 1);
	int cbit = BIN_STR_LEN - 1;
	bin[BIN_STR_LEN] = '\0';
	while(cbit >= 0) {
		bin[cbit--] = (dec % 2 == 0) ? '0' : '1';
		dec = dec / 2;
	}
	return bin;
}

char* ipv4_dec_to_bin(ipv4_addr ia) {
	char* str_byte[4], subnet_mask;
	char* str_ia = (char*) malloc(sizeof(char) * IP4_STR_LEN);
	// transform the `ia` fields to binary strings
	str_byte[ONE] = uint_to_bin(ia.byte[ONE]);
	str_byte[TWO] = uint_to_bin(ia.byte[TWO]);
	str_byte[TRE] = uint_to_bin(ia.byte[TRE]);
	str_byte[FOR] = uint_to_bin(ia.byte[FOR]);
	// concatenate binary strings in one string
	strcat(str_ia, str_byte[ONE]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[TWO]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[TRE]);
	strcat(str_ia, ".");
	strcat(str_ia, str_byte[FOR]);
	printf("ipv4_dec_to_bin: %s\n", str_ia);
	return str_ia;
}

ipv4_addr to_addr_ip(char* str) {
	ipv4_addr ia;
	sscanf(str, "%hhu.%hhu.%hhu.%hhu/%hhu", &ia.byte[ONE], &ia.byte[TWO], &ia.byte[TRE], &ia.byte[FOR], &ia.mask.cidr);
	return ia;
}

#endif // CONVERT_H
