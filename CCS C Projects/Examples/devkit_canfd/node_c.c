#include <16F15324.h>
#fuses NOWDT
#device ADC=16
#use delay(internal=32MHz)

#define NODE_C_LEDS              0x300
#define NODE_C_RANDOM_NUMBER     0x301
#define NODE_C_PUSHBUTTON        0x303

#case

#define MCP2517_SPI_SCK_PIN      PIN_C0
#define MCP2517_SPI_SDO_PIN      PIN_C2
#define MCP2517_SPI_SDI_PIN      PIN_C1
#define MCP2517_SPI_CS_PIN       PIN_C3

#pin_select SCK1OUT = MCP2517_SPI_SCK_PIN
#pin_select SDO1 = MCP2517_SPI_SDI_PIN
#pin_select SDI1 = MCP2517_SPI_SDO_PIN

#define CAN_USE_FILTERS          TRUE

#define CAN_USER_FILT_0          NODE_C_LEDS
#define CAN_USER_MASK_0          0x1FFFFFFE
#define CAN_USER_FILT_0_TYPE     CAN_FILTER_TYPE_EID_ONLY

#define CAN_TX_BUFFERS           16
#define CAN_TX_MAX_PAYLOAD_SIZE  PAYLOAD_SIZE_8_BYTES

#include <can-mcp2517.c>

/////////////////

#use fast_io(a)

#define ANALOG_INPUT_PIN      PIN_A5

#define ANALOG_CHANNEL        5
#define ANALOG_PORTS_SETTING  (sAN5, VSS_FVR)
#define ANALOG_SETTING        (ADC_CLOCK_INTERNAL)

#define LED_RED_PIN           PIN_A4
#define LED_YELLOW_PIN        PIN_C4
#define LED_GREEN_PIN         PIN_C5

#define PUSH_BUTTON_1_PIN     PIN_A2   //Under Green LED
#define PUSH_BUTTON_2_PIN     PIN_A1   //Under Yellow LED
#define PUSH_BUTTON_3_PIN     PIN_A0   //Under Red LED

void OutputLeds(uint8_t Mask, uint8_t Value)
{
   uint8_t i;
   
   for(i=0;i<3;i++)
   {
      switch(i)
      {
         case 0:
            if(bit_test(Mask, 0))
            {
               if(bit_test(Value, 0))
                  output_high(LED_GREEN_PIN);
               else
                  output_low(LED_GREEN_PIN);
            }
            break;
         case 1:
            if(bit_test(Mask, 1))
            {
               if(bit_test(Value, 1))
                  output_high(LED_YELLOW_PIN);
               else
                  output_low(LED_YELLOW_PIN);
            }
            break;
         case 2:
            if(bit_test(Mask, 2))
            {
               if(bit_test(Value, 2))
                  output_high(LED_RED_PIN);
               else
                  output_low(LED_RED_PIN);
            }
            
            break;
      }
   }
}

void InitHw(void)
{
   output_high(LED_RED_PIN);
   output_high(LED_YELLOW_PIN);
   output_high(LED_GREEN_PIN);

   output_a(0xFF);
   set_tris_a(0x2F);
   
   can_init();
}

void main(void)
{
   CAN_RX_HEADER RxHeader;
   uint8_t RxData[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   CAN_TX_HEADER TxHeader;
   uint8_t TxData[CAN_ACTUAL_MAX_TX_PAYLOAD_SIZE];
   typedef union
   {
      int1 pin[3];
      uint8_t b;
   } pins_t;
   
   pins_t cLevel, pLevel;
   
   InitHw();
   
   pLevel.b = input_a() & 0x7;
   
   while(TRUE)
   {
      if(can_kbhit())
      {
         if(can_getd(&RxHeader, RxData) == CAN_EC_OK)
         {
            if(RxHeader.Id == NODE_C_LEDS)
            {
               if(RxHeader.Length == 2)
                  OutputLeds(RxData[0], RxData[1]);
            }
         }
      }
      
      cLevel.b = input_a() & 0x07;
      
      if(cLevel.b != pLevel.b)
      {
         delay_us(50);
         
         if((input_a() & 0x07) != pLevel.b)
         {
            TxHeader.Id = NODE_C_PUSHBUTTON;
            TxHeader.Length = 1;
            TxHeader.ext = TRUE;
            TxHeader.rtr = FALSE;
            TxHeader.Format = CAN_MESSAGE_FORMAT_CAN_FD;
            
            TxData[0] = ((uint8_t)cLevel.pin[2] | ((uint8_t)cLevel.pin[1] << 1) | ((uint8_t)cLevel.pin[0] << 2)) & 0x07;
            
            can_putd(&TxHeader, TxData);
               
            pLevel.b = cLevel.b;
         }
      }  
   }
}
