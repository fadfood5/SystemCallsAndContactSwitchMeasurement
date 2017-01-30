#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int sysCall(int arr[]);

int main(){

        int ar[50] = {0};       //Creates the array for the sysCall function
        sysCall(ar);            //Calls the sysCall funciton
        return 0;
}

int sysCall(int arr[]){

        /*Varibles*/
        struct timeval start, end;
        long totaltime = 0.0;
        int counter = 0;
        //int size = sizeof(arr)/sizeof(int) + 1; 
        int size = 50; //Size of array


        /*For the size of the array, gets the time prior to execution, performs system call, gets time after system call*/
        /*Then it increments counter to display which iteration it is, and the time it took for the individual system call*/
        /*Finally adds to the total time it took for the system call, that way we can print the total and average after the loop        completes*/
        for(int i=0; i < size; i++){

                gettimeofday(&start, NULL);
                system(arr[i]);
                gettimeofday(&end, NULL);

                counter++;
                printf("System Call %ld time: %d microseconds\n", counter, ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
                totaltime += ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec));

        }

        printf("Total number of calls: %d\n", size);                            //Prints the number of calls
        printf("Total time: %ld microseconds\n", totaltime);                    //Prints the total time
        printf("Average time per call: %ld microseconds\n", totaltime/size);    //Prints the average time

        return 0;       //End the function
}
