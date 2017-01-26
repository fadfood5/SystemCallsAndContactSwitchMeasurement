#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int main(){

	int ar[3]={0,1,2};
	sysCall(ar);
	return 0;		
}

int sysCall(int arr[]){
	struct timeval start, end;
	long totaltime = 0.0;
	int counter = 0;
	int size = sizeof(arr)/sizeof(int) + 1;
	for(int i=0; i < size; i++){
		gettimeofday(&start, NULL);
		system(arr[i]);
		gettimeofday(&end, NULL);
		counter++;
		printf("System Call %ld time: %d microseconds\n", counter, ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));  	totaltime += ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec));
	}
	printf("Total number of calls: %d\n", size);
	printf("Total time: %ld microseconds\n", totaltime);
	printf("Average time per call: %ld microseconds\n", totaltime/3);
	return 0;
}
