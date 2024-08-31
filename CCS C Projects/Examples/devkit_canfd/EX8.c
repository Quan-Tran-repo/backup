#include "CCSCANFDA.c"

void ChangeLedState(uint8_t *State, COLORS Led)
{
   if(bit_test(*State, Led))
      bit_clear(*State, Led);
   else
      bit_set(*State, Led);
   
   write_c_led(Led, bit_test(*State, Led));
}

void main(void)
{
   uint8_t Buffer[8];
   CAN_RX_HEADER Header;
   uint8_t LedState = 0;
   
   can_init();    //always initialize the CAN
   
   //Make sure all three leds on Node C are off
   write_c_led(RED, FALSE);
   write_c_led(YELLOW, FALSE);
   write_c_led(GREEN, FALSE);
   
   while(TRUE)
   {
      if(can_kbhit())
      {
         if(can_getd(&Header, Buffer) == CAN_EC_OK)
         {
            if(Header.Id == NODE_C_PUSHBUTTON_ID)
            {
               if(bit_test(Buffer[0], RED) == 0)      //button was pressed
                  ChangeLedState(&LedState, RED);
               if(bit_test(Buffer[0], GREEN) == 0)    //button was pressed
                  ChangeLedState(&LedState, GREEN);
               if(bit_test(Buffer[0], YELLOW) == 0)   //button was pressed
                  ChangeLedState(&LedState, YELLOW);
            }
         }
      }
   }
}
