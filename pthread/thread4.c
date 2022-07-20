#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_barrier_t barrier;


void* thread_body_1(void* arg){
    printf("A\n");
    pthread_barrier_wait(&barrier);
    return NULL;
}


void* thread_body_2(void* arg){
    pthread_barrier_wait(&barrier);
    printf("B\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_barrier_init(&barrier, NULL, 2);
    pthread_t thread1;
    pthread_t thread2;

    int res1 = pthread_create(&thread1, NULL, thread_body_1, NULL);
    int res2 = pthread_create(&thread2, NULL, thread_body_2, NULL);

    if(res1 || res2){
        printf("Не могу создать поток");
        exit(1);
    }

    res1 = pthread_join(thread1, NULL);
    res2 = pthread_join(thread2, NULL);

    if(res1 || res2){
        printf("Не могу присоединить поток");
        exit(2);
    }

    pthread_barrier_destroy(&barrier);

    return 0;
}
