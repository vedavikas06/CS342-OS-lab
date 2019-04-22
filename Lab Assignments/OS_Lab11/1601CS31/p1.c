#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* fileName[1000];
int mapStInd[1000];
int mapEndInd[1000];
void printMenu()
{
	printf("Enter : \n");
	printf("1. To add File\n");
	printf("2. To Print Directory \n");
	printf("3. TO exit\n");

}


int main()
{


	int numBlock;
	printf("------------------------- Sequential File Allocation -------------------------\n");
	printf("Number of Blocks in disk\n");
	scanf("%d",&numBlock);
	int* disk = malloc(sizeof(int)*numBlock);
	for(int i=0;i<numBlock;i++) {
		disk[i]=-1;
	}
	int totFile = 0;


	while(1)
	{
		printMenu();
		int choice;

		scanf("%d",&choice);
		if(choice == 1)
		{
			char* fName = malloc(sizeof(char)*1000);
			int stBlock,totBlock;
			printf("Enter File name,starting block and total number of blocks in file\n");
			scanf("%s%d%d",fName,&stBlock,&totBlock);
			int flag = 0;


			if(totBlock!=0){
				for(int i=stBlock;i<numBlock;i++)
				{
					
					if(stBlock+totBlock-1 == i)
					{
						flag = 1;
						break;
					}		

					if(disk[i]!=-1){
						break;		
					}
				}
			}
			

			if(flag == 1)
			{
				
				fileName[totFile] = fName;
				mapStInd[totFile]=stBlock;
				mapEndInd[totFile] = stBlock+totBlock-1;

				for(int i=stBlock;i<stBlock+totBlock;i++){
					disk[i]=totFile;
				}


				totFile++;
			}
			else
			{
				printf("Already occupied or Not available\n");
			}
		}
		else if(choice == 2)
		{
			printf(" File name 		Start Block 	 EndBlock\n");
			for(int i=0;i<totFile;i++)
			{
				printf("%10s 		%4d 		%4d\n",fileName[i],mapStInd[i],mapEndInd[i] );
			}
		}
		else if(choice == 3)
		{
			printf("Exit\n");
			break;
		}
		else
		{
			printf("Invalid Input\n");
		}
	}
	return 0;
}


