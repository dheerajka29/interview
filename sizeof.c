#include <stdio.h>

/*
 * Use a preprocessesor instead.
 */ 
int main(void) {
    double x = 0;
    printf("size is %d",((char *)(&x + 1)-(char *)&x));
}	
