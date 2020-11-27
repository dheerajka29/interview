/*
 * Add 1 to a given number
   Write a program to add one to a given number. The use of operators like ‘+’, ‘-‘, ‘*’, ‘/’, ‘++’, ‘–‘ …etc are not allowed.
   Examples:

   Input:  12
   Output: 13

   Input:  6
   Output: 7
 *
 */   


#include <stdio.h>

int 
add_num(int no) {
    int m = 1;
    /*
     * Logic : Take the initial bit as set . 
     * Now check if the number has bit set corresponding to m.
     * If yes , then move to next bit toggling the current visited bit.
     * If no , then toggle the current bit and return the number.
     */ 
    while (no & m) {
       no = no ^ m;
       m=m<<1;
    }
    no = no^m;
    return no;    
}	

int 
main() {
    int num = 14;
    printf("No is %d\n",add_num(num));
    return 0;
}

