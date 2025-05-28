#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* sleep_sort(void* arg) {
    int val = *(int*)arg;
    sleep(val);
    printf("%d ", val);
    return NULL;
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    pthread_t threads[n];
    
    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, sleep_sort, &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\n");
    return 0;
}
