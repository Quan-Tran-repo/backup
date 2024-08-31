#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)

led5hz()
{
   output_d(0x00);
   delay_ms(100);
   output_d(0xff);
   delay_ms(100);
}

led10hz()
{
   output_d(0x00);
   delay_ms(50);
   output_d(0xff);
   delay_ms(50);
}
void main()
{
   set_tris_d(0x00);
   temp=1;
   while(true)
   {
      if(temp==1)
         {
         led5hz();
         if(!input(pin_A0))
           {temp=0;
            else 
            temp=1;}
         }
      if(temp==0)
         {
         led10hz();
         if(!input(pin_A0))
           {temp=1;
            else 
            temp=0;}
         }
   }
