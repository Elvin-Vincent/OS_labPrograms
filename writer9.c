#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    key= 1234;

    // shmget creates a shared memory segment and returns an identifier of the memory
    // 0666 is the permission code for read and write operation for everyone
    shmid= shmget(key, 1024, 0666|IPC_CREAT);  //key,size,shmflg

    // shmat attaches shared memory segment to process and returns the starting address of newly created shared memory segment
    // shmaddr specifies which address space of calling function should we use for attaching the shared memory segment
    // but it is set to zero and OS will automatically choose the address
    // finally str becomes an array with many addresses; ie, the shared memory space addresses
    str= (char *)shmat(shmid, NULL, 0);  //shmid,shmaddr,shmflg

    printf("Write Data: ");
    // gets function reads string and stores the string into the address pointed by str
    // but since str is like an array, we mention gets(str) instead of get(*s)
    // gets(str);
    fgets(str, 1024, stdin);

    printf("Data written in memory: %s\n", str);

    // // to show that str became like an array
    // printf("Index 0: %c\n", str[2]); 

    //detach process from shared memory
    shmdt(str);

    return 0;
}