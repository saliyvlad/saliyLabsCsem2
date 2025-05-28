#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Используется: %s <matrix_file>\n", argv[0]);
        return 1;
    }

    Matrix *matrix = read_matrix_from_file(argv[1]);
    if (matrix == NULL) {
        printf("Ошибка чтения матрицы из файла\n");
        return 1;
    }

    if (matrix->rows != matrix->cols) {
        printf("Матрицу невозможно преобразовать в обратную\n");
        free_matrix(matrix);
        return 1;
    }

    double det = determinant(matrix);
    if (det == 0) {
        printf("Матрица единичная (определитель равен 0), обратной не существует\n");
        free_matrix(matrix);
        return 1;
    }

    Matrix *inverse = inverse_matrix(matrix);
    if (inverse == NULL) {
        printf("Ошибка вывода матрицы\n");
        free_matrix(matrix);
        return 1;
    }

    printf("Оригинальная матрица:\n");
    print_matrix(matrix);

    printf("\nОбратная матрица:\n");
    print_matrix(inverse);

    // Verification: multiply original by inverse should give identity matrix
    Matrix *identity = multiply_matrices(matrix, inverse);
    if (identity != NULL) {
        printf("\nПроверка (оригинальная * обратная):\n");
        print_matrix(identity);
        free_matrix(identity);
    }

    free_matrix(matrix);
    free_matrix(inverse);

    return 0;
}
