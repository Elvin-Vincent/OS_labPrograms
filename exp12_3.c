#include <stdio.h>

void print(int frameno, int frame[])
{
    int j;
    for(j= 0; j< frameno; j++)
    printf("%d\t    ", frame[j]);
    printf("\n");
}
 
int main()
{
    int i, j, n, page[50], frameno, frame[10], move= 0, flag, count= 0, count1[10]= {0}, repindex, leastcount;
    printf("\nEnter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference numbers\n");
    for(i= 0; i< n; i++)
    scanf("%d", &page[i]);
    printf("Enter the number of frames\n");
    scanf("%d", &frameno);
    for(i= 0; i< frameno; i++)
    frame[i]= -1;
    printf("\nPage   Reference   String   Frames\n");
    for(i= 0; i< n; i++)
    {
        printf("%d\t", page[i]);
        flag= 0;
        for(j= 0; j< frameno; j++)
        {
            if(page[i]== frame[j])
            {
                flag= 1;
                count1[j]++;
                printf("No replacement\n");
                break;
            }
        }
        if(flag== 0 && count< frameno)
        {
            frame[move]= page[i];
            count1[move]= 1;
            move= (move+ 1)% frameno;
            count++;
            print(frameno, frame);
        }
        else if(flag== 0)
        {
            repindex= 0;
            leastcount= count1[0];
            for(j= 1; j< frameno; j++)
            {
                if(count1[j]< leastcount)
                {
                    repindex= j;
                    leastcount= count1[j];
                }
            }
            frame[repindex]= page[i];
            count1[repindex]= 1;
            count++;
            print(frameno, frame);
        }
    }
    printf("\nNumber of page faults is %d\n", count);
    return 0;
}
