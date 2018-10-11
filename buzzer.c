#include <LPC21xx.h>
#include "Timer0.h"

unsigned int delay=0;

int main ()
{
	InitTimer0(1000);  			// for 1 sec delay - 
	IO0DIR = 0x00000200 ;		// Configure P0.9 as output
	IO1DIR 	|=0X02000000;		// for LED  P1.25
	T0TCR = 0x01;				// start timer 

	while(1)
	{
		IO0SET = 0x00000200 ; 	//Buzzer ON
		IO1SET = 0x02000000 ; 	//led ON
		
		while(tmr_ovflg == 0);
		tmr_ovflg =0;

		IO0CLR = 0x00000200 ;	//Buzzer off
		IO1CLR = 0x02000000 ;	//led off
		
        while(tmr_ovflg == 0);
		tmr_ovflg =0;
	}
}	

