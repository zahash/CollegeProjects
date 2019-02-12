// write a program to put a (child)process to sleep 
// and then wake it up and then kill when completed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

void zahash(){
	printf("Zahash!! \n");
}

int main(){
	
	// create a child process
	pid_t cpid;
	pid_t ppid;
	
	if((cpid = fork())==0){
		/* child */
		
		ppid = getppid(); // not needed but lets just define it anyways
	
	
		// put the process to sleep for 3 seconds
		printf("sleeping.... \n");
		sleep(3);
		
		
		// after 3 seconds, execute the process
		printf("executing... \n");
		zahash();
		printf("successfull execution of zahash \n");
		
		
		// after execution, kill the process
		printf("killing the child... \n");
		kill(cpid, SIGUSR1);
		printf("successfully killed... \n"); // will never get displayed
		
		raise(SIGUSR1);
	}
	
		
}
