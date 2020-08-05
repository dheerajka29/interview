/*
 * https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
 * Given an integer n, find whether it is a power of 4 or not.

   Example :

   Input : 16
   Output : 16 is a power of 4

   Input : 20
   Output : 20 is not a power of 4
 */

#include <stdio.h>

int
main(void) {
    int num = 16;
    /*
     * Step 1 : Check if only single bit is set ,if not
     * it cannot be power of 4.
     * Step 2 : If only single bit is present , 
     * then statically check with bits which are multiples of 4, i.e
     * 16,64,256 etc.
     */ 
     if((num & (num - 1) == 0) && (num & 0x55555554))
	printf("No is power of 4\n");
     else
	printf("No is not a power of 4\n");
     return 0;     
}	
