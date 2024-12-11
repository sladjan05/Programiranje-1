#pragma once

typedef struct
{
    double re;
    double im;
} KOMPLEKS;

KOMPLEKS cx_input();
double cx_modulo(KOMPLEKS c);

void cx_print(KOMPLEKS c);