/* MULTITHREADING USING PTHREADS */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int id = *(int*)arg;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d: iteration %d\n", id, i);
        usleep(100000); // 0.1 sec
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter number of threads: ");
    scanf("%d", &n);

    pthread_t tid[n];
    int ids[n];

    for (int i = 0; i < n; i++) {
        ids[i] = i + 1;
        pthread_create(&tid[i], NULL, thread_func, &ids[i]);
    }

    for (int i = 0; i < n; i++)
        pthread_join(tid[i], NULL);

    printf("All threads finished.\n");
    return 0;
}
