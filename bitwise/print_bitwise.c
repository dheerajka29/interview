/*
 * https://www.geeksforgeeks.org/print-bitwise-and-set-of-a-number-n/
 * Print bitwise AND set of a number N
   Given a number N, print all the numbers which are a bitwise AND set of the binary representation of N. 
   Bitwise AND set of a number N is all possible numbers x smaller than or equal N such that N & i is equal to x for some number i.

   Examples :

   Input : N = 5
   Output : 0, 1, 4, 5
   Explanation: 0 & 5 = 0
                1 & 5 = 1
                2 & 5 = 0
                3 & 5 = 1
                4 & 5 = 4
                5 & 5 = 5
   So we get 0, 1, 4 and 5 in the
   bitwise subsets of N.

   Input : N = 9
   Output : 0, 1, 8, 9
 */

#include <stdio.h>

int
main(void) {
    int n = 9;
    int i = n;
    for(;i > 0;i = (i-1)&n){
        printf("%d\n",i);
    }	   
    printf("0\n"); 
    return 0;
}	
