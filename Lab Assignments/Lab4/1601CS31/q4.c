#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){

	int t;

	scanf("%d",&t);

	int pid = fork();

	if (pid == -1) { 
		fprintf(stderr, "fork failed\n"); 
		exit(1);

	} 



	if (pid == 0) { 
		printf("child process\n");
		printf("child process id %d\n",getpid());

		sleep(t);

		printf("slept for : %d sec\n-------------\n",t);
		exit(0);


	 
	} 

	if (pid > 0) { 
		printf("parent process\n");
                
		printf("parent and child process id's: %d , %d\n",getpid(),pid);
		wait(NULL);
		exit(1);

	}





return 0;



}

























