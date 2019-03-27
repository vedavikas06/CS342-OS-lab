#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char **argv){
	

	int a = atoi(argv[0]);
	int b = atoi(argv[1]);
	char* ch = argv[2];

	if(*ch=='+'){
		return a+b;
	}else if(*ch=='-'){
		return a-b;
	}
	


}
























