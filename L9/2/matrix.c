#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix *mx_input()
{
    Matrix *mat = malloc(sizeof(Matrix));
    do
    {
        printf("Unesite dimenzije matrice (n m): ");
        scanf("%d %d", &mat->rows, &mat->cols);
    } while (mat->rows < 1 || mat->cols < 1 ? printf("Dimenzije moraju biti pozitivne.\n") : (mat->rows > 10 || mat->cols > 10) ? printf("Dimenzije ne mogu biti vece od 10.\n")
                                                                                                                                : 0);

    mat->data = malloc(mat->rows * sizeof(int *));

    printf("Unesite elemente matrice: \n");
    for (int i = 0; i < mat->rows; i++)
    {
        mat->data[i] = malloc(mat->cols * sizeof(int));
        for (int j = 0; j < mat->cols; j++)
        {
            scanf("%d", &mat->data[i][j]);
        }
    }

    return mat;
}

Matrix *mx_add(const Matrix *a, const Matrix *b)
{
    if (a->rows != b->rows || a->cols != b->cols)
    {
        return NULL;
    }

    Matrix *result = malloc(sizeof(Matrix));

    result->rows = a->rows;
    result->cols = a->cols;
    result->data = malloc(result->rows * sizeof(int *));

    for (int i = 0; i < result->rows; i++)
    {
        result->data[i] = malloc(result->cols * sizeof(int));
        for (int j = 0; j < result->cols; j++)
        {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix *mx_multiply(const Matrix *a, const Matrix *b)
{
    if (a->cols != b->rows)
    {
        return NULL;
    }

    Matrix *result = malloc(sizeof(Matrix));

    result->rows = a->rows;
    result->cols = b->cols;
    result->data = malloc(result->rows * sizeof(int *));

    for (int i = 0; i < result->rows; i++)
    {
        result->data[i] = malloc(result->cols * sizeof(int));
        for (int j = 0; j < result->cols; j++)
        {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++)
            {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

void mx_print(const Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}