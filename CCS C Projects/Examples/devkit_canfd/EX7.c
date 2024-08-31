#include "CCSCANFDA.c"

void main(void)
{
   CAN_TX_HEADER Header;
   uint8_t Data[3];
   
   can_init();
   
   Header.Id = 0x400;
   Header.Length = 3;
   Header.ext = TRUE;
   Header.rtr = FALSE;
   Header.Format = CAN_MESSAGE_FORMAT_CAN_FD;
   
   Data[0] = 0x00;
   Data[1] = 0x80;
   Data[2] = 0xFF;
   
   can_putd(&Header, Data);
   
   while(TRUE)
   {
   
   }
}
