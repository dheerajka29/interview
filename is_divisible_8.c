/*
 * Check if a number is divisible by 8 using bitwise operators
   Given a number n, check if it is divisible by 8 using bitwise operators.

   Examples:

   Input : 16
   Output :YES

   Input :15
   Output :NO
 */

#include <stdio.h>

int
main(void) {
    int num = 4;
    if(num & ((1<<3) - 1)) 
       printf("not divisible by 8 \n");	    
    else
       printf("Divisible by 8 \n");
    return 0;
}	
