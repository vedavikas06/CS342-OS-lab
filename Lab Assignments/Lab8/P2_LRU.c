//gcc p2.c
//./a.out < pages.txt


#include<stdio.h>
 
int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main()
{
    int no_of_frames;
    while(scanf("%d", &no_of_frames) != EOF){
    int  no_of_pages, frames[100], pages[100], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    
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
        
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }   
        }
        
        if(flag2 == 0){
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j]!=-1)
                hist[j][i]= frames[j];
            else
                 hist[j][i]= 0;
        }
    }

    printf("\n--------------------------------------------------------\n");
    for(int i=0;i<no_of_frames;i++){

        for(int j =0;j<no_of_pages;j++){
                printf("%d ", hist[i][j]);
            }

        printf("\n");       
    }

    printf("\nUsing %d frames, the reference string yielded:\nScheme          #Faults\n",no_of_frames);

    printf("LRU          %d\n\n",faults);
    

    }
    



    
    return 0;
}
