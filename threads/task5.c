#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void* arg) {
    printf("Очистка: поток завершается\n");
}

void* thread_func(void* arg) {
    pthread_cleanup_push(cleanup, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Дочерний поток: строка %d\n", i+1);
        sleep(1);
    }
    
    pthread_cleanup_pop(1);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    
    sleep(2);
    pthread_cancel(thread);
    
    pthread_join(thread, NULL);
    return 0;
}
