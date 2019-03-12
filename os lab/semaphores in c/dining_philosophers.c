#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


void *philosopher(void *arg) {
	int n = 5;

	while(1){
		thinking();

		take_fork(i);
		take_fork((i+1)%n);

		eat();

		put_fork(i);
		put_fork((i+1)%n);
	}

}

int main(void) {

    pthread_t tid0,tid1;
    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);

	// create more threads for reader and writer as per required	
    pthread_create(&tid0, NULL, writer, NULL);
    pthread_create(&tid1, NULL, reader, NULL);
    
    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}