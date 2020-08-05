/*
 * Given a number, find the most significant bit number which is set bit and which is in power of two

   Examples:

   Input : 10
   Output : 8
   Binary representation of 10 is 1010
   The most significant bit corresponds
   to decimal number 8.

   Input : 18
   Output : 16
 */

#include <stdio.h>

int
main(void) {
     int num = 18;
     int count = 0;
     while(num){
           count++;
	   num=num/2;
     }	     
     printf("%d\n",count);
     return 0;
}	
