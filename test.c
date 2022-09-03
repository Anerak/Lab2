#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#define MAX 10
void *funcion1()
{
    printf("Thread: %d\n", pthread_self());
    pthread_exit(0);
}
int main()
{
    pthread_attr_t attr;
    pthread_t thid[MAX];
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for (int i = 0; i < MAX; i++)
    {
        pthread_create(&thid[i], &attr, funcion1, NULL);
    }
    /**
    printf("Start sleep\n");
    Sleep(10000);
    printf("End sleep\n");
    */
    return 0;
}