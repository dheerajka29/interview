/*
 * Rotate bits of a number
   Bit Rotation: A rotation (or circular shift) is an operation similar to shift except 
   that the bits that fall off at one end are put back to the other end.
   In left rotation, the bits that fall off at left end are put back at right end.

   In right rotation, the bits that fall off at right end are put back at left end.
 */

#include <stdio.h>
#include <stdbool.h>

unsigned
left_rotate(unsigned int num , unsigned int no_bits) {
     return (num<<no_bits) | (num>>((sizeof(unsigned int)*8) - no_bits)); 
}	

unsigned
right_rotate(unsigned int num , unsigned int no_bits) {
     return (num>>no_bits) | (num<<((sizeof(unsigned int)*8) - no_bits));
}

int
main(void) {
    unsigned int num = 16;
    int bits_to_rotate = 2;
    bool is_left_rotate = false;
    if(is_left_rotate)
       printf("after rotation : %u\n",left_rotate(num,bits_to_rotate));
    else
       printf("after rotation : %u\n",right_rotate(num,bits_to_rotate));   
    return 0 ;
}	
