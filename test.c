#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int is_ended = 0;

void *thread_func(void *arg)
{
    while (1) {
        int is_alive;
        /* Access the shared variable without any synchronization */
        is_alive = is_ended == 0;
        if (is_ended == 0)
            is_alive = 1;
        else
            is_alive = 0;
        if (!is_alive) {
            printf("Thread exiting\n");
            break;
        }
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    int i;

    /* Create a thread */
    pthread_create(&tid, NULL, thread_func, NULL);
    sleep(1);
    is_ended = 1;
    /* Wait for the thread to exit */
    pthread_join(tid, NULL);
}
