#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <sys/time.h>

//Reference used was manual of sched_setaffinity
//Makes it so that there is only 1 processor in use
int setCpu(){
        cpu_set_t  set;
        CPU_ZERO(&set);
        CPU_SET(0, &set);
        sched_setaffinity(0, sizeof(set), &set);
        printf("Set process to CPU 0\n");
}

struct timeval start, end;
long totaltime = 0.0;

//Write file function used for first process
int write(){

        FILE *fileWrite = fopen("pipe.txt", "w");

        /*Error handler*/
        if(fileWrite == NULL){
                printf("Cannot open file, terminating...\n");
                exit(1);
        }

        /*Was for testing*/
        char *writeText = "Testing";
        fprintf(fileWrite, "%s", writeText);

        /*Sets the start of the timer*/
        gettimeofday(&start, NULL);

        fclose(fileWrite);

        //Was for testing
        //printf("Write finished\n");
        return 0;

}

//Read file function used for the second process
int read(){

        FILE *fileWrite = fopen("pipe.txt", "r");

        //Sets the end of the timer
        gettimeofday(&end, NULL);

if(fileWrite != NULL){

        FILE *fileWrite = fopen("pipe.txt", "r");

        //Sets the end of the timer
        gettimeofday(&end, NULL);

        char content[100];
        if(fileWrite != NULL){
                while(fscanf(fileWrite, "%s", content) != EOF);
                        printf("%s", content);
                printf("\nRead finished\n");
                printf("\n");
                fclose(fileWrite);

        }

        /*Error Handler*/
        else{
                printf("Cannot open file. Terminating...");
                exit(1);
                }
        }
}

//Function used to find the context switch time
int testContextSwitch(){

        int counter = 0;
        long totaltime = 0.0;
        for(int i = 0; i < 50; i++){

                write(); //Calls first process
                read(); //Calls second process
                counter++; //Increment counter for finding average
                printf("Context switch number  %ld time: %d microseconds\n", counter, ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))); //Prints the current context switch number and time it took to switch
                totaltime += ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)); //Adds the total time for context switching

        }

        printf("Total time: %ld microseconds\n", totaltime); //Prints total time
        printf("Average time per context switch: %ld microseconds\n", totaltime/counter); //Prints the average time
}

int main(){
        setCpu();       //Calls function to set # of processors used to 1
        testContextSwitch();    //Initiates context switch function
        return 0;
}
                                                                                   103,1         Bot

