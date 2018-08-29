#include<lpc21xx.h>
#include<stdio.h>
 
void lcd_init( void );
void wr_cn( void );
void clr_disp ( void );
void delay ( unsigned int );
void lcd_com (void );
void wr_dn(void);
void lcd_data(void);
 
unsigned char temp1;
unsigned long int temp, r =0;
unsigned char *ptr, disp[] = "pk kathir vm",disp1[] = "VICKY";//

int main()
{
	IO0DIR =  0x000000FC;
	IO0PIN =  0x00000000;
	
	delay(32000);
	lcd_init();
	delay(32000);
	clr_disp();
	delay(32000);
	while(1)
	{
	
	temp1 = 0x8f;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x8e;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x8d;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x8c;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x8b;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x8a;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x89;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x88;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x87;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x86;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x85;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x84;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x83;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x82;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x81;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	temp1 = 0x80;
	lcd_com();
	
	ptr = disp;
	
	while (*ptr!= '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
	}
	clr_disp();
}
temp1 = 0xC0;
lcd_com();

	ptr= disp1;
while(*ptr != '\0')
	{
		temp1 = *ptr;
		lcd_data();
		ptr++;
		}
	while(1);
	}
void lcd_init(void)
{
	temp=0x30;
	wr_cn();
	delay(6200);
	
	temp=0x30;
	wr_cn();
	delay(6200);
	
	temp=0x30;
	wr_cn();
	delay(6200);
	
	temp=0x20;
	wr_cn();
	delay(6200);
	
	temp=0x28;
	lcd_com();
	delay(6200);
	
	temp1 = 0x0c;
	lcd_com();
	delay(8000);
	
	temp1 = 0x06;
	lcd_com();
	delay(8000);
	
	temp1 = 0x80;
	lcd_com();
	delay(8000);
}
void lcd_com( void)
	{
		temp = temp1& 0xf0;
		wr_cn();
		temp = temp1& 0x0f;
		temp = temp << 4;
		wr_cn();
		delay(150000);
		}
		
void wr_cn( void ) 
		{
		IO0CLR = 0x000000FC;
		IO0SET = temp;
		IO0CLR = 0x00000004;
		IO0SET = 0x00000008;
		delay(10);
		IO0CLR = 0x00000008;
		
		}
		
void wr_dn( void )
{
	IO0CLR = 0x000000FC;
	IO0SET = temp;
	IO0SET = 0x00000004;
	IO0SET = 0x00000008;
	delay(10);
	IO0CLR = 0x00000008;
	}
void lcd_data( void )
{
	temp = temp1 & 0xf0;
	temp = temp ;
	wr_dn();
	temp = temp1 & 0x0f;
	temp = temp<<4;
	wr_dn();
	delay(25000);
	
	}
void clr_disp(void)
{
temp1 = 0x01;
lcd_com();
delay(800);	
}

void delay(unsigned int r1)
{
for(r=0;r<r1; r++);
}
