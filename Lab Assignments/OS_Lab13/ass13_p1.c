#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>


void MAX(int arr[], int l, int r)
{
	int status;
	if(r-l<9)
	{
		int max = -1;
		int i;
		for(i=l;i<=r;++i)
		{
			if(arr[i] > max){
				max = arr[i];	
			}
			
		}
		printf("PID = %d \t parent PID = %d \t max = %d\n",getpid(),getppid(),max);
		exit(max);	
	}
	else
	{
		int cpid1, cpid2;
		if((cpid1 = fork()) == 0)
		{
			r = l+((r-l)/2);
			MAX(arr, l, r);		
		}
		else if((cpid2 = fork()) == 0)
		{
			l = l+((r-l)/2) + 1;
			MAX(arr, l, r);		
		}
		else//Parent
		{
			waitpid(cpid1, &status, 0);
			int max1 = status / 256;
		
			waitpid(cpid2, &status, 0);
			int max2 = status / 256;
			
			int max;
			if(max1>max2){
				max = max1;
			}else{
				max = max2;
			}

			printf("PID = %d \t parent PID = %d \t max = %d\n",getpid(),getppid(),max);
			exit(max);		
		}
	
	}

}


int main(int argc, char * argv[])
{
	srand((unsigned int)time(NULL));
	int arr[1000];
	int n,i,status;
	
	
	if(argc!=2)
	{
		printf("Invalid arguments!!\n");
		exit(0);
	}
	
	n = atoi(argv[1]);
	
	int cpid;
	
	//Generate random numbers
	for(i=0;i<n;++i) {
		arr[i] = rand()%128;
	}
	
	
	printf("Original Array \n\n");	
	for(i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	
	printf("\n\n");
	
	//Fork a child process which computes max
	if((cpid = fork()) == 0)//Child process
	{
		MAX(arr, 0, n-1);	
	}
	else//Parent process
	{
		waitpid(cpid, &status, 0);
		
		int max = status >> 8;
		printf("The maximum value in the array is : %d\n",max);
	}
	sleep(2);
	exit(0);
}




