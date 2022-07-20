#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t mtx;


void* thread_body_1(void* arg){
    int* shared_var = (int*) arg;
    
    pthread_mutex_lock(&mtx);
    (*shared_var)++;
    printf("%d\n", *shared_var);
    pthread_mutex_unlock(&mtx);
    
    return NULL;
}

void* thread_body_2(void* arg){
    int* shared_var = (int*) arg;
    
    pthread_mutex_lock(&mtx);
    *shared_var += 2;
    printf("%d\n", *shared_var);
    pthread_mutex_unlock(&mtx);

    return NULL;
}

int main(int argc, char const *argv[])
{
    int shared_var = 0;

    pthread_t thread1;
    pthread_t thread2;
    pthread_mutex_init(&mtx, NULL);

    int res1 = pthread_create(&thread1, NULL, thread_body_1, &shared_var);
    int res2 = pthread_create(&thread2, NULL, thread_body_2, &shared_var);

    if(res1 || res1){
        printf("Не могу создать поток");
        exit(1);
    }

    res1 = pthread_join(thread1, NULL);
    res2 = pthread_join(thread2, NULL);

    if(res1 || res1){
        printf("Не могу присоединить поток");
        exit(2);
    }

    pthread_mutex_destroy(&mtx);
    
    return 0;
}


