#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Дочерний поток: строка %d\n", i+1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);  // Ожидание завершения дочернего потока
    
    for (int i = 0; i < 5; i++) {
        printf("Родительский поток: строка %d\n", i+1);
    }
    
    return 0;
}
