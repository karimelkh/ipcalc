#include "core.h"

#define SHORT_OPTS "b:d:ho:"

static struct option long_options[] = {
/*		name			has_arg					flag	val	*/
	{	"help",			no_argument,		NULL,		'h'	},
	{	"bin",			required_argument,	NULL,		'b'	},
	{	"isnet",		required_argument,	NULL,		'y'	},
	{	"isint",		required_argument,	NULL,		'z'	},
};

int main(int argc, char* argv[]) {
	if(argc == 1) {
		print_help();
		exit(EXIT_FAILURE);
	}
	opterr = 0; // disable `getopt` default error messages
	char current_opt;
	while((current_opt = (char) getopt_long(argc, argv, SHORT_OPTS, long_options, NULL)) != -1) {
		switch (current_opt) {
			case 'b':	/* get binary */
				get_bin(optarg);
				break;
	
			case 'd':	/* get decimal */
				log_msg("you chose 'd'");
				break;
		
			case 'h':	/* print help */
				print_help();
				break;

			case 'y':
				printf("is %s for a network? %s\n", optarg, is_net(to_addr_ip(optarg)) == 1 ? "yes" : "no");
				break;

			case 'z':
				printf("is %s for an interface? %s\n", optarg, is_net(to_addr_ip(optarg)) == 0 ? "yes" : "no");
				break;
			
			case '?':
				fprintf(stderr,  "invalid option: %s%c%s\n" , ANSI_RED, optopt, ANSI_RES);
				print_help();
				break;
			
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
