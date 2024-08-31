//Enable FIFO2 Object as a TX Object with a buffer size of 1 and max payload 
//size of 8 bytes.
#define CAN_USE_FIFO_2_OBJECT
#define CAN_FIFO_2_OBJECT_TYPE               1  //TX Object
#define CAN_FIFO_2_OBJECT_COUNT              1
#define CAN_FIFO_2_OBJECT_MAX_PAYLOAD_SIZE   PAYLOAD_SIZE_8_BYTES
#define CAN_FIFO_2_OBJECT_TX_PRIORITY        31

//Enable CAN Filters and setup FILTER 0 for RTR ID and assign it to the FIFO2
//Object.  Enable Filter 1, which will be setup to receive all other messages
//and direct them to FIFO 1.
#define CAN_USE_FILTERS          TRUE

#define CAN_USER_FILT_0          0x1000
#define CAN_USER_MASK_0          0x1FFFFFFF
#define CAN_USER_FILT_0_TYPE     CAN_FILTER_TYPE_EID_ONLY
#define CAN_USER_FILT_0_OBJECT   CAN_OBJECT_FIFO_2

#define CAN_USER_FILT_1          0
#define CAN_USER_MASK_1          0
#define CAN_USER_FILT_1_TYPE     CAN_FILTER_TYPE_EID_ONLY
#define CAN_USER_FILT_1_OBJECT   CAN_OBJECT_FIFO_1

#include "CCSCANFDB.c"

void main(void)
{
   CAN_TX_HEADER txHeader;
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint8_t i;
   uint32_t Count = 0;
   
   can_init();
   
   can_enable_rtr(CAN_OBJECT_FIFO_2);
   
   while(TRUE)
   {
      //Check if FIFO 2 is empty and if so load with next message
      //to send when an remote transmission request is received.
      if(can_tx_is_empty(CAN_OBJECT_FIFO_2))
      {
         txHeader.Id = 0x1000;
         txHeader.Length = 4;
         txHeader.ext = TRUE;
         txHeader.rtr = FALSE;
         txHeader.Format = CAN_MESSAGE_FORMAT_CAN_FD;
         
         can_load_rtr(&txHeader, (uint8_t *)&Count, CAN_OBJECT_FIFO_2);
         
         Count++;
      }
   
      if(can_kbhit())
      {
         if(can_getd(&Header, Data) == CAN_EC_OK)
         {
            printf("%LX: (%u)", Header.Id, Header.Length);
            
            if(!Header.rtr)
            {
               for(i=0;i<Header.Length;i++)
                  printf(" %X", Data[i]);
            }
            
            PrintCANStats(&Header);
            printf("\r\n");
         }
      }
   }
}
