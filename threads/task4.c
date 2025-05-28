#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Дочерний поток: строка %d\n", i+1);
        sleep(1);  // Задержка между выводами
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    
    sleep(2);  // Ждем 2 секунды
    pthread_cancel(thread);  // Прерываем дочерний поток
    
    pthread_join(thread, NULL);
    return 0;
}
