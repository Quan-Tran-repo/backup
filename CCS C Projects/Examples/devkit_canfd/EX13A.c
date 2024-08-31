#include "CCSCANFDA.c"

#include <tick.c>
#define TickDifference(a,b)   (a-b)

void main(void)
{
   TICK cTick, pTick;
   CAN_TX_HEADER txHeader;
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint8_t i=0;
   int1 cLevel, pLevel;
   
   can_init();    //always initialize the CAN
   
   clear_7_segments();  //clear the 7 segments
   
   pTick = TickGet() - TICKS_PER_SECOND;
   pLevel = input(PUSH_BUTTON);
   
   while(TRUE)
   {
      cTick = TickGet();
      
      if(TickDifference(cTick, pTick) >= TICKS_PER_SECOND)
      {
         if(bit_test(i, 0))
            write_c_led(GREEN, TRUE);
         else
            write_c_led(GREEN, FALSE);
         
         if(bit_test(i, 1))
            write_c_led(YELLOW, TRUE);
         else
            write_c_led(YELLOW, FALSE);
         
         if(bit_test(i, 2))
            write_c_led(RED, TRUE);
         else
            write_c_led(RED, FALSE);
         
         if(++i > 7)
            i = 0;
            
         pTick = cTick;
      }
      
      //Check if push button was pressed, and if so send a message to
      //get ADC Reading from Node B.
      cLevel = input(PUSH_BUTTON);
      
      if(cLevel != pLevel)
      {
         delay_us(50);
         
         if(input(PUSH_BUTTON) != pLevel)
         {
            if(cLevel == 0)
            {
               txHeader.Id = 0x1000;
               txHeader.Length = 0;
               txHeader.ext = TRUE;
               txHeader.rtr = FALSE;
               txHeader.Format = CAN_MESSAGE_FORMAT_CAN_FD;
               
               can_putd(&txHeader, 0);
            }
            
            pLevel = cLevel;
         }
      }
      
      //If message with Id of 0x1000 is received display ADC Reading on Node D 7-segments
      if(can_kbhit())
      {
         if(can_getd(&Header, Data) == CAN_EC_OK)
         {
            if(Header.Id == 0x1000)
               write_7_segments(make16(Data[1], Data[0]), 16);
         }
      }
   }
}
