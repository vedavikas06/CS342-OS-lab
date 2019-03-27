#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> 


int main()
{

char op1[20], op2[20];
char sign;
int status;


printf("Enter x and n:\n");
scanf("%s %s", op1, op2);

//printf("%s %s", op1, op2);

int pid = fork();

if (pid == 0)
{
	printf("In Child process\n\n");

	if (execl("file2",op1,op2,NULL) < 0)
	perror("eroare") ;

	
}
else if (pid>0)
{
	printf("In Parent process\n\n");
	waitpid(pid, &status, 0);

	printf("Child process Done\n");

	printf("Parent process Done\n");

}

exit(0);



}


















