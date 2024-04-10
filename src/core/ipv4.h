/* IPv4 related code */

#define IP4_STR_LEN 15
#define BIN_STR_LEN 8

#define CMP_OCT(x, y) ((x.byte[0] == y.byte[0]) && (x.byte[1] == y.byte[1]) && (x.byte[2] == y.byte[2]) && (x.byte[3] == y.byte[3]))

enum { ONE = 0; TWO = 1; TRE = 2; FOR = 3 };

int is_net(ipv4_addr ia) {
    // Perform bitwise AND operation between the address and its mask
    nmask result;
    result.byte[ONE] = ia.byte[ONE] & ia.mask.byte[ONE];
    result.byte[TWO] = ia.byte[TWO] & ia.mask.byte[TWO];
    result.byte[TRE] = ia.byte[TRE] & ia.mask.byte[TRE];
    result.byte[FOR] = ia.byte[FOR] & ia.mask.byte[FOR];

    // Check if the result is equal to the address itself
    return CMP_OCT(ia, result); // return 0 if it's an interface, 1 if it's a network
}
