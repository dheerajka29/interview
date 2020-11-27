#include<stdio.h>
#include<stdlib.h>

#define CHECK_BIT(x,pos) x & (1U<<pos)
#define TOGGLE_BIT(x,pos) x ^= (1U<<pos)
#define SET_BIT(x,pos) x |= (1U<<pos)
#define CLEAR_BIT(x,pos) x &= ~(1U<<pos)
#define SWAP_NIBBLE(x) ((x&(0x0F))<<4 | (x&(0xF0))>>4)
#define CHANGE_ENDIAN(x) (((x&(0x000000FF))<<24) | ((x&(0x0000FF00))<<8) | ((x&(0x00FF0000))>>8) | ((x&(0xFF000000))>>24))
void main()
{
	int x = 8;

	printf("sizeof int = %d" ,sizeof(int));
	printf("Check bit at position 3 for value %d is %d\n",x, CHECK_BIT(x,3)); 
	x = 8;
	printf("Toggle bit at position 2 for value %d, after Toggle is %d\n",x, TOGGLE_BIT(x,2)); 
	x = 8;
	printf("Set bit at position 2 for value %d after set is %d\n",x, SET_BIT(x,2)); 
	x = 8;
	printf("clear bit at position 2 for value %d after clear is %d\n",x, CLEAR_BIT(x,2));
	x = 8;
	printf("Swap nibble for value %d after swap is %d\n",x, SWAP_NIBBLE(x));
	x=1;
	printf("change endian for value %x after change is %x\n",x, CHANGE_ENDIAN(x));
}


