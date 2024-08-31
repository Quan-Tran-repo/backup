#include "CCSCANFDB.c"

void main(void)
{
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint8_t i;
   
   can_init();
   
   can_set_mode(CAN_OP_CONFIG);     //put in config mode
   
   can_set_filter_id(CAN_FILTER_0, 0x300, 0x1FFFFF00, CAN_FILTER_TYPE_EID_ONLY);
   can_enable_filter(CAN_FILTER_0, CAN_OBJECT_FIFO_1);
   
   can_set_mode(CAN_OP_NORMAL_FD);  //put in normal FD mode
   
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
