/*
 * Link : https://www.geeksforgeeks.org/check-number-positive-negative-zero-using-bit-operators/
 */ 

#include <stdio.h>

int
main(void) {
    int a = -5;
    int temp = 1 + (a>>31) - (~a>>31); // 0 will return 1. positive num will return 2. negative will return 0.
    return 0;
}
