#include <stdio.h>

#define SIZE 3 // Размер массивов A и B

int main() {
    // 1. Создаем массивы A и B
    float A[SIZE * 2] = {1.0, 2.0, 3.0, -1.0, 4.0, 0.5}; // Пример значений для A
    float B[SIZE * 2] = {2.0, -3.0, 1.0, 2.5, 0.0, -4.0}; // Пример значений для B
    float C[SIZE * 2]; // Массив для хранения суммы

    // 2. Сложение A и B в C
    for (int i = 0; i < SIZE * 2; i++) {
        C[i] = A[i] + B[i];
    }

    // 3. Нахождение максимальной реальной части в A
    float max_real_A = A[0];
    int count_imag_B_negative = 0;

    for (int i = 0; i < SIZE; i++) {
        // Проверяем реальную часть
        if (A[i * 2] > max_real_A) {
            max_real_A = A[i * 2];
        }
        // Проверяем мнимую часть B
        if (B[i * 2 + 1] < 0) {
            count_imag_B_negative++;
        }
    }

    printf("Максимальная реальная часть массива A: %.2f\n", max_real_A);
    printf("Количество мнимых частей, которые меньше 0 в массиве B: %d\n", count_imag_B_negative);

    // 4. Вычисление среднего арифметического элементов массива C
    float sum_C = 0;
    for (int i = 0; i < SIZE * 2; i++) {
        sum_C += C[i];
    }
    float average_C = sum_C / (SIZE * 2);
    printf("Среднее арифметическое элементов массива C: %.2f\n", average_C);

    return 0;
}
#НА 5
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int is_perfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) sum += i;
    }
    return sum == num;
}

void process_array(int arr[], int size) {
    int last_prime_index = -1, first_perfect_index = -1;

    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i])) {
            last_prime_index = i;
        }
        if (first_perfect_index == -1 && is_perfect(arr[i])) {
            first_perfect_index = i;
        }
    }

    if (last_prime_index != -1 && first_perfect_index != -1) {
        int temp = arr[last_prime_index];
        arr[last_prime_index] = arr[first_perfect_index];
        arr[first_perfect_index] = temp;
    }

    // Удаление четных чисел
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--; // Проверяем текущую позицию снова
        }
    }

    // Вывод массива
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int X[] = {1, 2, 3, 4, 5, 6, 28}; // Пример массива
    int size = sizeof(X) / sizeof(X[0]);
    process_array(X, size);
    return 0;
}
