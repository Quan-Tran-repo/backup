#include "CCSCANFDA.c"

void main(void)
{
   uint8_t i=0;
   
   can_init();    //always initialize the CAN
   
   clear_7_segments();  //clear the 7 segments
   
   while(TRUE)
   {
      write_7_segment(NODE_D_7SEG_0, i);
      delay_ms(1000);
      if(++i == 10)
          i = 0;
      
      write_c_led(GREEN, i>1);
      write_c_led(YELLOW, i>4);
      write_c_led(RED, i>7);
   }
}
