#include "core.c" // this is temporary - later we will build it with `make`

#define OPTIONS "b:d:ho:"

static struct option long_options[] = {
/*		name			has_arg					flag	val	*/
	{	"help",			required_argument,		0,		'h'	},
	{	"bin",			no_argument,			0,		'b'	},
//	{	"delete",		required_argument,		0,		0	},
//	{	"verbose",		no_argument,			0,		0	},
//	{	"create",		required_argument,		0,		'c'	},
//	{	"file",			required_argument,		0,		0	},
//	{	0,				0,						0,		0	}
};

int main(int argc, char* argv[]) {
	if(argc == 1) {
		print_help();
		exit(EXIT_FAILURE);
	}
	// addr_ip ia = { {105, 67, 5, 96}, {{255, 255, 255, 0}} };
	opterr = 0; // disable `getopt` default error messages
	char opt;
	while((opt = (char)getopt(argc, argv, OPTIONS)) != -1) {
	// while((opt = (char) getopt_long(argc, argv, OPTIONS, long_options, NULL)) != -1) {
		switch (opt) {
			case 'b':	/* get binary */
				get_bin(optarg);
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
