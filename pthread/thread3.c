#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool_t;

typedef struct {
    bool_t done;
    // мьютекс для защиты критического участка
    pthread_mutex_t mtx;
    // улованая переменная для синхронизации потоков
    pthread_cond_t cv;
} shared_state_t;

void shared_state_init(shared_state_t *shared_state_t){
    shared_state_t->done = FALSE;
    pthread_mutex_init(&shared_state_t->mtx, NULL);
    pthread_cond_init(&shared_state_t->cv, NULL);
}

void shared_state_destroy(shared_state_t *shared_state_t){
    pthread_mutex_destroy(&shared_state_t->mtx);
    pthread_cond_destroy(&shared_state_t->cv);
}

void* thread_body_1(void* arg){
    shared_state_t* ss = (shared_state_t*) arg;
    pthread_mutex_lock(&ss->mtx);
    printf("A\n");
    ss->done = TRUE;
    pthread_cond_signal(&ss->cv);
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}


void* thread_body_2(void* arg){
    shared_state_t* ss = (shared_state_t*) arg;
    pthread_mutex_lock(&ss->mtx);
    while (!ss->done)
    {
        pthread_cond_wait(&ss->cv, &ss->mtx);
    }
    printf("B\n");
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}

int main(int argc, char const *argv[])
{
    shared_state_t shared_state;
    shared_state_init(&shared_state);

    pthread_t thread1;
    pthread_t thread2;

    int res1 = pthread_create(&thread1, NULL, thread_body_1, &shared_state);
    int res2 = pthread_create(&thread2, NULL, thread_body_2, &shared_state);

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

    shared_state_destroy(&shared_state);

    return 0;
}
