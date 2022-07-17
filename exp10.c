// bankers algorithm

#include<stdio.h>
int main()
{
    int p, r, i, j, k, flag, count= 0;
    printf("Enter the no. of processes: ");
    scanf("%d", &p);
    printf("Enter the no. of resources: ");
    scanf("%d", &r);
    int alloc[p][r], max[p][r], need[p][r]; 
    int avail[r], finish[p], safe[p];   

    printf("Enter the Allocation:\n");     //Allocation matrix
    for(i= 0; i< p; i++)
    {
        printf("Process P%d:\n", i);
        for(j= 0; j< r; j++)
            scanf("%d", &alloc[i][j]);
    }
    
    printf("\nEnter the Max resources:\n");  //Max matrx
    for(i= 0; i< p; i++)
    {
        printf("Process %d:\n", i);
        for(j= 0; j< r; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\nNeed matrix:\n");              //Need matrx
    for(i= 0; i< p; i++)
    {
        printf("Process %d:\t", i);
        for(j= 0; j< r; j++)
        {
            need[i][j]= max[i][j]- alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter Available resources:\n");   //Available array for resources
    for(j= 0; j< r; j++)
        scanf("%d", &avail[j]);

    for(i= 0; i< p; i++)           //initializing all finish[i]= false  
        finish[i]= 0;
    
    for(k= 0; k< p; k++)           // this loop does the whole comparison process again and again for p times
    {
        for(i= 0; i< p; i++)   
        {
            if(finish[i] == 0)              //checks if the process is already used or not
            {   
                for(j= 0; j< r; j++)        //check loop
                {
                    if(need[i][j] <= avail[j])
                    {
                        flag= 1;
                        continue;
                    }
                    else
                    {
                        flag= 0;
                        break;
                    }
                }              
                if(flag == 1)             //updation condition
                {
                    safe[count]= i;
                    for(j= 0; j< r; j++)
                        avail[j] += alloc[i][j];
                    finish[i]= 1;
                    count++;
                }
            }
        }
    }

    for(i= 0; i< p; i++)
    {
        if(finish[i] == 0)
        {
            printf("\nThe system is not in safe state\n");
            return 0;
        }
    }

    printf("The safe sequence is:\n");
    for(i= 0; i< p; i++)
        printf("P%d\t", safe[i]);
    printf("\nThe system is in safe state\n");
}





// #include<stdio.h>
// int main()
// {
//     int p, r, i, j, flag, count= 0, lcount= 0;
//     printf("Enter the no. of processes: ");
//     scanf("%d", &p);
//     printf("Enter the no. of resources: ");
//     scanf("%d", &r);
//     int alloc[p][r], max[p][r], need[p][r]; 
//     int avail[r], finish[p], safe[p];   

//     printf("Enter the Allocation:\n");     //Allocation matrix
//     for(i= 0; i< p; i++)
//     {
//         printf("Process P%d:\n", i);
//         for(j= 0; j< r; j++)
//             scanf("%d", &alloc[i][j]);
//     }
    
//     printf("\nEnter the Max resources:\n");  //Max matrx
//     for(i= 0; i< p; i++)
//     {
//         printf("Process %d:\n", i);
//         for(j= 0; j< r; j++)
//             scanf("%d", &max[i][j]);
//     }

//     printf("\nNeed matrix:\n");              //Need matrx
//     for(i= 0; i< p; i++)
//     {
//         printf("Process %d:\t", i);
//         for(j= 0; j< r; j++)
//         {
//             need[i][j]= max[i][j]- alloc[i][j];
//             printf("%d\t", need[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nEnter Available resources:\n");   //Available array for resources
//     for(j= 0; j< r; j++)
//         scanf("%d", &avail[j]);

//     for(i= 0; i< p; i++)           //initializing all finish[i]= false  
//         finish[i]= 0;
 
//     for(i= 0; count< p; i= (i+ 1)% p)   // i iterates in a circular way. count increments only when the process is used
//     {
//         if(finish[i] == 0)              //checks if the process is already used or not
//         {   
//             for(j= 0; j< r; j++)        //check loop
//             {
//                 if(need[i][j] <= avail[j])
//                     flag= 1;
//                 else
//                 {
//                     flag= 0;
//                     break;
//                 }
//             }              
//             if(flag == 1)             //updation condition
//             {
//                 safe[count]= i;
//                 for(j= 0; j< r; j++)
//                     avail[j] += alloc[i][j];
//                 finish[i]= 1;
//                 count++;
//             }
//         }
//     }

//     for(i= 0; i< p; i++)
//     {
//         if(finish[i] == 0)
//         {
//             printf("\nThe system is not in safe state\n");
//             return 0;
//         }
//     }
    
//     printf("The safe sequence is:\n");
//     for(i= 0; i< p; i++)
//         printf("P%d\t", safe[i]);
//     printf("\nThe system is in safe state\n");
// }