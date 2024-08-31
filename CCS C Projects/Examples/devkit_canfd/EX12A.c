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
         write_7_segment(NODE_D_7SEG_0, i);
      
         write_c_led(GREEN, i>1);
         write_c_led(YELLOW, i>4);
         write_c_led(RED, i>7);
         
         if(++i == 10)
            i = 0;
            
         pTick = cTick;
      }
      
      //Check if push button was pressed, and if so send an RTR message to 
      //get current count from Node B.
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
               txHeader.rtr = TRUE;
               txHeader.Format = CAN_MESSAGE_FORMAT_CAN_2_0;
               
               can_putd(&txHeader, 0);
            }
            
            pLevel = cLevel;
         }
      }
      
      //If message with Id of 0x1000 is received print current count to serial
      //port.
      if(can_kbhit())
      {
         if(can_getd(&Header, Data) == CAN_EC_OK)
         {
            if(Header.Id == 0x1000)
               printf("\r\nNode B Count: %lu", make32(Data[3], Data[2], Data[1], Data[0]));
         }
      }
   }
}
