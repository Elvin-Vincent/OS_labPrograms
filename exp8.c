// producer consumer

#include<stdio.h>
#define N 4
// initially empty slots are 5. full slots are 0
int mutex= 1, empty= N, full= 0;
int item= 0, buff[N], i= 0;

int wait(int *s)
{
    --*s; //if we write s without *, then it will decrement the adderss of thet variable s. 
        //*s denotes pointes to the value contained in that address
}

int signal(int *s)
{
    ++*s;
}

void producer()
{
    wait(&empty);
    wait(&mutex);
    
    //Critical Section
    item++;
    i++;
    buff[i]= item;
    printf("Producer produces item: %d\n", buff[i]);

    signal(&mutex);
    signal(&full);
}

void consumer()
{
    wait(&full);
    wait(&mutex);

    // Critical Section
    printf("Consumer consumes item: %d\n", buff[i]);
    i--;
    item--;

    signal(&mutex);
    signal(&empty);
}

int main()
{
    int op;
    printf("1. Producer\n2. Consumer\n3. Exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: if((mutex == 1) && (empty != 0)) //atleat one empty slot
                        producer();
                    else
                        printf("Buffer is full !!!\n");
                    break;
            case 2: if((mutex == 1) && (full != 0))  //atleat one full slot
                        consumer();
                    else
                        printf("Buffer is empty !!!\n");
                    break;
            case 3: return 0;
        }
    }
}






// // without pointers

// #include<stdio.h>
// #define N 5
// // initially empty slots are 5. full slots are 0
// int mutex= 1, empty= N, full= 0;
// int item= 0, buff[N], i= 0;

// int wait(int s)
// {
//     return --s;
// }

// int signal(int s)
// {
//     return ++s;
// }

// void producer()
// {
//     empty= wait(empty);
//     mutex= wait(mutex);
    
//     //Critical Section
//     item++;
//     i++;
//     buff[i]= item;
//     printf("Producer produces item: %d\n", buff[i]);

//     mutex= signal(mutex);
//     full= signal(full);
// }

// void consumer()
// {
//     full= wait(full);
//     mutex= wait(mutex);

//     // Critical Section
//     printf("Consumer consumes item: %d\n", buff[i]);
//     i--;
//     item--;

//     mutex= signal(mutex);
//     empty= signal(empty);
// }

// int main()
// {
//     int op;
//     printf("1. Producer\n2. Consumer\n3. Exit\n");
//     while(1)
//     {
//         printf("Enter choice: ");
//         scanf("%d", &op);
//         switch(op)
//         {
//             case 1: if((mutex == 1) && (empty != 0)) //atleat one empty slot
//                         producer();
//                     else
//                         printf("Buffer is full !!!\n");
//                     break;
//             case 2: if((mutex == 1) && (full != 0))  //atleat one full slot
//                         consumer();
//                     else
//                         printf("Buffer is empty !!!\n");
//                     break;
//             case 3: return 0;
//         }
//     }
// }