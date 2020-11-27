#include <stdio.h>
#include <string.h>

int
main(void) {
    int num = 1;
    int count = 0;
    int temp = num;
    while(temp){
          count = (count*10 + (temp%10));  	    
          temp = temp/10;
    }
    if(count == num)
       printf("no is palindrome\n");
    else
       printf("no is not palindrome\n");		    
    return 0; 
}	
