/*
 * Link : https://www.geeksforgeeks.org/check-n-divisible-power-2-without-using-arithmetic-operators/
 */ 

#include <stdio.h>

int
main(void) {
    int num = 32;
    int pow = 3;
    if(num & ((1<<pow) - 1))
       printf("Not Divisible\n");
    else
       printf("Divisible\n");
    return 0;    
}	
