// priority

#include<stdio.h>
int main()
{
    int n, temp, i, j;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], tat[n], wt[n], pri[n], tottat= 0, totwt= 0;
    float avgtat, avgwt;
    for(i= 0; i< n; i++)
    {
        printf("Burst time:");
        scanf("%d", &bt[i]);
        printf("Priority:");
        scanf("%d", &pri[i]);
        p[i]= i;
    }
    for(i= 0; i< n; i++)
    {
        for(j= 0; j< n-i-1; j++)
        {
            if(pri[j] > pri[j+ 1])
            {
                temp= pri[j];
                pri[j]= pri[j+ 1];
                pri[j+ 1]= temp;

                temp= bt[j];
                bt[j]= bt[j+ 1];
                bt[j+ 1]= temp;

                temp= p[j];
                p[j]= p[j+ 1];
                p[j+ 1]= temp;
            }
        }
    }
    for(i= 0; i< n; i++)
    {
        // tat time 
        if(i == 0)
            tat[i]= bt[i];
        else
            tat[i]= tat[i- 1]+ bt[i];
        
        // total tat
        tottat += tat[i];
        
        // waiting time
        wt[i]= tat[i]- bt[i];

        // total wt
        totwt += wt[i];
    }

    avgtat= (float)tottat/ n;
    avgwt= (float)totwt/ n;

    printf("Process\tPrio\tBT\tTAT\tWT\n");
    for(i= 0; i< n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], pri[i], bt[i], tat[i], wt[i]);
    printf("\nAvg TAT: %f", avgtat);
    printf("\nAvg WT: %f\n", avgwt);
}