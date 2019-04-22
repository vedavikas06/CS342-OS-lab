#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
int main()
{

  printf("Consider a paging hardware with a TLB. Assume that the entire page table and all the pages are in the physical memory. It takes TLB_search_time milliseconds to search the TLB and memory_access_time​ milliseconds to access the physical memory. If the TLB hit ratio is hit_ratio 0<hit_ratio<=1 ");

  float TLB_search_time,memory_access_time,hit_ratio; 

  printf("\nTLB_search_time, memory_access_time ,hit_ratio in milliseconds\n");
  scanf("%f %f %f",&TLB_search_time, &memory_access_time ,&hit_ratio);
  float result = hit_ratio * (TLB_search_time + memory_access_time) + (1.00 - hit_ratio) * (TLB_search_time + 2*memory_access_time);
  printf("effective memory access time (in milliseconds) : %f\n",result);




	return 0;
}