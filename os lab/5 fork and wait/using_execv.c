#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* Executing external program using 'execv' command */

int main(int argc, char * argv[]){
	// executing the 'ls' program
	char * is_args[] = {"/bin/ls", "-l", NULL};
	// execv(filepath, arguments)
	execv(is_args[0], is_args);
	perror("execv");
	return 0;
}

// try executing a simple python file
