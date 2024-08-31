//Enable FIFO2 Object as a RX Object with a buffer size of 1 and max payload 
//size of 8 bytes.
#define CAN_USE_FIFO_2_OBJECT
#define CAN_FIFO_2_OBJECT_TYPE               0  //RX Object
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

#define MCP2517_INT_PIN PIN_A4

#include "CCSCANFDB.c"

#pin_select INT0=MCP2517_INT_PIN

#INT_EXT
void can_isr(void)
{
   CAN_TX_HEADER txHeader;
   uint16_t Reading;
   
   can_discard(CAN_OBJECT_FIFO_2);  //easy way to clear FIFO2's buffer
   
   Reading = read_adc();
   
   txHeader.Id = 0x1000;
   txHeader.Length = 2;
   txHeader.ext = TRUE;
   txHeader.rtr = FALSE;
   txHeader.Format = CAN_MESSAGE_FORMAT_CAN_FD;
   
   can_putd(&txHeader, (uint8_t *)&Reading);   
}

void main(void)
{
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint8_t i;
   
   port_a_pullups(0x10);   //enable pull-up on PIN_A4
   
   setup_adc_ports(sAN2, VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(2);

   can_init();
   
   //Enable CAN FIFO Receive Not Empy Interrupt for FIFO 2
   can_enable_fifo_interrupts(CAN_OBJECT_FIFO_2, CAN_FIFO_INTERRUPT_RXNE);
   //Enable CAN Receive Object Interrupt
   can_enable_interrupts(CAN_INTERRUPT_RX);
   
   enable_interrupts(INT_EXT_H2L);  //enable EXT interrupt for falling edge
   enable_interrupts(GLOBAL);       //enable global interrupt

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
