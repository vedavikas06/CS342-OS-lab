#include <unistd.h> 
#include <stdio.h> 

#include<stdlib.h> 

#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 



int main(int argc, char *argv[]){




	printf("file2 process\n\n");
	
	float x = atof(argv[0]);
	int n = atoi(argv[1]);
	//printf("%f %d", x, n);
	
	float tot = 1.0f;
	float po =x;
	long long fac = 1;

	for(int i=1;i<n;i++){
		tot+=(float) po/fac;
		po *= x;
		fac*=(i+1);

	}

	printf("Result :%f \n\n",tot);

	

		 





return 0;



}
























