#pragma once

#include <inttypes.h>

#define MAX_LENGTH 200

typedef int8_t *BigInt;

BigInt bi_from_int(int n);
void bi_increment(BigInt n);
int8_t bi_compare(BigInt a, BigInt b);
BigInt bi_multiply(BigInt a, BigInt b);
BigInt bi_factorial(BigInt n);

void bi_print(BigInt n);