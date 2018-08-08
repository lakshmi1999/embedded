# embedded
#include<lpc21xx.h>
int main()
{
	 int j,i;
   PINSEL0=0x00000000;
   IO0DIR=0x0000F000;
	 IO0CLR=0x0000F000;
   for(i=0;i<50;i++)
   {                           
	   IO0PIN=0x0000E000;		
		 for(j=0;j<2500000;j++)
			    {}
	  IO0PIN=0x0000D000;
		 for(j=0;j<2500000;j++)
	   {}
	   				      
	   IO0PIN=0x0000E000;
		 for(j=0;j<2500000;j++)
	{}
	    	    
	   IO0PIN=0x00007000;
		 for(j=0;j<2500000;j++)
		{}
		  IO0PIN=0x0000E000;
		 for(j=0;j<2500000;j++)
			{}
		  IO0PIN=0x00007000;
		 
		 for(j=0;j<2500000;j++)
				{}
		  IO0PIN=0x0000B000;
		 for(j=0;j<2500000;j++)
					{}
		  IO0PIN=0x00007000;
		 for(j=0;j<2500000;j++)
		 {}
		  IO0PIN=0x0000B000;
		 for(j=0;j<2500000;j++)
			{}
		  IO0PIN=0x0000D000;
		 for(j=0;j<2500000;j++)
			{}
		  IO0PIN=0x0000B000;
		 for(j=0;j<250000;j++)
			{}
		  IO0PIN=0x0000D000;
		 for(j=0;j<2500000;j++)
			{}
		  IO0PIN=0x0000E000;
		 for(j=0;j<2500000;j++)
			{}
		 
		 	}
	 /*for(i=0;i<25;i++)
	 {
    for(i=0;i<25;i++)
   {
     
	   IO0PIN=0x00007000;		  
		 for(j=0;j<5000;j++);
			    
	  IO0PIN=0x0000B000;
		 for(j=0;j<5000;j++)
		 {
		 }
	   				      
	   IO0PIN=0x0000D000;
		 for(j=0;j<5000;j++)
		 {
		 }
	    	    
	   IO0PIN=0x0000E000;
		 for(j=0;j<5000;j++);
	 }*/
 }
