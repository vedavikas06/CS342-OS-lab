#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000][100000];
char* fileMap[100000];
int mapIdx[100000];
int sz[100000];

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
	printf("------------------------- Indexed File Allocation -------------------------\n");
	printf("Enter the number of Blocks in disk\n");
	scanf("%d",&numBlock);


	int totFile = 0;
	int* disk = malloc(sizeof(int)*numBlock);
	for(int i=0;i<numBlock;i++) {
		disk[i]=-1;
	}
	
	while(1)
	{
		printMenu();
		int choice;
		scanf("%d",&choice);
		if(choice == 1)
		{
			char* fName = malloc(sizeof(char)*1000);
			int iBlock,tBlock;
			printf("Enter File name,indexed block and total number of blocks in file\n");
			scanf("%s%d%d",fName,&iBlock,&tBlock);



			if(iBlock <0 || iBlock >=numBlock ||disk[iBlock]!=-1)
			{
				printf("Index Block is not empty or invalid index\n");
				continue;
			}
			
			int j=0;
			int cnt = 0;
			for(int i=0;i<tBlock;i++)
			{
				for(;j<numBlock;j++)
				{
					if(disk[j]==-1)
					{
						
						cnt++;
						j++;
						break;
					}
				}
			}


			if(cnt == tBlock)
			{

				int j=0;
				for(int i=0;i<tBlock;i++)
				{
					for(;j<numBlock;j++)
					{
						if(disk[j]==-1)
						{
							
							arr[totFile][i] = j;
							disk[j] = totFile;
							break;
						}
					}
				}
				
				// printf("\n");
				fileMap[totFile] = fName;
				mapIdx[totFile] = iBlock;
				sz[totFile]=tBlock;
				totFile++;
			}
			else
			{
				
				printf("Not Enough free Space remained\n");
			}
		}
		else if(choice == 2)
		{
			printf("File name 		Index Block      Block Stored\n");
			for(int i=0;i<totFile;i++)
			{
				printf("%9s 		%11d      ",fileMap[i],mapIdx[i]);
				for(int j=0;j<sz[i];j++)
					printf("%d ",arr[i][j]);
				printf("\n");
			}
		}
		else if(choice == 3)
		{
			break;
		}
		else
		{
			printf("Invalid Input\n");
		}
	}
}