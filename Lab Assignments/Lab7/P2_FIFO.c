//gcc p2.c
//./a.out < pages.txt



#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct Queue 
{ 
    int front, rear, siz; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->siz = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
int isFull(struct Queue* queue) 
{  return (queue->siz == queue->capacity);  } 
  
int isEmpty(struct Queue* queue) 
{  return (queue->siz == 0); } 
  
int enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return -1; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->siz = queue->siz + 1; 
    // printf("%d enqueued to queue\n", item); 
    return queue->rear;
} 
  
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->siz = queue->siz - 1; 
    return item; 
} 
  
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 

int main()
{
	
	int n;
	while(scanf("%d",&n) != EOF){
	

	// scanf("%d",&n);

	int page[100];
	int st =0;
	while(1){
		int a;
		scanf("%d",&a);
		if(a!=-1){
			page[st] = a;
			printf("%d ", page[st]);

			st++;


		}else{
			break;
		}

	}
	
	int present[100];
	for(int i=0;i<100;i++){
		present[i] = 0;
	}


	int sizee = st;
	int hist[n][sizee];


	// printf(" size  %d ", sizee);

for(int i=0;i<n;i++){

 	for(int j =0;j<sizee;j++){
			hist[i][j] = 0;
		}	
}

	// printf(" size  %d ", sizee);
	

	struct Queue* queue = createQueue(n); 

	int cnt =0;



  	for(int i=0;i<sizee;i++){

  		if(i>0){
  			for(int j =0;j<n;j++){
  				hist[j][i] = hist[j][i-1]; 
  			}
  		}

  		if(present[page[i]] == 0){
		
	    	int fr = enqueue(queue, page[i]); 

	    	if(fr == -1){
	    		int deq = dequeue(queue);
	 			 //printf("%d dequeued from queue\n", deq); 
	    		 int enq = enqueue(queue, page[i]);
	    		 hist[enq][i] = page[i];

	    		 present[deq] = 0;
	    		 present[page[i]] = 1;

	    	}else{
	    		 hist[fr][i] = page[i];
	    		 present[page[i]] = 1;

	    	}

	    	cnt++;

    	}else{
		 //printf("Already present\n"); 

    	}
    	

	}

	printf("\n--------------------------------------------------------\n");
	for(int i=0;i<n;i++){

  		for(int j =0;j<sizee;j++){
  				printf("%d ", hist[i][j]);
  			}

  		printf("\n");		
	}

	printf("\n\nUsing %d frames, the reference string yielded:\nScheme          #Faults\n",n);

	printf("FIFO            %d\n\n",cnt);
	

	}

	return 0;
}
