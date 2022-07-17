#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid, status;
    char *args[]={"ls", "-l", 0}; //terminal command, argument of command, return exit value
    printf("Parent process\n");
    pid= fork();
    if(pid == 0)
    {
        printf("Child process\n");
        execv("/bin/ls", args);
    }
    else
    {
        wait(&status);
        printf("Parent process\n");
        exit(0);
    }
}