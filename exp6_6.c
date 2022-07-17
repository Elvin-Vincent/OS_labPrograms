#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(int argc, char *argv[])
{
    char buff[200];
    DIR *dirp;
    printf("Enter the directory: ");
    scanf("%s", buff);
    if((dirp= opendir(buff)) == 0)
    {
        printf("Error");
        exit(0);
    }
    while(dptr= readdir(dirp))
        printf("%s\n", dptr->d_name);
    closedir(dirp);
}