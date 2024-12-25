#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} TACKA;

typedef struct
{
    TACKA tacke[3];
} TROUGAO;

void citaj(TACKA *t)
{
    scanf("%lf %lf", &t->x, &t->y);
}

double udaljenost(TACKA t1, TACKA t2)
{
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

int provjera(TACKA *tacke)
{
    return udaljenost(tacke[0], tacke[1]) + udaljenost(tacke[1], tacke[2]) > udaljenost(tacke[0], tacke[2]) &&
           udaljenost(tacke[0], tacke[1]) + udaljenost(tacke[0], tacke[2]) > udaljenost(tacke[1], tacke[2]) &&
           udaljenost(tacke[1], tacke[2]) + udaljenost(tacke[0], tacke[2]) > udaljenost(tacke[0], tacke[1]);
}

TROUGAO trougao(TACKA *tacke)
{
    TROUGAO t;

    for (int i = 0; i < 3; i++)
    {
        t.tacke[i] = tacke[i];
    }

    return t;
}

double obim(TROUGAO t)
{
    return udaljenost(t.tacke[0], t.tacke[1]) + udaljenost(t.tacke[1], t.tacke[2]) + udaljenost(t.tacke[0], t.tacke[2]);
}

int main()
{
    TACKA tacke[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Unesite koordinate %d. tacke: ", i + 1);
        citaj(&tacke[i]);
    }

    if (provjera(tacke))
    {
        TROUGAO t = trougao(tacke);
        printf("Obim trougla je: %.4lf\n", obim(t));
    }
    else
    {
        printf("Trougao nije moguce formirati.\n");
    }

    return 0;
}