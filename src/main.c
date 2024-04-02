#include "core.c" // this is temporary - later we will build it with `make`

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
	while((opt = (char)getopt(argc, argv, OPTIONS)) != -1)
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
				fprintf(stderr,  "invalid option: %s %c %s\n" , ANSI_RED, optopt, ANSI_RES);
				print_help();
				break;
			
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
