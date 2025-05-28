#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Добавлено для strtok
#include <math.h>    // Добавлено для pow

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    if (matrix == NULL) return NULL;

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double **)malloc(rows * sizeof(double *));
    if (matrix->data == NULL) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
        if (matrix->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void free_matrix(Matrix *matrix) {
    if (matrix == NULL) return;
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

Matrix *read_matrix_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int rows = 0, cols = 0;
    char line[1024];

    // First pass to determine dimensions
    while (fgets(line, sizeof(line), file) != NULL) {
        rows++;
        char *token = strtok(line, " \t\n");
        int current_cols = 0;
        while (token != NULL) {
            current_cols++;
            token = strtok(NULL, " \t\n");
        }
        if (rows == 1) {
            cols = current_cols;
        } else if (current_cols != cols) {
            printf("Inconsistent number of columns in row %d\n", rows);
            fclose(file);
            return NULL;
        }
    }

    if (rows == 0 || cols == 0) {
        fclose(file);
        return NULL;
    }

    // Rewind file for second pass to read data
    rewind(file);

    Matrix *matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        if (fgets(line, sizeof(line), file) != NULL) {
            char *token = strtok(line, " \t\n");
            for (int j = 0; j < cols && token != NULL; j++) {
                matrix->data[i][j] = atof(token);
                token = strtok(NULL, " \t\n");
            }
        }
    }

    fclose(file);
    return matrix;
}

void print_matrix(const Matrix *matrix) {
    if (matrix == NULL) return;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%8.4f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *create_submatrix(const Matrix *matrix, int exclude_row, int exclude_col) {
    if (matrix == NULL || matrix->rows <= 1 || matrix->cols <= 1) return NULL;

    Matrix *submatrix = create_matrix(matrix->rows - 1, matrix->cols - 1);
    if (submatrix == NULL) return NULL;

    int sub_i = 0;
    for (int i = 0; i < matrix->rows; i++) {
        if (i == exclude_row) continue;
        int sub_j = 0;
        for (int j = 0; j < matrix->cols; j++) {
            if (j == exclude_col) continue;
            submatrix->data[sub_i][sub_j] = matrix->data[i][j];
            sub_j++;
        }
        sub_i++;
    }

    return submatrix;
}

double determinant(const Matrix *matrix) {
    if (matrix == NULL || matrix->rows != matrix->cols) {
        return NAN;
    }

    if (matrix->rows == 1) {
        return matrix->data[0][0];
    }

    if (matrix->rows == 2) {
        return matrix->data[0][0] * matrix->data[1][1] - 
               matrix->data[0][1] * matrix->data[1][0];
    }

    double det = 0;
    for (int j = 0; j < matrix->cols; j++) {
        Matrix *submatrix = create_submatrix(matrix, 0, j);
        if (submatrix == NULL) {
            return NAN;
        }
        double sub_det = determinant(submatrix);
        free_matrix(submatrix);
        det += matrix->data[0][j] * pow(-1, j) * sub_det;
    }

    return det;
}

Matrix *transpose_matrix(const Matrix *matrix) {
    if (matrix == NULL) return NULL;

    Matrix *transposed = create_matrix(matrix->cols, matrix->rows);
    if (transposed == NULL) return NULL;

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            transposed->data[j][i] = matrix->data[i][j];
        }
    }

    return transposed;
}

Matrix *cofactor_matrix(const Matrix *matrix) {
    if (matrix == NULL || matrix->rows != matrix->cols) return NULL;

    Matrix *cofactor = create_matrix(matrix->rows, matrix->cols);
    if (cofactor == NULL) return NULL;

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            Matrix *submatrix = create_submatrix(matrix, i, j);
            if (submatrix == NULL) {
                free_matrix(cofactor);
                return NULL;
            }
            double sub_det = determinant(submatrix);
            free_matrix(submatrix);
            cofactor->data[i][j] = pow(-1, i + j) * sub_det;
        }
    }

    return cofactor;
}

Matrix *inverse_matrix(const Matrix *matrix) {
    if (matrix == NULL || matrix->rows != matrix->cols) return NULL;

    double det = determinant(matrix);
    if (det == 0) return NULL;

    Matrix *cofactor = cofactor_matrix(matrix);
    if (cofactor == NULL) return NULL;

    Matrix *adjugate = transpose_matrix(cofactor);
    free_matrix(cofactor);
    if (adjugate == NULL) return NULL;

    Matrix *inverse = create_matrix(matrix->rows, matrix->cols);
    if (inverse == NULL) {
        free_matrix(adjugate);
        return NULL;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            inverse->data[i][j] = adjugate->data[i][j] / det;
        }
    }

    free_matrix(adjugate);
    return inverse;
}

Matrix *multiply_matrices(const Matrix *a, const Matrix *b) {
    if (a == NULL || b == NULL || a->cols != b->rows) return NULL;

    Matrix *result = create_matrix(a->rows, b->cols);
    if (result == NULL) return NULL;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}
