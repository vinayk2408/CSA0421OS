/* DINING PHILOSOPHERS (5 Philosophers, Semaphores + Threads) */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t forks[5];

void* philosopher(void* arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % 5;

    if (id == 4) {
        sem_wait(&forks[right]);
        sem_wait(&forks[left]);
    } else {
        sem_wait(&forks[left]);
        sem_wait(&forks[right]);
    }

    printf("Philosopher %d is eating\n", id);
    sleep(1);
    printf("Philosopher %d finished eating\n", id);

    sem_post(&forks[left]);
    sem_post(&forks[right]);

    return NULL;
}

int main() {
    pthread_t tid[5];
    int id[5];

    for (int i = 0; i < 5; i++)
        sem_init(&forks[i], 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    for (int i = 0; i < 5; i++)
        sem_destroy(&forks[i]);

    return 0;
}
