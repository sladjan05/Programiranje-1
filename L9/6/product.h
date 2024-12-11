#pragma once

typedef struct
{
    int id;
    char name[30];
    double price;
    int quantity;
} ARTIKAL;

ARTIKAL prod_input();

void prod_print_table(int n, ARTIKAL arr[]);