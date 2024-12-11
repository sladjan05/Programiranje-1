#include "bigint.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BigInt bi_from_int(int n)
{
    BigInt result = calloc(MAX_LENGTH, sizeof(int8_t));

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        result[i] = n % 10;
        n /= 10;
    }

    return result;
}

void bi_increment(BigInt n)
{
    int8_t carry = 1;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        int8_t sum = n[i] + carry;

        n[i] = sum % 10;
        carry = sum / 10;
    }
}

int8_t bi_compare(BigInt a, BigInt b)
{
    for (int i = MAX_LENGTH - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            return 1;
        }
        else if (a[i] < b[i])
        {
            return -1;
        }
    }

    return 0;
}

BigInt bi_multiply(BigInt a, BigInt b)
{
    BigInt result = bi_from_int(0);

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        for (int j = 0; i + j < MAX_LENGTH; j++)
        {
            int8_t product = a[i] * b[j];

            int8_t carry = product / 10;
            product %= 10;

            int8_t sum = result[i + j] + product;

            result[i + j] = sum % 10;
            result[i + j + 1] += carry + sum / 10;
        }
    }

    return result;
}

BigInt bi_factorial(BigInt n)
{
    BigInt result = bi_from_int(1);

    for (BigInt i = bi_from_int(1); bi_compare(i, n) <= 0; bi_increment(i))
    {
        BigInt temp = bi_multiply(result, i);
        free(result);

        result = temp;
    }

    return result;
}

void bi_print(BigInt n)
{
    int i = MAX_LENGTH - 1;

    while (i > 0 && n[i] == 0)
    {
        i--;
    }

    for (; i >= 0; i--)
    {
        printf("%d", n[i]);
    }
}