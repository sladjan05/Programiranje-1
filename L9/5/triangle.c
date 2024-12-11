#include "triangle.h"

#include <stdio.h>
#include <math.h>

TROUGAO tr_input()
{
    TROUGAO t;

    printf("Unesite stranice trougla: ");
    scanf("%lf %lf %lf", &t.a, &t.b, &t.c);

    if (t.a + t.b <= t.c || t.a + t.c <= t.b || t.b + t.c <= t.a)
    {
        printf("Trougao nije validan.\n");
        return tr_input();
    }

    return t;
}

double tr_perimeter(TROUGAO t)
{
    return t.a + t.b + t.c;
}

double tr_area(TROUGAO t)
{
    double s = tr_perimeter(t) / 2;
    return sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
}