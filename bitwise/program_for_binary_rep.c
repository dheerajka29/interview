/*
 * https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
 */

#include <stdio.h>

void
recurse_print(unsigned int num){
    if(num){
       recurse_print(num>>1);
       printf("%u",num &1); 
    }	    
}	
int
main(void) {
    unsigned int num = 342;
    recurse_print(num);
    return 0;    
}	
