#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool 
is_prime(double num) {
    if (num == 0.0 || num == 1.0)
        return false;	    
    int temp = sqrt(num);
    int index = 2;
    for (index; index <= temp; index++) {
         if((int)num % index == 0)
            return false;
    }	    
    return true;
}	

int main (void) {
   double num = 2;
   printf("No is %s\n",is_prime(num)?"a Prime":"not a Prime");
}	
