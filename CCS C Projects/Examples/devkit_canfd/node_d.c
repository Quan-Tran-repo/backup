#include <16F18346.h>
#fuses NOWDT
#use delay(internal=32MHz)

#case

#define MCP2517_SPI_SCK_PIN   PIN_C0
#define MCP2517_SPI_SDO_PIN   PIN_C2
#define MCP2517_SPI_SDI_PIN   PIN_C1
#define MCP2517_SPI_CS_PIN    PIN_B4

#pin_select SCK1OUT=MCP2517_SPI_SCK_PIN
#pin_select SDO1=MCP2517_SPI_SDI_PIN
#pin_select SDI1=MCP2517_SPI_SDO_PIN

#define CAN_USE_FILTERS       TRUE

#define CAN_USER_FILT_0       0x400
#define CAN_USER_MASK_0       0x1FFFFFFF
#define CAN_USER_FILT_0_TYPE  CAN_FILTER_TYPE_EID_ONLY

#include <can-mcp2517.c>

#define OUTPUT_LATCH_REG1     0x00
#define OUTPUT_LATCH_REG2     0x01
#define OUTPUT_LATCH_REG3     0x02

/////////////////

#define _7SEG_A_PIN     PIN_C6
#define _7SEG_B_PIN     PIN_A1
#define _7SEG_C_PIN     PIN_A2
#define _7SEG_D_PIN     PIN_C3
#define _7SEG_E_PIN     PIN_C4
#define _7SEG_F_PIN     PIN_C5
#define _7SEG_G_PIN     PIN_A0
#define _7SEG_DP_PIN    PIN_C7

#define _7SEG_AN1_PIN   PIN_B5
#define _7SEG_AN2_PIN   PIN_B6
#define _7SEG_AN3_PIN   PIN_B7

uint8_t g_7SegValue[3] = {0, 0, 0};

void _7SegAnPinLevel(uint8_t Position, int1 Level)
{
   switch(Position)
   {
      case 0:
         if(Level)
            output_high(_7SEG_AN3_PIN);
         else
            output_low(_7SEG_AN3_PIN);
         break;
      case 1:
         if(Level)
            output_high(_7SEG_AN2_PIN);
         else
            output_low(_7SEG_AN2_PIN);
         break;
      case 2:
         if(Level)
            output_high(_7SEG_AN1_PIN);
         else
            output_low(_7SEG_AN1_PIN);
         break;
   }
}

#INT_TIMER2 
void led_refresh_timer(void)
{
   static uint8_t Position = 2;
   uint8_t value;
   
   _7SegAnPinLevel(Position, 0);
   
   if(++Position >= 3)
      Position = 0;
   
   value = g_7SegValue[Position];
   
   if(bit_test(value, 0))
      output_low(_7SEG_A_PIN);
   else
      output_high(_7SEG_A_PIN);
   
   if(bit_test(value, 1))
      output_low(_7SEG_B_PIN);
   else
      output_high(_7SEG_B_PIN);
   
   if(bit_test(value, 2))
      output_low(_7SEG_C_PIN);
   else
      output_high(_7SEG_C_PIN);
   
   if(bit_test(value, 3))
      output_low(_7SEG_D_PIN);
   else
      output_high(_7SEG_D_PIN);      
   
   if(bit_test(value, 4))
      output_low(_7SEG_E_PIN);
   else
      output_high(_7SEG_E_PIN);      
   
   if(bit_test(value, 5))
      output_low(_7SEG_F_PIN);
   else
      output_high(_7SEG_F_PIN);
   
   if(bit_test(value, 6))
      output_low(_7SEG_G_PIN);
   else
      output_high(_7SEG_G_PIN);
   
   if(bit_test(value, 7))
      output_low(_7SEG_DP_PIN);
   else
      output_high(_7SEG_DP_PIN);
   
   _7SegAnPinLevel(Position, 1);
}

void Init7Segment(void)
{
   output_low(_7SEG_AN1_PIN);
   output_low(_7SEG_AN2_PIN);
   output_low(_7SEG_AN3_PIN);
   
   setup_timer_2(T2_DIV_BY_64, 208, 1);   //~200 Hz refresh rate per 7-segment
   
   enable_interrupts(INT_TIMER2);
   enable_interrupts(GLOBAL);
}

void Display7Segment(uint8_t position, uint8_t Mask, uint8_t Value)
{
   uint8_t i;
   
   for(i=0;i<8;i++)
   {
      if(bit_test(Mask, i) == 1)
      {
         if(bit_test(Value, i))
            bit_set(g_7SegValue[position], i);
         else
            bit_clear(g_7SegValue[position], i);
      }
   }
}

typedef enum {DIGIT_ZERO, DIGIT_ONE, DIGIT_TWO, DIGIT_THREE, DIGIT_FOUR, DIGIT_FIVE,
              DIGIT_SIX, DIGIT_SEVEN, DIGIT_EIGHT, DIGIT_NINE} DIGITS;

typedef enum {
   DIGIT_VALUE_ZERO = 0x3f,
   DIGIT_VALUE_ONE = 0x06,
   DIGIT_VALUE_TWO = 0x5B,
   DIGIT_VALUE_THREE = 0x4F,
   DIGIT_VALUE_FOUR = 0x66,
   DIGIT_VALUE_FIVE = 0x6D,
   DIGIT_VALUE_SIX = 0x7D,
   DIGIT_VALUE_SEVEN = 0x07,
   DIGIT_VALUE_EIGHT = 0x7F,
   DIGIT_VALUE_NINE = 0x6F,
   DIGIT_VALUE_CLEAR = 0
} DIGIT_VALUE;

DIGIT_VALUE Get7SegValue(DIGITS Digit)
{
   DIGIT_VALUE Result;

   switch(Digit)
   {
      case DIGIT_ZERO:
         Result = DIGIT_VALUE_ZERO;
         break;
      case DIGIT_ONE:
         Result = DIGIT_VALUE_ONE;
         break;
      case DIGIT_TWO:
         Result = DIGIT_VALUE_TWO;
         break;
      case DIGIT_THREE:
         Result = DIGIT_VALUE_THREE;
         break;
      case DIGIT_FOUR:
         Result = DIGIT_VALUE_FOUR;
         break;
      case DIGIT_FIVE:
         Result = DIGIT_VALUE_FIVE;
         break;
      case DIGIT_SIX:
         Result = DIGIT_VALUE_SIX;
         break;
      case DIGIT_SEVEN:
         Result = DIGIT_VALUE_SEVEN;
         break;
      case DIGIT_EIGHT:
         Result = DIGIT_VALUE_EIGHT;
         break;
      case DIGIT_NINE:
         Result = DIGIT_VALUE_NINE;
         break;
      default:
         Result = DIGIT_VALUE_CLEAR;
         break;
   }
   
   return(Result);
}

void DisplayCount7Seg(uint16_t Count)
{
   if(Count > 999)
      Count = 999;
   
   Display7Segment(0, 0x7F, Get7SegValue(Count % 10));
   Count /= 10;
   Display7Segment(1, 0x7F, Get7SegValue(Count % 10));
   Count /= 10;
   Display7Segment(2, 0x7F, Get7SegValue(Count % 10));
}

void main(void)
{
   CAN_RX_HEADER RxHeader;
   uint8_t RxData[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   
   Init7Segment();
   
   can_init();
   
   while(TRUE)
   {
      if(can_kbhit())
      {
         if(can_getd(&RxHeader, RxData) == CAN_EC_OK)
         {
            if(RxHeader.Length == 3)
            {
               if((RxData[0] >= OUTPUT_LATCH_REG1) && (RxData[0] <= OUTPUT_LATCH_REG3))
                  Display7Segment(RxData[0], RxData[1], RxData[2]);
            }
         }
      }
   }
}
