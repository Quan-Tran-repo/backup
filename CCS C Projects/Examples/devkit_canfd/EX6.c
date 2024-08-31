#include <33CH128MP506.h>
#fuses NOWDT
#use delay(crystal=20MHz, AUX: clock=80MHz)

#define CAN_TX_PIN      PIN_C14
#define CAN_RX_PIN      PIN_C15

#pin_select C1TX = CAN_TX_PIN
#pin_select C1RX = CAN_RX_PIN

#define CAN_TX_BUFFERS     4

#include <can-dsPIC33_FD.c>

#define WRITE_7SEG_D_ID    0x400
#define NODE_D_7SEG_0      0
#define NODE_D_7SEG_1      1
#define NODE_D_7SEG_2      2

const uint8_t lcd_seg[16] = { 0x3F, 0x30, 0x6D, 0x79, 0x72, 0x5B, 0x5F, 0x31, 
                              0x7F, 0x73, 0x77, 0x5E, 0x0F, 0x7C, 0x4F, 0x47};

void write_7_segment(uint8_t segment, uint8_t mask, uint8_t value)
{
   CAN_TX_HEADER Header;
   uint8_t Data[3];
   
   Header.Id = WRITE_7SEG_D_ID;
   Header.Length = 3;
   Header.ext = TRUE;
   Header.rtr = FALSE;
   Header.Format = CAN_MESSAGE_FORMAT_CAN_FD;
   
   Data[0] = segment;
   Data[1] = mask;
   Data[2] = value;
   
   can_putd(&Header, Data);
}

void write_7_segments(uint16_t value, uint8_t base)
{
   write_7_segment(NODE_D_7SEG_0, 0x7F, lcd_seg[value % base]);
   
   value /= base;
   write_7_segment(NODE_D_7SEG_1, 0x7F, lcd_seg[value % base]);
   
   value /= base;
   write_7_segment(NODE_D_7SEG_2, 0x7F, lcd_seg[value]);
}

void main(void)
{
   uint16_t i = 0;
   
   can_init();    //initializes the CAN
   
   while(TRUE)
   {
      write_7_segments(i, 10);
      
      if(++i > 999)
         i = 0;
      
      delay_ms(1000);
   }
}
