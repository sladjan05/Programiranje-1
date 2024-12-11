#include "fraction.h"

#include <stdio.h>

#include "utils.h"

RAZLOMAK frac_input()
{
    RAZLOMAK f;
    scanf("%d/%d", &f.num, &f.den);

    return f;
}

RAZLOMAK frac_add(RAZLOMAK a, RAZLOMAK b)
{
    RAZLOMAK result;

    result.num = a.num * b.den + b.num * a.den;
    result.den = a.den * b.den;

    int d = gcd(result.num, result.den);
    result.num /= d;
    result.den /= d;

    return result;
}

void frac_print(RAZLOMAK f)
{
    printf("%d/%d", f.num, f.den);
}