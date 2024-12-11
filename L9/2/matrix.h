#pragma once

typedef struct Matrix
{
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *mx_input();
Matrix *mx_add(const Matrix *a, const Matrix *b);
Matrix *mx_multiply(const Matrix *a, const Matrix *b);

void mx_print(const Matrix *mat);