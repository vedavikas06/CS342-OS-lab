#include <unistd.h> 
#include <stdio.h> 

int p = 0;

int main(){



	int pid = fork();

	if (pid == -1) { 
		fprintf(stderr, "fork failed\n"); 

	} 



	if (pid == 0) { 
		printf("child process\n");
		p++;

		printf("p : %d\n-------------\n",p);
	 
	} 

	if (pid > 0) { 
		printf("parent process\n");
		p++;
		printf("p : %d\n-------------\n",p);

	}


/*fork()ing creates an exact copy of the parent process at the time of forking. However, after the fork() is completed, the child has a completely different existence, and will not report back to the parent.

In simple words,the parent's global variables will not be altered by changes in the child.*/


return 0;



}

























