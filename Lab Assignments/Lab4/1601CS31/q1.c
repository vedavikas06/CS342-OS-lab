#include <unistd.h> 
#include <stdio.h> 

int main(){


int pid = fork();

	if (pid == -1) { 
	fprintf(stderr, "fork failed\n"); 
	
	} 

	if (pid == 0) { 
	printf("parent process id is %d in child process\n",getppid()); 
	 
	} 

	if (pid > 0) { 
	printf("child process id is %d in parent process\n",pid); 
	 
	}




return 0;



}


/* As fork created a child process we can print parent process id in child process using getppid() similarly we can get child pid using pid variable */

























