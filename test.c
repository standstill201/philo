#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    printf("Hello from the new thread!\n");
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_detach(thread);
	printf("!!!!!!!!!!!!!!!!!!\n");
    pthread_detach(thread);
    printf("Hello from the main thread!\n");
    sleep(1);
    return 0;
}