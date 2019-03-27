#include <unistd.h> 
#include <stdio.h> 

int factorial(int n){
	int tot =1;

	for(int i=1;i<=n;i++){
		tot=tot*i;
	}

	printf("output %d of process id : %d\n",tot,getpid());
	return tot;
}

int main(){


	printf("Before Fork\n");
	factorial(5);
	printf("-------------\n");


	int pid = fork();

	if (pid == -1) { 
	fprintf(stderr, "fork failed\n"); 

	} 



	if (pid == 0) { 
		printf("child process\n");
		factorial(5);
		printf("-------------\n");
	 
	} 

	if (pid > 0) { 
		printf("parent process\n");
		factorial(5);
		printf("-------------\n");	 
	}




return 0;



}

























