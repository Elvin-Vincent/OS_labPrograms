// SCAN Disk Scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inihead, n, totheadmov= 0, i, totsize, dir, j, temp, index;
    printf("No. of Requests:");
    scanf("%d", &n);
    
    int rq[n];
    printf("Request sequence:\n");
    for(i= 0; i< n; i++)
        scanf("%d", &rq[i]);

    printf("Initial head position: ");
    scanf("%d", &inihead);

    printf("Total disk size: ");
    scanf("%d", &totsize);
    
    printf("Head movement direction (1:high & 0:low) : ");
    scanf("%d", &dir);

    // bubble sort
    for(i= 0; i< n; i++)
    {
        for(j= 0; j< n- i- 1; j++)
        {
            if(rq[j]> rq[j+ 1])
            {
                temp= rq[j];
                rq[j]= rq[j+ 1];
                rq[j+ 1]= temp;
            }
        }
    }

    for(i= 0; i< n; i++)
    {
        if(rq[i]> inihead)
        {
            index= i;
            break;
        }
    }

    // If graph is going low, reach the leftmost end of the disk size, then go till the highest given request 
    // If graph is going high, reach the rightmost end of the disk size, then go til the least given request
    if(dir == 1)
    {
        for(i= index; i< n; i++)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i]; 
        }
        // rightmost end
        totheadmov += abs((totsize- 1)- inihead);
        inihead= totsize- 1;
        // going low till given request
        for(i= index- 1; i>= 0; i--)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i];
        }
    }

    if(dir == 0)
    {
        for(i= index- 1; i>= 0; i--)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i]; 
        }
        // leftmost end
        totheadmov += abs(0- inihead);
        inihead= 0;
        // going high till given request
        for(i= index; i< n; i++)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i];
        }
    }
    printf("Total head movement = %d\n", totheadmov);
    return 0;
}
