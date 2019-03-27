#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
  
int main() 
{ 
    
    int fd1[2];   
  
    
    char input_str[100]; 
    pid_t p; 
  
    if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    printf("Enter Message :\n");
    scanf("%[^\n]s", input_str); 
    p = fork(); 
  
    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
  
    else if (p > 0) 
    { 
  
        close(fd1[0]);  
  
        printf("\nwriting \"%s\" into the pipe - parent process\n",input_str); 
        write(fd1[1], input_str, strlen(input_str)+1); 
        close(fd1[1]); 
  
       
        wait(NULL); 
  
        printf("\nDone!!\n");
    } 
  
    // child process 
    else
    { 
        close(fd1[1]);  // Close writing end of first pipe 
  
        // Read a string using first pipe 
        char read_str[100]; 
        read(fd1[0], read_str, 100); 
  
        
        int k = strlen(read_str); 
        
        read_str[k] = '\0';   
        
       
        printf("read  \"%s\" from the pipe - child process\n",read_str); 
        // Close both reading ends 
        close(fd1[0]); 
       
  
       
        exit(0); 
    } 

    return 0;
} 
