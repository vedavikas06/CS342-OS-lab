//gcc p5.c -o p5.o -lm
//./p5.o

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  

int main()
{
	
  printf("A CPU generates​ M-bit ​virtual addresses. The page size is​ N ​Bytes. The processor has a translation look-aside buffer (TLB) which can hold a total of​ L page table​ entries and is n-​way set associative. ");


  int M,N,L,n;

  printf("\nM,N,L,n\n");
  scanf("%d %d %d %d",&M,&N,&L,&n);

  N = log2(N);
  int no_sets;
  no_sets = L/n;

  int bits_no_sets =  log2(no_sets);

  int no_bits_page_frame = M-N;


  printf("no of tag bits : %d\n",no_bits_page_frame-bits_no_sets);




	return 0;
}