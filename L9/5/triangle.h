#pragma once

typedef struct
{
    double a;
    double b;
    double c;
} TROUGAO;

TROUGAO tr_input();
double tr_perimeter(TROUGAO t);
double tr_area(TROUGAO t);