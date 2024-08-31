#define CAN_TIME_BASE_COUNTER_ENABLE      TRUE //enable Time-Stamp Counter
#define CAN_TIME_BASE_COUNTER_PRESCALAR   1000 //increment every 1000 clocks, every 50us

#define CAN_RX_TIME_STAMP     TRUE  //enable Time-Stamp for RX Buffer, FIFO1

#include "CCSCANFDB.c"

void DisplayTimeStamp(uint32_t TimeStamp)
{
   uint8_t Hr, Min, Sec;
   uint16_t mSec;
   
   TimeStamp /= 20;   //in ms
   
   mSec = TimeStamp % 1000;
   TimeStamp /= 1000; //in seconds
   
   Sec = TimeStamp % 60;
   TimeStamp /= 60;   //in mins
   
   Min = TimeStamp % 60;
   Hr = TimeStamp / 60;
   
   printf("%02u:%02u:%02u.%03lu -> ", Hr, Min, Sec, mSec);
}

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
            if(Header.HasTS)
               DisplayTimeStamp(Header.TimeStamp);
         
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
