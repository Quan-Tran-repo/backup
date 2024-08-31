#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
const unsigned int8 Anode[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
const unsigned int8 Cathode[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void main()
{
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_a(0xFF);
   while(true)
   {
      output_c(Cathode[1]);output_d(0xFE);delay_ms(1000);output_d(0xFF);delay_ms(1000);
      output_c(Cathode[9]);output_d(0xFD);delay_ms(1000);output_d(0xFF);delay_ms(1000);
   }
}
