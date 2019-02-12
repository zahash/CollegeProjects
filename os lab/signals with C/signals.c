#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // for signal() and raise()

/* int signal(int signum, void (*handler)(int)) */

// signal handler takes signal number and a function (which reuturns void)
// which will be executed when that signal arrives


void zahash(int signum){
	printf("Zahash!! \n");
	}

int main(){
	// execute zahash when SIGUSR1 is raised
	signal(SIGUSR1, zahash);
	
	// raise the signal
	raise(SIGUSR1);
	}

