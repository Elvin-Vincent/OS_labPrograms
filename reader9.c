#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *ptr;

    key= 1234;

    shmid= shmget(key, 1024, 0666|IPC_CREAT);
    ptr= (char *)shmat(shmid, NULL, 0);

    printf("Data read from memory: %s\n", ptr);

    //detach process from shared memory
    shmdt(ptr);

    // destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}