#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


int funct(int a,int b,int ch){
	if(ch==1){
		return a+b;
	}else if(ch==2){
		return a-b;
	}
	
}

int main(){

	int a,b,status;
	char ch;
	printf("Input a,b,sign(2 numbers,sign)\n");
	scanf("%d %d %c",&a,&b,&ch);
	printf("Input Sign(+,-)\n");
  	
	

    printf("%d %d %c\n",a,b,ch);
	int pid = fork();

	if (pid == -1) { 
	fprintf(stderr, "fork failed\n"); 

	} 

	if (pid == 0) { 

		printf("child process\n");
		
		char *str_fd1;		
		char str_fd2[10],str_fd3[10];
		
		str_fd1 = "server";
	    sprintf(str_fd2, "%d", a);
	    sprintf(str_fd3, "%d", b);
	    

	    //printf("%s %s %s %s\n",str_fd1,str_fd2,str_fd3,str_fd4);

	    char *arg[5];
	    arg[0] = str_fd1;
	    arg[1] = str_fd2;
	    arg[2] = str_fd3;
	    arg[3] = &ch;
	    arg[4] = NULL;

	    //printf("%s %s %s %s\n",arg[0],arg[1],arg[2],arg[3]);
	    printf("sent ---------\n\n");
	    //execl("./p3","./p3",arg[1],arg[2],arg[3],(char *)0);
	    if(execl("server",arg[1],arg[2],arg[3], NULL)<0)
            perror("eroare") ;	

	} 

	if (pid > 0) { 
		printf("parent process-----------\n\n");
		waitpid(pid, &status, 0) ;
    	printf("Result is: %d\n", WEXITSTATUS(status)) ;

		
	}




exit(0) ;



}
























