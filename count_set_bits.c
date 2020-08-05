/*
 * https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
 */ 

#include <stdio.h>

int
main(void) {
    int num = 2;
    int count = 0;
    int m = 1;
    int iter = sizeof(num) * 8;
    /*while(iter >0) {
          if(m & num){
             count++;
	  }	
	  iter--;
	  m <<=1;	  
    }*/
    /*while(num){
          num = num/2;
	  count++;
    }*/
    while(num) {
          count++;
	  num = num&(num-1);
    }	    
    printf("%d\n",count);    
    return 0;
}	
