#include <LPC21xx.h>

unsigned int i;

int main ()
{
	IO0DIR = 0x00000400;			//Set P0.10 as output
	IO0SET = 0x00000400;			//P0.10 is set to a HI
	
	while(1)
	{
		for(i=0;i<1000000;i++)
		{}
		IO0SET = 0x00000400;		//RLY ON
		for(i=0;i<1000000;i++)
		{}
		IO0CLR = 0x00000400;		//RLY OFF
	}
}
