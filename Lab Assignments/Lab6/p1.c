#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#define buffersize 5

int buffer[buffersize];
int cons_st=0,prod_st=0;

sem_t mutex,empty,full;

void wait(int* S){
	while((*S)<=0);   
	(*S)--;
}

void signal(int* S){
	(*S)++;
}


void* prod(void *arg){

	int prodId = *((int *)arg);

	while(1){
	
	sleep(1 + rand()%3);
	sem_wait(&empty);
	sem_wait(&mutex);

	buffer[prod_st] = rand()%1000;
	
	printf("%d is produced by thread %d\n",buffer[prod_st],prodId);
	prod_st++;
	
	

	if (prod_st >= buffersize){
		
		if(prod_st >= buffersize && cons_st == 0){
			printf("Buffer is full\n");
		}
		/*for(int i=0;i<buffersize;i++){
			printf("%d ",buffer[i]);
		}
		printf("\n");*/
    		prod_st = 0;
	}


	
	

	 sem_post(&mutex);
	sem_post(&full);

	}



}


void* cons(void *arg){

	int consId = *((int *)arg);

	while(1){
		sleep(1+rand()%4);
		sem_wait(&full);
		sem_wait(&mutex);

		printf("%d is consumed by thread %d\n",buffer[cons_st],consId);
		buffer[cons_st] = 0;
		cons_st++;
		  if (cons_st >= buffersize) {
		   	cons_st = 0;
		}

		
		 sem_post(&mutex);
		sem_post(&empty);


		
	}



}




int main(){

	int sleep_time,cons_thr,prod_thr;
	
	printf("Enter the number of Producers:");
	scanf("%d",&prod_thr);
	printf("Enter the number of Consumers:");
	scanf("%d",&cons_thr);
	printf("Enter sleep time:");
	scanf("%d",&sleep_time);

	

   pthread_t cons_threads[cons_thr];
   pthread_t prod_threads[prod_thr];

   //pthread_mutex_init(&lockPrint,NULL);
   srand(time(0));
   sem_init(&mutex, 0, 1);
   sem_init(&full, 0, 0);
   sem_init(&empty, 0, buffersize);
   
 
  // sem_init(&full,0,1);
   //sem_init(&empty,0,1);
   
    for(int i =0;i<prod_thr;i++)
   {
   	   int thr = pthread_create(&prod_threads[i],NULL,prod,&i);
   	   if(thr < 0)
   	   {
   	   	 printf("Thread failed %d\n",i);
   	   }
   	   printf("=========Producer Thread %d started==========\n",i); 
   	   sleep(0.1);
   }

   
   for(int i =0;i<cons_thr;i++)
   {
   	   int thr = pthread_create(&cons_threads[i],NULL,cons,&i);
   	   if(thr < 0)
   	   {
   	   	 printf("Thread failed %d\n",i);
   	   }
   	   printf("=========Consumer Thread %d started==========\n",i); 
   	   sleep(0.1);
   }


   sleep(sleep_time);
   for(int i=0; i<prod_thr; i++)
      pthread_cancel(prod_threads[i]);

   for(int i=0; i<cons_thr; i++)
      pthread_cancel(cons_threads[i]);
   
   printf("\nThe program is now exited.\n");



	return 0;
}

