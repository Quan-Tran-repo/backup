#include <33CH128MP506.h>
#fuses NOWDT
#use delay(crystal=20MHz)

#define GREEN_LED    PIN_C12

void main(void)
{
   while(TRUE)
   {
      output_low(GREEN_LED);
      delay_ms(1000);
      output_high(GREEN_LED);
      delay_ms(1000);
   }
}
