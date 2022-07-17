#include<stdio.h>
#include<unistd.h>
#include<stdlib.h> 
#include<sys/wait.h>
int main()
{
    int pid, status, exitch;
    if((pid= fork())== -1) //child process created here and checks for error
    {
        perror("Error\n");
        exit(0);
    }
    if(pid == 0) /*Currently parent process is running even though child is created. The child is lagging behind the parent. PID of parent process is always grater than 0*/
    {
        sleep(5);
        printf("Child process\n");
        exit(0);
    }
    else
    {
        printf("Parent process\n");
        if((exitch= wait(&status)) == -1) /*Here the parent process waits. During this wait time, the child process runs from begining*/
        {
            perror("During wait()");
            exit(0);
        }
        printf("Parent process exiting\n");
    }
}