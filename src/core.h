typedef struct mask nmask;

typedef struct addr ipv4_addr;


void print_help(void);

void log_err(const char*);

void log_msg(const char*);

// return the binary of an unsigned int
char* uint_to_bin(unsigned int);

// return the binary form of an ipv4 address
char* ipv4_dec_to_bin(ipv4_addr);

// count how many 1s in an unsigned int
int count_ones(unsigned int);

// check if an ipv4 address is for a network
int is_network(ipv4_addr);

// check if an ipv4 address is for an interface
int is_interface(ipv4_addr);

void print_ipv4(ipv4_addr);

// return ipv4_addr from a string
ipv4_addr str_to_ipv4(const char*);

