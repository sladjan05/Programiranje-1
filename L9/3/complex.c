#include "complex.h"

#include <stdio.h>
#include <math.h>

KOMPLEKS cx_input()
{
    KOMPLEKS c;
    scanf("%lf %lf", &c.re, &c.im);

    return c;
}

double cx_modulo(KOMPLEKS c)
{
    return sqrt(c.re * c.re + c.im * c.im);
}

void cx_print(KOMPLEKS c)
{
    printf("%.2lf + %.2lfi", c.re, c.im);
}