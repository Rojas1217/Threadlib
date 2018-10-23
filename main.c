#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long sum =0;

//Thread function that will generate sum of 0 to n, just for sake of passing some function into threads
void* sum_run(void* arg) {
	long *limit_ptr = (long*) arg;
	long limit = *limit_ptr;

	
	for (long i = 0; i <= limit; i++) {
		sum+= i;
	}
	pthread_exit(0);
}


int main(int argc, char **argv) {

	if (argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}
	
	long limit = atoll(argv[1]);

	//Thread ID
	pthread_t tid;
	
	//Create attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&tid, &attr, sum_run, &limit);

	
	//
	pthread_join(tid, NULL);
	printf("sum is %ld\n", sum);
	printf("Thread ID is %ld\n",pthread_self());
}



