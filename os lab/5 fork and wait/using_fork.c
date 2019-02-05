#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int pid;
	printf("Process related system calls \n");
	
	if((pid=fork()) == -1){
		perror("During Fork \n");
		exit(0);
		}
	
	// parent and child will run in parallel
	if(pid == 0){
		printf("child process \n");
		printf("process id = %d \n", getpid());
		printf("process id of parent = %d \n", getppid());
		exit(0);
		}
	else{
		printf("parent process \n");
		printf("process id = %d \n", getpid());
		printf("process id of parent = %d \n", getppid());
		exit(0);
		}
	}
