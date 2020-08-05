/*
 * Link : https://www.geeksforgeeks.org/modify-bit-given-position/
 */ 
#include <stdio.h>

int
main(void) {
    int n = 7, p = 2, b = 0;
    printf("%d\n",((~(1<<(p))) | b<<(p)) & n);
    return 0;	    
}	
