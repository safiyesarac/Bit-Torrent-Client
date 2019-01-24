#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "nc.h"

void createClient(nc_args_t *);
void createServer(nc_args_t *);


/*
	At the moment, the client is reading a text and sending it to the server
	which then storing it. What I want is for the client to query the server
	with an offset and the server then writes from the offset to the client
	until the file is finished
*/
int main(int argc, char *argv[]) {
    
    nc_args_t nc_args;
    parse_args(&nc_args, argc, argv);
	
    if ((&nc_args)->listen == 1) {
		int retval;
		if ( ( retval = checkport( (&nc_args)->port ) ) == 0) {
			fprintf(stderr, "Valid port number is between 0 and 65535\n");
			usage(stdout);
			exit(1);
		} else if ( (&nc_args)->port < 2000) {
			fprintf(stderr, "Port number must be greater than 2000\n");
			usage(stdout);
			exit(1);
		}
		createServer(&nc_args);
    } else{
		createClient(&nc_args);
	}
    return 0;
    
}