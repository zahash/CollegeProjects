#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* pass input to parent process and let child finish it
 * like, 'cat sample.txt' will be the input */

int main(){
	int pid, status;
	printf("Process related system calls \n");
	
	// take the input here
	
	
	if((pid=fork()) == -1){
		perror("During Fork \n");
		exit(0);
		}
	
	if(pid == 0){
		printf("child process \n");
		printf("process id = %d \n", getpid());
		printf("process id of parent = %d \n", getppid());
		
		// execute the process here
		
		exit(0);
		}
		
	else{
		wait(&status);
		printf("parent process \n");
		printf("process id = %d \n", getpid());
		printf("process id of parent = %d \n", getppid());
		exit(0);
		}
	}
