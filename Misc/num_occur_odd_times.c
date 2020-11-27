/*
 * https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
 * Given an array of positive integers. All numbers occur even number of times 
 * except one number which occurs odd number of times. Find the number in O(n) time & constant space.
   Examples :

   Input : arr = {1, 2, 3, 2, 3, 1, 3}
   Output : 3

   Input : arr = {5, 7, 2, 7, 5, 2, 5}
   Output : 5
 *
 */

#include <stdio.h>

int 
main(void) {
    int arr[] = {1, 2, 3, 2, 3, 1, 3};
    int len = sizeof(arr)/sizeof(int);
    /*
     * Algo 1 : take a new array , with index being
     * the array element , and increement it. 
     * Finally , traverse the array again and print element
     * with odd count.
     */ 
     
    //Algo 2.
    int temp = arr[0];
    int iter ;
    for(iter = 1;iter < len; iter++) {
	/*when xor of 2 same elements is done , it returns zero.
	 *and when xor is done for 3 elements , the a^a = 0 ^a = a returns.  
         */	 
         temp = temp ^ arr[iter];
    }	    
    printf("%d\n",temp);
    return 0;
}	
