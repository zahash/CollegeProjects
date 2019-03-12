#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;
int readcount=0;


void *writer(void *arg) {
	// for writer

	printf("Writer Entering...\n");
	sem_wait(&wrt);
	printf("Writer Entered Sucessfully\n");

	sleep(2);		// write operation

	printf("Writer Exiting...\n");
	sem_post(&wrt);
	printf("Writer Exited Sucessfully\n");
}


void *reader(void *arg) {
	// for reader

	printf("Reader Entering...\n");
	sem_wait(&mutex);
	readcount++;

	if(readcount==1){
		printf("(This is the First Reader)\n");
		sem_wait(&wrt);
	}

	sem_post(&mutex);
	printf("Reader Entered Sucessfully\n");

	sleep(2); 		//read operation

	printf("Reader Exiting...\n");
	sem_wait(&mutex);
	readcount--;

	if(readcount==0){
		printf("(This is the Last Reader)\n");
		sem_post(&wrt);
	}

	sem_post(&mutex);
	printf("Reader Exited Sucessfully\n");
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