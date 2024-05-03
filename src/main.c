#include "ipc.h"

#define VALID_SHORT_OPTS "b:ht:n:"

static struct option long_options[] = {
	/*	name			has_arg				flag		val	*/
	{	"help",			no_argument,		NULL,		'h'	},
	{	"bin",			required_argument,	NULL,		'b'	},
	{	"net",			required_argument,	NULL,		'n'	},
	{	"type",			required_argument,	NULL,		't'	},
	{	"isnet",		required_argument,	NULL,		'y'	},
	{	"isint",		required_argument,	NULL,		'z'	},
};

int main(int argc, char* argv[]) {
	if(argc == 1) {
		log_help();
		exit(EXIT_FAILURE);
	}

	char current_opt;
	int ip_ver = 0;

	while((current_opt = (char) getopt_long(argc, argv, VALID_SHORT_OPTS, long_options, NULL)) != -1) {
		switch (current_opt) {
			case 'b':
				ip_ver = atoi(optarg);
				if (optind >= argc) {
					fprintf(stderr, "Expected argument after -b option\n");
//					log_err(1, "Expected argument after -b option");
					exit(EXIT_FAILURE);
				}
				// seg fault here when using incorrect ip_ver value:
				// `ipcalc --bin 5 192.0.0.0`
				ipc_bin(argv[optind], ip_ver);
				optind++; // Move to the next argument after the IP address
				break;

			case 'h':
				log_help();
				break;

			case 'n':
			case 't':
			case 'y':
			case 'z':
				char* ip_address = (char*) malloc(100 * sizeof(char)); // change this 100 (random value)
				strcpy(ip_address, optarg);
				opt_got_arg(argc, argv, "s:"); // BAD_NAME, to chnage later
				if(current_opt == 'y')
					ipc_isnet(ip_address, optarg);
				else if(current_opt == 'z')
					ipc_isint(ip_address, optarg);
				else if(current_opt == 't')
					ipc_type(ip_address, optarg);
				else
					ipc_net(ip_address, optarg);
				free(ip_address);
				break;

			case '?':
				// to enhance with `log_err()` next commit -- WAITING FOR OTHER COMMIT --
				fprintf(stderr,  "invalid option: %s%c%s\n" , ANSI_RED, optopt, ANSI_RES);
				log_help();
				break;

			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
