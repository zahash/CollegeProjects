#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void *cube(void *a){

	int *arr = (int *) a;

	int size = 4;
	for(int i=0; i<size; i++){
		int cb = pow(arr[i], 3);
		printf("cube of %d is %d\n", arr[i], cb);

		sleep(0.2);
	}
}

void *square(void *a){

	int *arr = (int *) a;

	int size = 4;
	for(int i=0; i<size; i++){
		int cb = pow(arr[i], 2);
		printf("square of %d is %d\n", arr[i], cb);

		sleep(0.2);
	}
}


int main(){

	int size = 4;
	int arr[] = {1,2,3,5};

	pthread_t T1, T2;

	pthread_create(&T1, NULL, cube, (void *)arr);
	pthread_create(&T2, NULL, square, (void *)arr);

	pthread_join(T1, NULL);
	pthread_join(T2, NULL);

	printf("All Done \n");
	
	return 0;
}
