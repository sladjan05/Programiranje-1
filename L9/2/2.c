#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(void)
{
    Matrix *a = mx_input(), *b = mx_input();
    Matrix *sum = mx_add(a, b);
    Matrix *product = mx_multiply(a, b);

    if (sum == NULL)
    {
        printf("Matrice ne mogu biti sabrane.\n");
    }
    else
    {
        printf("Zbir matrica: \n");
        mx_print(sum);
    }

    if (product == NULL)
    {
        printf("Matrice ne mogu biti pomnozene.\n");
    }
    else
    {
        printf("Proizvod matrica: \n");
        mx_print(product);
    }

    return 0;
}