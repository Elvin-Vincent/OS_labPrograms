#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("PID: %d\n", fork());
}