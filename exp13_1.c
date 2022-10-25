// FCFS Disk Scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inihead, n, totheadmov= 0, i;
    printf("No. of Requests: ");
    scanf("%d", &n);
    
    int rq[n];
    printf("Request sequence:\n");
    for(i= 0; i< n; i++)
        scanf("%d", &rq[i]);

    printf("Initial head position: ");
    scanf("%d", &inihead);

    for(i= 0; i< n; i++)
    {
        totheadmov += abs(rq[i]- inihead);
        inihead= rq[i];
    }
    printf("Total head movement = %d\n", totheadmov);
    return 0;
}
