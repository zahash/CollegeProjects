#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // for signal() and raise()

void zahash(int signum){
	printf("Zahash!! \n");
}

int main(){
	while(1){
	// execute zahash when SIGINT is raised
	// SIGINT is the interrupt signal (keyboard interrupt)

	signal(SIGINT, zahash);
	}
}
