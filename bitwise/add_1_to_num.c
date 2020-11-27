/*
 * Add 1 to a given number
   Write a program to add one to a given number. 
   The use of operators like ‘+’, ‘-‘, ‘*’, ‘/’, ‘++’, ‘–‘ …etc are not allowed.
 * Link : https://www.geeksforgeeks.org/add-1-to-a-given-number/
 */ 

#include <stdio.h>

int
main(void) {
   unsigned int num = 4;
   unsigned int m = 1;
   if(num & m) {
      num = num ^ m;
      m <<= 1;      
   }
   num = num ^ m;
   printf("%u\n",num);
   return 0;   
}	
