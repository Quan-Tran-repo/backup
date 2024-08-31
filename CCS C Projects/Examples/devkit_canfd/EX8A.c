#include <16F18346.h>
#fuses NOWDT
#device ADC=10
#use delay(internal=32MHz)

#define MCP2517_SPI_SCK_PIN   PIN_C0
#define MCP2517_SPI_SDO_PIN   PIN_C2
#define MCP2517_SPI_SDI_PIN   PIN_C1
#define MCP2517_SPI_CS_PIN    PIN_B4

#pin_select SCK1OUT=MCP2517_SPI_SCK_PIN
#pin_select SDO1=MCP2517_SPI_SDI_PIN
#pin_select SDI1=MCP2517_SPI_SDO_PIN

#define CAN_TX_BUFFERS     4

#include <can-mcp2517.c>

#define RED_LED            PIN_C3
#define YELLOW_LED         PIN_C4
#define GREEN_LED          PIN_C5

#define WRITE_LEDS_C_ID       0x300

typedef enum {GREEN, YELLOW, RED} COLORS;

void main(void)
{
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   int1 a,b,c;
   
   a = b = c = TRUE;
   
   can_init();
   
   while(TRUE)
   {
      if(can_kbhit())
      {
         if(can_getd(&Header, Data) == CAN_EC_OK)
         {
            if(Header.Id == WRITE_LEDS_C_ID)
            {
               if(bit_test(Data[0], GREEN))
                  a = Data[1];
               else if(bit_test(Data[0], YELLOW))
                  b = Data[1];
               else if(bit_test(Data[0], RED))
                  c = Data[1];
               
               output_bit(GREEN_LED, a);
               output_bit(YELLOW_LED, b);
               output_bit(RED_LED, c);
            }
         }
      }
   }
}
