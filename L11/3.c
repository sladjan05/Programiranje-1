#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char naziv[30 + 1];
    char ekstenzija[10 + 1];
    int bajtovi;
} DOKUMENT;

DOKUMENT *formiraj(int *n)
{
    do
    {
        printf("Unesite broj dokumenata: ");
        scanf("%d", n);
    } while (*n < 0 && printf("Broj dokumenata mora biti nenegativan.\n"));

    DOKUMENT *dokumenti = (DOKUMENT *)malloc(*n * sizeof(DOKUMENT));

    for (int i = 0; i < *n; i++)
    {
        getchar();
        printf("\n");

        printf("Unesite naziv %d. dokumenta: ", i + 1);
        gets(dokumenti[i].naziv);

        printf("Unesite ekstenziju %d. dokumenta: ", i + 1);
        scanf("%s", dokumenti[i].ekstenzija);

        do
        {
            printf("Unesite broj bajtova %d. dokumenta: ", i + 1);
            scanf("%d", &dokumenti[i].bajtovi);
        } while (dokumenti[i].bajtovi < 0 && printf("Broj bajtova mora biti nenegativan.\n"));
    }

    return dokumenti;
}

void ispisi(DOKUMENT dokument)
{
    char puno_ime[30 + 10 + 1 + 1];
    sprintf(puno_ime, "%s.%s", dokument.naziv, dokument.ekstenzija);
    printf("%-41s | %d [B]\n", dokument.naziv, dokument.bajtovi);
}

int main(void)
{
    int n;
    DOKUMENT *dokumenti = formiraj(&n);

    printf("\n");

    int bajtovi;
    do
    {
        printf("Ispisi sve dokumente koji imaju vise od ... bajtova: ");
        scanf("%d", &bajtovi);
    } while (bajtovi < 0 && printf("Broj bajtova mora biti nenegativan.\n"));

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (dokumenti[i].bajtovi > bajtovi)
        {
            ispisi(dokumenti[i]);
        }
    }

    free(dokumenti);

    return 0;
}