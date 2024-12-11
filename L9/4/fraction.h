#pragma once

typedef struct
{
    int num;
    int den;
} RAZLOMAK;

RAZLOMAK frac_input();
RAZLOMAK frac_add(RAZLOMAK a, RAZLOMAK b);

void frac_print(RAZLOMAK f);