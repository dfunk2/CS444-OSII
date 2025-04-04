/*Denise Funk
CS 444
April 1st, 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define array_size 5
int array[4] = {0};

void *thread(void* arg){
    //threads will print out an array of 0-4 prefixed by thread name 
    for(int i = 0; i < array_size; i++){
        printf("%s: %d\n", (char*) arg, i);
    }

    return NULL;
}

int main(void){
    pthread_t thread_id1, thread_id2;
    printf("Launching threads\n");
    
    pthread_create(&thread_id1, NULL, thread, "thread 1");

    pthread_create(&thread_id2, NULL, thread, "thread 2");
    
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    
    printf("Threads complete!\n");

}