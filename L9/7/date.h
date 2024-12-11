#pragma once

typedef struct
{
    int day;
    int month;
    int year;
} DATUM;

DATUM date_input();
int date_compare(DATUM a, DATUM b);