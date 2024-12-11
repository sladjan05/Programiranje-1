#include "date.h"

#include <stdio.h>

int date_compare(DATUM a, DATUM b)
{
    if (a.year != b.year)
        return a.year - b.year;
    if (a.month != b.month)
        return a.month - b.month;
    return a.day - b.day;
}