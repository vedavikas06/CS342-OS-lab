#include<stdio.h>
#include<math.h>

unsigned int logn2(unsigned int x)
{
   return (x>1) ? 1+logn2(x/2) : 0;
}

int main()
{
    unsigned int pas ,las , page , p, q, r;
    printf("Enter Physical Address Space (in GB): ");
    scanf("%u", &pas);
    printf("Enter Virtual Address Space (in GB): ");
    scanf("%u", &las);
    printf("Enter Page Size (in kB): ");
    scanf("%u", &page);
    
    p = logn2(pas)+30;
    q = logn2(las)+30;
    r = logn2(page)+10;

    printf("Number of Pages in the system is 2 ^ %d\n", q-r);
    printf("Number of Frames in the system is 2 ^ %d\n", p-r);
    printf("Number of bits required to represent the Physical Address is %u\n", p);
    printf("Number of bits required to represent the Virtual Address is %u\n", q);
    printf("Number of bits required to represent the Page Offset is %u\n", r);
    
    printf("Page Table Size is %d * (2 ^ %d) kBytes\t", p-r, q-r);
    
    return 0;
}
