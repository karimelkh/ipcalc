#include "core.h"

#define OPTS "b:d:ho:"

int main(int argc, char* argv[]) {
	if(argc == 1) {
		print_help();
		// exit(1);
		exit(0);
	}
	int opt, domain;
	opterr = 0; // disable `getopt` default error messages
	char* addr_fam = "i4"; // default output type
	while((opt = getopt(argc, argv, OPTS)) != -1) {
		switch (opt) {
			case 'b':
				char* bin_form = optarg;
				char* dec_form;
				if(getopt(argc, argv, OPTS) == 'o')
					addr_fam = optarg;
				domain	=	(strcmp(addr_fam, "i4") == 0) ? AF_INET :
							(strcmp(addr_fam, "i6") == 0) ? AF_INET6 : -1; // neither case to implement later
				inet_pton(domain, bin_form, dec_form);
				printf("%s\t%s\n", bin_form, dec_form);
				break;
			/* case 'd':
				printf("Binary: %s\n", to_bin(optarg));
				break;*/
			case 'h':
				print_help();
				break;
			case '?':
				fprintf(stderr, "%s: Invalid option\n", argv[0]);
				print_help();
				break;
			default:
				break;
		}
	}
	return 0;
}
