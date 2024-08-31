#define CAN_USE_FILTERS          TRUE

#define CAN_USER_FILT_0          0x400
#define CAN_USER_MASK_0          0x1FFFFF00
#define CAN_USER_FILT_0_TYPE     CAN_FILTER_TYPE_EID_ONLY
#define CAN_USER_FILT_0_OBJECT   CAN_OBJECT_FIFO_1

#include "CCSCANFDB.c"

void main(void)
{
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint8_t i;
   
   can_init();
   
   while(TRUE)
   {
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
