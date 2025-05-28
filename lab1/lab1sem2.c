#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define N 100

struct Student {
    int student_id;
    char name[64];
    int math;
    int physics;
    int informatics;
    float average_score;
};

// Функция addStudent адаптирована
struct Student addStudent(int id, const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    newStudent.student_id = id;
    strncpy(newStudent.name, name, sizeof(newStudent.name) - 1);
    newStudent.name[sizeof(newStudent.name) - 1] = '\0';
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.average_score = (float)(math + phy + inf) / 3.0f;
    return newStudent;
}

// Функция printStudentInfo адаптирована
void printStudentInfo(struct Student student) {
    printf("ID: %d\n", student.student_id);
    printf("Имя: %s\n", student.name);
    printf("Математика: %d\n", student.math);
    printf("Физика: %d\n", student.physics);
    printf("Информатика: %d\n", student.informatics);
    printf("Средний балл: %.2f\n", student.average_score);
    printf("----------------------\n");
}

// QuickSort адаптирована
void swap(struct Student* a, struct Student* b) {
    struct Student t = *a;
    *a = *b;
    *b = t;
}

int partition(struct Student arr[], int low, int high) {
    float pivot = arr[high].average_score;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].average_score > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    struct Student students[N];

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student %d", i + 1);
        students[i] = addStudent(i + 1, name, rand() % 101, rand() % 101, rand() % 101);
    }

    printf("Студенты до сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    struct timeval start, end;
    long seconds, microseconds;
    double elapsed;

    gettimeofday(&start, NULL);
    quickSort(students, 0, N - 1);
    gettimeofday(&end, NULL);

    seconds = (end.tv_sec - start.tv_sec);
    microseconds = ((end.tv_usec - start.tv_usec));
    elapsed = seconds + microseconds * 1e-6;

    printf("Время выполнения Quick Sort (N=%d): %.5f секунд\n", N, elapsed);
    printf("Размер данных (N=%d): %lu байт\n", N, sizeof(students));

    printf("\nСтуденты после сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    return 0;
}
void selectionSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Индекс минимального элемента
        for (int j = i + 1; j < n; j++) {
            if (arr[j].average_score < arr[min_idx].average_score) {
                min_idx = j; // Обновляем индекс минимального элемента
            }
        }
        // Меняем местами найденный минимальный элемент и текущий элемент
        struct Student temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}



void countingSort(struct Student arr[], int n) {
    struct Student output[n]; // Выходной массив
    int count[MAX_SCORE + 1] = {0}; // Массив для подсчета количества студентов по среднему баллу

    // Подсчет количества студентов для каждого среднего балла
    for (int i = 0; i < n; i++) {
        int score = (int)arr[i].average_score;
        count[score]++;
    }

    // Изменение count[i] так, чтобы он содержал фактические позиции студентов в выходном массиве
    for (int i = 1; i <= MAX_SCORE; i++) {
        count[i] += count[i - 1];
    }

    // Построение выходного массива
    for (int i = n - 1; i >= 0; i--) {
        int score = (int)arr[i].average_score;
        output[count[score] - 1] = arr[i]; // Поместить студента в правильное место
        count[score]--; // Уменьшаем количество
    }

    // Копирование отсортированных студентов обратно в оригинальный массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
