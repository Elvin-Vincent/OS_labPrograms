#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    char path[10];
    struct stat *nfile;
    nfile= (struct stat *)malloc(sizeof(struct stat));
    printf("Enter the file name: ");
    scanf("%s", path);
    stat(path, nfile);
    printf("User ID: %d\n", nfile->st_uid);
    printf("Group ID: %d\n", nfile->st_gid);
    printf("Size: %ld\n", nfile->st_size);
    printf("Block size: %ld\n", nfile->st_blksize);
    printf("Mode: %d\n", nfile->st_mode);
    printf("No. of links: %ld\n", nfile->st_nlink);
    printf("Last access time: %ld\n", nfile->st_atime);
}