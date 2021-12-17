#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[3];
int counter = 0;
pthread_mutex_t lock;
  
void* trythis(void* arg)
{
  
    unsigned long i = 0;
//    counter += 500;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < 50000; i++) 
	{
    
		pthread_mutex_lock(&lock);
		counter++;
    	pthread_mutex_unlock(&lock);
	}
        
  
    printf("\n Job %d has finished\n", counter);
  
  
    return NULL;
}
int main(void)
{
    int i = 0;
    int error;  
//    if (pthread_mutex_init(&lock, NULL) != 0) {
//        printf("\n mutex init has failed\n");
//        return 1;
//    }
    while (i < 3) {
        error = pthread_create(&(tid[i]),
                               NULL,
                               &trythis, NULL);
//        if (i > 3 ){
//        	for(i=1; i < 2; i++){
//        		tid[i] = (rand()%1001 )+1;
//				printf("%d \n", tid[i]);			
//			}	
//		}
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));                
        i++;     
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
//    pthread_mutex_destroy(&lock);
     return 0;
}

