#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
const unsigned int8 Anode[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
const unsigned int8 Cathode[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void main()
{
   int8 i,k,j;
   set_tris_c(0x00);
   set_tris_d(0x00);
   while(true)
   {
   for (i=0;i<24;i++)
      {
      for (j=0;j<60;j++)
         {
         for (k=0;k<60;k++)
            {
               output_c(Cathode[k%10]);output_low(pin_d0);delay_ms(1);output_high(pin_d0);
               output_c(Cathode[k/10]);output_low(pin_d1);delay_ms(1);output_high(pin_d1);
               delay_ms(1);
            }
            output_c(Cathode[j%10]);output_low(pin_d2);delay_ms(1);output_high(pin_d2);
            output_c(Cathode[j/10]);output_low(pin_d3);delay_ms(1);output_high(pin_d3);
         }   
         output_c(Cathode[i%10]);output_low(pin_d4);delay_ms(1);output_high(pin_d4);
         output_c(Cathode[i/10]);output_low(pin_d5);delay_ms(1);output_high(pin_d5);
       }
    }
}
