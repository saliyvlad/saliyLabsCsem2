#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix *create_matrix(int rows, int cols);
void free_matrix(Matrix *matrix);
Matrix *read_matrix_from_file(const char *filename);
void print_matrix(const Matrix *matrix);
double determinant(const Matrix *matrix);
Matrix *inverse_matrix(const Matrix *matrix);
Matrix *multiply_matrices(const Matrix *a, const Matrix *b);

#endif // MATRIX_H
