/*
 * Link : https://www.geeksforgeeks.org/1-to-n-bit-numbers-with-no-consecutive-1s-in-binary-representation/
 * 1 to n bit numbers with no consecutive 1s in binary representation.
   Given a number n, our task is to find all 1 to n bit numbers with no consecutive 1s in their binary representation.

   Examples:

   Input : n = 4
   Output : 1 2 4 5 8 9 10
   These are numbers with 1 to 4
   bits and no consecutive ones in
   binary representation.

   Input : n = 3
   Output : 1 2 4 5
 */

#include <stdio.h>

int
main(void) {
    int n_bit = 3;
    int i = 0;
    int j = 0;
    /*First loop to traverse till the n_bit.*/
    for(i; i < n_bit;i++) {
        /*Print this bit as no other 1s beside it*/
        printf("%d\n",1<<i);
	/* Loop taking the i-2 bit right of current bit.*/
	for(j = i-2;j>=0;j--){
	    printf("%d\n",(1<<j) | (1<<i));
	}	
    }
    return 0;    
}	
