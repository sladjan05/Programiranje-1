#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y)          \
    {                       \
        typeof(x) temp = x; \
        x = y;              \
        y = temp;           \
    }

typedef struct
{
    char naziv[30 + 1];
    int postignuti_golovi;
    int primljeni_golovi;
    int bodovi;
} TIM;

void ucitaj(TIM *tim)
{
    printf("Unesite naziv tima: ");
    gets(tim->naziv);

    do
    {
        printf("Unesite postignute golove: ");
        scanf("%d", &tim->postignuti_golovi);
    } while (tim->postignuti_golovi < 0 && printf("Broj golova mora biti nenegativan.\n"));

    do
    {
        printf("Unesite primljene golove: ");
        scanf("%d", &tim->primljeni_golovi);
    } while (tim->primljeni_golovi < 0 && printf("Broj golova mora biti nenegativan.\n"));

    do
    {
        printf("Unesite broj bodova: ");
        scanf("%d", &tim->bodovi);
    } while (tim->bodovi < 0 && printf("Broj bodova mora biti nenegativan.\n"));

    getchar();
}

TIM *formiraj(int *n)
{
    do
    {
        printf("Unesite broj timova: ");
        scanf("%d", n);
    } while (*n < 0 && printf("Broj timova mora biti nenegativan.\n"));

    getchar();

    TIM *timovi = (TIM *)malloc(*n * sizeof(TIM));

    for (int i = 0; i < *n; i++)
    {
        printf("\n");
        printf("Unesite podatke za %d. tim:\n", i + 1);
        printf("===========================\n");

        ucitaj(&timovi[i]);
    }

    return timovi;
}

void sortiraj(TIM *timovi, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (timovi[i].bodovi == timovi[j].bodovi)
            {
                int gol_razlika_1 = timovi[i].postignuti_golovi - timovi[i].primljeni_golovi;
                int gol_razlika_2 = timovi[j].postignuti_golovi - timovi[j].primljeni_golovi;

                if (gol_razlika_1 == gol_razlika_2)
                {
                    if (timovi[i].postignuti_golovi < timovi[j].postignuti_golovi)
                    {
                        SWAP(timovi[i], timovi[j]);
                    }
                }
                else if (gol_razlika_1 < gol_razlika_2)
                {
                    SWAP(timovi[i], timovi[j]);
                }
            }
            else if (timovi[i].bodovi < timovi[j].bodovi)
            {
                SWAP(timovi[i], timovi[j]);
            }
        }
    }
}

void ispisi(TIM *timovi, int n)
{
    printf("RB. NAZIV                          GPO GPR    GR BOD\n");
    printf("=== ============================== === === ===== ===\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2d. %-30s %3d %3d %5d %3d\n", i + 1, timovi[i].naziv, timovi[i].postignuti_golovi, timovi[i].primljeni_golovi, timovi[i].postignuti_golovi - timovi[i].primljeni_golovi, timovi[i].bodovi);
    }
    printf("=== ============================== === === ===== ===\n");
}

int main()
{
    int n;
    TIM *timovi = formiraj(&n);

    sortiraj(timovi, n);
    ispisi(timovi, n);
    free(timovi);

    return 0;
}