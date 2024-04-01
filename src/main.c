#include "core.h"

#define OPTIONS "b:d:ho:"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	opterr = 0; // disable `getopt` default error messages
	char opt;
	while((opt = getopt(argc, argv, OPTIONS)) != -1)
	{
		switch (opt)
		{
			case 'b':	/* get binary */
				to_bin(optarg);
				break;
	
			case 'd':	/* get decimal */
				log_msg("you chose 'd'");
				break;
		
			case 'h':	/* print help */
				print_help();
				break;
			
			case '?':
				fprintf(stderr, ANSI_CLR_RED "invalid option: %s\n" ANSI_CLR_RES, opt);
				print_help();
				break;
			
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
