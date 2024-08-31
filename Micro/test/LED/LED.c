#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
const unsigned int8 Anode[10]={0xC0, 0xFC, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned int8 i,a,b, x=0x00, y=0x00;
void main()
{
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_a(0x03);
   if (!input(pin_A0))
      {delay_ms(20);
      if(!input(pin_A0))
         {
      for (i=0;i<24;i++)
       {
         a=i%10; b=i/10;
         x=Anode[a];
         y=Anode[b];
         output_c(y);
         output_d(x);
         delay_ms(100);
       }
         }
      }
}
