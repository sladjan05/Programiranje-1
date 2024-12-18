#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double coef;
    int deg;
} CLAN;

typedef struct
{
    int count;
    CLAN *terms;
} POLINOM;

POLINOM citaj(void)
{
    POLINOM p;

    int n;
    do
    {
        printf("Unesite stepen polinoma: ");
        scanf("%d", &n);
    } while (n < 0 ? printf("Stepen polinoma mora biti nenegativan broj.\n") : n >= 100 ? printf("Stepen polinoma mora biti manji od 100.\n")
                                                                                        : 0);

    p.count = 0;
    p.terms = malloc(n * sizeof(CLAN));

    for (int i = 0; i < n; i++)
    {
        printf("A_%d * x^%d -> A_%d = ", i, i, i);

        double coef;
        scanf("%lf", &coef);

        if (coef)
        {
            p.terms[p.count].deg = i;
            p.terms[p.count].coef = coef;
            p.count++;
        }
    }

    realloc(p.terms, p.count * sizeof(CLAN));

    return p;
}

CLAN *nadji_clan(POLINOM p, int deg)
{
    for (int i = 0; i < p.count; i++)
    {
        if (p.terms[i].deg == deg)
        {
            return &p.terms[i];
        }
    }

    return NULL;
}

POLINOM saberi(POLINOM p1, POLINOM p2)
{
    POLINOM p;

    p.count = 0;
    p.terms = malloc((p1.count + p2.count) * sizeof(CLAN));

    for (int i = 0; i < p1.count; i++)
    {
        p.terms[i] = p1.terms[i];
        p.count++;
    }

    for (int i = 0; i < p2.count; i++)
    {
        CLAN *clan = nadji_clan(p, p2.terms[i].deg);

        if (clan)
        {
            clan->coef += p2.terms[i].coef;
        }
        else
        {
            p.terms[p.count++] = p2.terms[i];
        }
    }

    realloc(p.terms, p.count * sizeof(CLAN));

    return p;
}

POLINOM pomnozi(POLINOM p1, POLINOM p2)
{
    POLINOM p;

    p.count = 0;
    p.terms = malloc(p1.count * p2.count * sizeof(CLAN));

    for (int i = 0; i < p1.count; i++)
    {
        for (int j = 0; j < p2.count; j++)
        {
            double coef = p1.terms[i].coef * p2.terms[j].coef;
            int deg = p1.terms[i].deg + p2.terms[j].deg;

            CLAN *clan = nadji_clan(p, deg);

            if (clan)
            {
                clan->coef += coef;
            }
            else
            {
                p.terms[p.count].coef = coef;
                p.terms[p.count].deg = deg;
                p.count++;
            }
        }
    }

    realloc(p.terms, p.count * sizeof(CLAN));

    return p;
}

void ispisi(POLINOM p)
{
    for (int i = 0; i < p.count; i++)
    {
        double coef = p.terms[i].coef;
        int deg = p.terms[i].deg;

        switch (deg)
        {
        case 0:
            printf("%.3lf ", coef);
            break;
        case 1:
            printf("%.3lf * x ", coef);
            break;
        default:
            printf("%.3lf * x^%d ", p.terms[i].coef, p.terms[i].deg);
            break;
        }

        if (i < p.count - 1)
        {
            printf("+ ");
        }
    }

    printf("\n");
}

int main(void)
{
    POLINOM p1 = citaj();
    POLINOM p2 = citaj();

    POLINOM p3 = saberi(p1, p2);
    POLINOM p4 = pomnozi(p1, p2);

    printf("Zbir: ");
    ispisi(p3);

    printf("Proizvod: ");
    ispisi(p4);

    free(p1.terms);
    free(p2.terms);
    free(p3.terms);
    free(p4.terms);

    return 0;
}