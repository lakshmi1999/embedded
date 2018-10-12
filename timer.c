#include <LPC21xx.h>
#include "TIMER0.h"

#define DESIRED_COUNT_FREQ	1000			// in Hz

#define CRYSTAL_FREQUENCY_IN_HZ	12000000
#define PLL_MULTIPLIER	1
#define PCLK	PLL_MULTIPLIER*CRYSTAL_FREQUENCY_IN_HZ	// since VPBDIV=1
#define PRESCALER	(PCLK/DESIRED_COUNT_FREQ)-1

void Delay250 (void);
void DelayMs (int n);

void Timer0ClearIF_Isr(void) __irq; //declaration of ISR

unsigned char tmr_ovflg =0;

void InitTimer0(int interval)
{

/*	VPBDIV: VPB bus clock divider
	1: PCLK = processor clock		*/
	VPBDIV=1;


/*	T0PC: Timer 0 Prescaler counter
	the counter is incremented once every T0PC+1 cycles of PCLK
*/
	T0PR=PRESCALER;
	
	T0MR0=interval;	//interrupt every 1 sec for interval = 1000
	T0MCR=3;		//interrupt and clear when counter=match

/*	T0TCR: Timer 0 Control Register
	2: reset counters (both timer and prescaler)
	1: enable counting
*/
	T0TCR=2;
//	T0TCR=1;
    VICVectAddr0 = (unsigned long) Timer0ClearIF_Isr;   
   VICVectCntl0 = 0x20 | 4;      //Assign the VIC channel Timer0 to interrupt priority 0
   VICIntEnable |= 0x00000010;    //Enable the TIMER0 interrupt

}

void Timer0ClearIF_Isr(void) __irq
{
	T0IR |=0x01;
	VICVectAddr=0;
	tmr_ovflg =0xff;
}

// the functions below are not used
void DelayMs (int n)
{
	int k ;
	for(k = 0 ; k < n ; k ++)
	{
		Delay250() ;
		Delay250() ;
		Delay250() ;
		}
}

void Delay250 (void)
{
	int k ;
	for(k = 0 ; k < 100 ; k ++)
	{
	}
}
