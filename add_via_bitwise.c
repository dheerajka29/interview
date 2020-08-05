/*
 * Add two numbers without using arithmetic operators
   Write a function Add() that returns sum of two integers. 
   The function should not use any of the arithmetic operators (+, ++, –, -, .. etc).
 */

#include <stdio.h>

int main(void) {
    int a = 89;
    int b = 121;
    int carry = 0;
    /*
     * b is used for storing the carry information.
     */ 
    while(b != 0) {
          carry = a & b;
	  a = a^b;
	  b = carry<<1;
    }
    printf("%d\n",a);   
    return 0; 
}	
