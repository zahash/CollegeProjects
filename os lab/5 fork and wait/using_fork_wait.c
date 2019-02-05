#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t c_pid, pid; // pid_t is a datatype 'short int'
	int status;
	c_pid = fork();
		
	// parent will wait for child to complete
	if(c_pid == 0){		
		pid = getpid();
		printf("Child: %d \n", pid);
		printf("Child waits for 2 sec, exits after 12 sec \n");
		sleep(2);
		exit(12);
		}
		
	else if (c_pid > 0){
		pid = wait(&status);
		if(WIFEXITED(status)){
			printf("Parent: Child exited with status: %d \n", WEXITSTATUS(status));
			}
		}
		
	else{
		perror("fork failed");
		exit(2); // exit failure, hard
		}
		
	return 0; // sucess
	}
	
	
