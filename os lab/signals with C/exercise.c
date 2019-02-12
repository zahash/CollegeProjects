//write a program to put a process to sleep and then wake it up and then kill it when completed
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

void phalt(int signum){
  printf("Child needs to be killed\n");
}

void main(){
  pid_t cpid;
  pid_t ppid;
  
  if((cpid=fork())==0){
    cpid=getpid();
    signal(SIGUSR1,phalt);
    raise(SIGUSR1);
    //while(1);
  }
  
  else{
    kill(cpid,SIGTSTP);
    printf("Child %d halts\n",cpid);
    ppid=getppid();
    printf("Parent %d goes to sleep\n",ppid);
    sleep(5);
    printf("Parent %d awake\n",ppid);
    kill(cpid,SIGCONT);
    printf("Child %d continued\n",cpid);
    wait(NULL);
  }
}
