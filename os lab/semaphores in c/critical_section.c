#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg){
	sem_wait(&mutex);		// wait
	printf("Entering Critical Section\n");

	sleep(4);


	printf("Exiting Critical Section\n");
	sem_post(&mutex);		// signal
}

int main(){
	sem_init(&mutex, 0, 1);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread, NULL);

	sleep(0.2);		// small delay before creting(running) t2 to ensure that t1 would start first

	pthread_create(&t2, NULL, thread, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	sem_destroy(&mutex);

	return 0;
}