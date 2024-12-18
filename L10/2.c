#include <stdio.h>
#include <stdlib.h>

void ucitaj(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void ispisi(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void pomnozi(int **mat1, int m1, int n1, int **mat2, int m2, int n2, int **rez)
{
    if (n1 != m2)
    {
        printf("Matrice nisu kompatibilne za mnozenje.\n");
        return;
    }

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            rez[i][j] = 0;
            for (int k = 0; k < n1; k++)
            {
                rez[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main(void)
{
    int m1, n1, m2, n2;
    do
    {
        printf("m1 = ");
        scanf("%d", &m1);
        printf("n1 = ");
        scanf("%d", &n1);
        printf("m2 = ");
        scanf("%d", &m2);
        printf("n2 = ");
        scanf("%d", &n2);
    } while (n1 != m2 ? printf("Matrice nisu kompatibilne za mnozenje.\n") : 0);

    int **mat1 = malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++)
    {
        mat1[i] = malloc(n1 * sizeof(int));
    }

    int **mat2 = malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++)
    {
        mat2[i] = malloc(n2 * sizeof(int));
    }

    int **res = malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++)
    {
        res[i] = malloc(n2 * sizeof(int));
    }

    ucitaj(mat1, m1, n1);
    ucitaj(mat2, m2, n2);

    pomnozi(mat1, m1, n1, mat2, m2, n2, res);

    printf("\n");
    printf("Rezultantna matrica:\n");

    ispisi(res, m1, n2);

    for (int i = 0; i < m1; i++)
    {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < m2; i++)
    {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < m1; i++)
    {
        free(res[i]);
    }
    free(res);

    return 0;
}