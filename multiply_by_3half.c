/*
 * Multiply a given Integer with 3.5
   Given a integer x, write a function that multiplies x with 3.5 and returns the integer result. You are not allowed to use %, /, *.
   Examples :
   Input: 2
   Output: 7

   Input: 5
   Output: 17 (Ignore the digits after decimal point)
 */

#include <stdio.h>

int
multiply_by_three_half(int num){
      return ((num<<1) + num + (num>>1));
}	

int
main(void) {
     int num = 352;
     printf("After multiplication , no is %d\n",
	    multiply_by_three_half(num));	    
     return 0; 
}	
