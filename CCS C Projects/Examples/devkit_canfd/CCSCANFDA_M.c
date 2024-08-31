#define CAN_TX_PIN      PIN_C14
#define CAN_RX_PIN      PIN_C15

#pin_select C1TX = CAN_TX_PIN
#pin_select C1RX = CAN_RX_PIN

#define CAN_TX_BUFFERS     16

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

void write_7_segment(uint8_t segment, uint8_t value)
{
   write_7_segment(segment, 0x7F, lcd_seg[value % 10]);
}

void clear_7_segments(void)
{
   write_7_segment(NODE_D_7SEG_0, 0xFF, 0);
   write_7_segment(NODE_D_7SEG_1, 0xFF, 0);
   write_7_segment(NODE_D_7SEG_2, 0xFF, 0);
}

#define WRITE_LEDS_C_ID    0x300

typedef enum {GREEN, YELLOW, RED} COLORS;

void write_c_led(COLORS led, int1 on)
{
   CAN_TX_HEADER Header;
   uint8_t Data[2];
   
   Header.Id = WRITE_LEDS_C_ID;
   Header.Length = 2;
   Header.ext = TRUE;
   Header.rtr = FALSE;
   Header.Format = CAN_MESSAGE_FORMAT_CAN_FD;
   
   Data[0] = 0x01 << led;
   
   if(on)
      Data[1] = 0;
   else
      Data[1] = 0xFF;
   
   can_putd(&Header, Data);
}

#define NODE_C_PUSHBUTTON_ID  0x303 

#define PUSH_BUTTON  PIN_C0

#pin_select U1TX=PIN_C8
#pin_select U1RX=PIN_C9

#use rs232(xmit=PIN_D8, rcv=PIN_D9, baud=115200)

#include <tick.c>
#define TickDifference(a,b)   (a-b)

#define GREEN_LED PIN_C12
#define YELLOW_LED PIN_B15
