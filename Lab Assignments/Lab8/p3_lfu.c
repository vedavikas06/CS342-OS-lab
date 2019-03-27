//gcc p2.c
//./a.out < pages.txt


#include<stdio.h>
// #define SIZE 3
// int full=0;//To check whether all frames are filled
// int a[21],n;//To take the input
// int frame[SIZE];
// int ctr[SIZE]={0};//Counter to know the frequency, intially all have zero frequency of use

int repptr;
// int count=0;
// int display()
// {int i;
// printf("\nThe elements in the frame are\n");
// for(i=0;i<full;i++)
// printf("%d\n",frame[i]);   
// }
int Longestopt(int no_of_frames,int ctr[],int time[],int frame[])
{
    int i,min;
    min=0;
    for(i=1;i<no_of_frames;i++){//The page with least frequency is selected as victim
        if(ctr[frame[min]]>ctr[frame[i]]){
            min=i;
            repptr=min;
        }else if(ctr[frame[min]] == ctr[frame[i]] && time[frame[min]] > time[frame[i]]){
            min=i;
            repptr=min;
        }

    }

    // for(int i=1;i<20;i++){
    //     printf("%d ",ctr[i]);
    // }
    // printf("\n");

    return min;
}
int Pagerep(int ele,int frame[],int ctr[],int no_of_frames,int *full,int cnt,int time[])
{
     int temp;
     repptr=Longestopt(no_of_frames,ctr,time,frame);//The victim page is selected with the help of a function
     temp=frame[repptr];
     frame[repptr]=ele;
     time[ele] = cnt;
     ctr[ele]+=1;//A new page is brought, hence it's counter is set to 1
     

     return temp;   
}
int Pagefault(int ele,int frame[],int ctr[],int no_of_frames,int *full,int cnt,int time[])
{
    if(*full!=no_of_frames)
    {
        ctr[ele]++;//The counters will increase initially for all frames till they are full
        frame[*full]=ele;
        time[ele] = cnt;
        *full = *full +1;
    }
    else{
        //printf("The page replaced is %d",Pagerep(ele,frame,ctr,no_of_frames,full));
         Pagerep(ele,frame,ctr,no_of_frames,full,cnt,time);
    }

    return 0;
}
int Search(int ele,int *full,int frame[],int ctr[],int cnt,int time[])
{
    int i,flag;
    flag=0;
    if(*full!=0)
    {
        for(i=0;i<*full;i++){
            if(ele==frame[i])
            {   
                flag=1;ctr[frame[i]]++;//Whenever a reference is made the counter is incremented
                time[frame[i]] = cnt;
                break;
            }
        }
    }
 return flag;   
}
int main()
{

    // int i;
    // FILE *fp;
    // fp=fopen("Input.txt","r");
    // printf("The number of elements in the reference string are :");
    // fscanf(fp,"%d",&n);
    // printf("%d",n);
    // for(i=0;i<n;i++)
    // fscanf(fp,"%d",&a[i]);
    // printf("\nThe elements present in the string are\n");
    // for(i=0;i<n;i++)
    // printf("%d  ",a[i]);
    // printf("\n\n");
    // for(i=0;i<n;i++)
    // {
    //     if(Search(a[i])!=1)
    //     {
    //         Pagefault(a[i]);
    //         display();
    //         count++;
    //     }
        
    // }
    //     printf("\nThe number of page faults are %d\n",count);
    //     getche();





    int no_of_frames;
    while(scanf("%d", &no_of_frames) != EOF){
    int  no_of_pages, pages[100], counter = 0, time[100], i, j, pos, faults = 0;

    
    int st=0;
    while(1){
        int a;
        scanf("%d",&a);
        if(a!=-1){
            pages[st] = a;
            printf("%d ", pages[st]);

            st++;


        }else{
            break;
        }

    }
    no_of_pages = st;
    int hist[no_of_frames][no_of_pages];


    printf(" size  %d ", no_of_pages);

    for(int i=0;i<no_of_frames;i++){

        for(int j =0;j<no_of_pages;j++){
                hist[i][j] = 0;
            }   
    }
        
    
    int tot =0;
    int *full= &tot;//To check whether all frames are filled
    int frame[no_of_frames];
    int ctr[101];
    // memset(ctr,0,(no_of_frames+1)*sizeof(ctr[0]));
    for (int j = 0; j <= no_of_frames; ++j)
    {
        
        frame[j] =0;
    }
    for(int j =1;j<100;j++){
        time[j] = -1;
        ctr[j] = 0;
    }
    int repptr;
    //int count=0;

    for(i = 0; i < no_of_pages; ++i){
       

        if(Search(pages[i],full,frame,ctr,i,time)!=1)
        {
            Pagefault(pages[i],frame,ctr,no_of_frames,full,i,time);
            // display();
            faults++;
        }
        
        
        for(j = 0; j < no_of_frames; ++j){
            if(frame[j]!=-1)
                hist[j][i]= frame[j];
            else
                 hist[j][i]= 0;
        }

        //printf("full : %d\n",*full);
    }

    printf("\n--------------------------------------------------------\n");
    for(int i=0;i<no_of_frames;i++){

        for(int j =0;j<no_of_pages;j++){
                printf("%d ", hist[i][j]);
            }

        printf("\n");       
    }

    printf("\nUsing %d frames, the reference string yielded:\nScheme          #Faults\n",no_of_frames);

    printf("LFU            %d\n\n",faults);
    

    }

    return 0;
    

}