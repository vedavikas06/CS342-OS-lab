#include <stdio.h>
#include <malloc.h>     
#include <unistd.h>
#include <alloca.h>    
extern void afunc(void);    

int bss_var;          
int data_var = 42;  

int main(int argc, char **argv)
{
    char *p, *b, *nb;

    printf("Text Locations:\n");
    printf("\tAddress of main: %p\n", main);
    printf("\tAddress of afunc: %p\n", afunc);

    printf("Stack Locations:\n");
   // afunc();

    p = (char *) alloca(32);
    if (p != NULL) {
        printf("\tStart of alloca()'ed array: %p\n", p);
        printf("\tEnd of alloca()'ed array: %p\n", p + 31);
    }

    printf("Data Locations:\n");
    printf("\tAddress of data_var: %p\n", & data_var);

    printf("BSS Locations:\n");
    printf("\tAddress of bss_var: %p\n", & bss_var);

    b = sbrk((ptrdiff_t) 32);   /* grow address space */
    nb = sbrk((ptrdiff_t) 0);
    printf("Heap Locations:\n");
    printf("\tInitial end of heap: %p\n", b);
    printf("\tNew end of heap: %p\n", nb);

    b = sbrk((ptrdiff_t) -16);  /* shrink it */
    nb = sbrk((ptrdiff_t) 0);
    printf("\tFinal end of heap: %p\n", nb);
}

void afunc(void)
{
    static int level = 0;       /* recursion level */
    auto int stack_var;        /* automatic variable, on stack */

    if (++level == 3)           /* avoid infinite recursion */
        return;

    printf("\tStack level %d: address of stack_var: %p\n",
            level, & stack_var);
    afunc();                    /* recursive call */
}