#define CAN_USE_FIFO_2_OBJECT            
#define CAN_FIFO_2_OBJECT_TYPE               1  //TX Object
#define CAN_FIFO_2_OBJECT_COUNT              1
#define CAN_FIFO_2_OBJECT_MAX_PAYLOAD_SIZE   PAYLOAD_SIZE_8_BYTES
#define CAN_FIFO_2_OBJECT_TX_PRIORITY        31

#include "CCSCANFDA.c"

#include <tick.c>
#define TickDifference(a,b)   (a-b)

void main(void)
{
   TICK cTick, pTick;
   CAN_TX_HEADER txHeader;
   uint8_t i=0;
   
   can_init();    //always initialize the CAN
   
   clear_7_segments();  //clear the 7 segments
   
   pTick = TickGet() - TICKS_PER_SECOND;
   
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
         
         txHeader.Id = 0x1000;
         txHeader.Length = 0;
         txHeader.ext = TRUE;
         txHeader.rtr = FALSE;
         txHeader.Format = CAN_MESSAGE_FORMAT_CAN_FD;
         
         can_putd(&txHeader, 0, CAN_OBJECT_FIFO_2);
         
         pTick = cTick;
      }   
   }
}
