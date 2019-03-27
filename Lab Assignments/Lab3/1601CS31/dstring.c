#include <unistd.h> 
#include <stdio.h> 

#include<stdlib.h> 

#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main ( int argc, char *argv[] )
{
    if ( argc != 2 ) 
    {
        printf( "usage: %s is provided,.txt is not provided", argv[0] );
    }
    else 
    {
        FILE *file = fopen( argv[1], "r" );
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int x;
            int cnt =0;
            char word[100] = "";
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                
                if (x == ' ') 
                { 
                 
                 //word[cnt] = '\0';
                 printf("%s\n",word);
                 strncpy(word, "\0", 100);
                 cnt =0;
               } 
               else if( x != '\n')
               { 
                   word[cnt++] = (char) x; 
               } 
            }
            printf("%s",word);
            fclose( file );
            printf("\n");
        }
    }
}