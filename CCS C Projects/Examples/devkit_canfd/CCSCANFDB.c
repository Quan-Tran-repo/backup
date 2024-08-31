#include <16F18346.h>
#fuses NOWDT
#device ADC=10
#use delay(internal=32MHz)

#case

#define MCP2517_SPI_SCK_PIN   PIN_C0
#define MCP2517_SPI_SDO_PIN   PIN_C2
#define MCP2517_SPI_SDI_PIN   PIN_C1
#define MCP2517_SPI_CS_PIN    PIN_B4

#pin_select SCK1OUT=MCP2517_SPI_SCK_PIN
#pin_select SDO1=MCP2517_SPI_SDI_PIN
#pin_select SDI1=MCP2517_SPI_SDO_PIN

#define CAN_TX_BUFFERS     4

#define RED_LED            PIN_C3
#define YELLOW_LED         PIN_C4
#define GREEN_LED          PIN_C5

#define WRITE_LEDS_C_ID       0x300

typedef enum {GREEN, YELLOW, RED} COLORS;

#include <can-mcp2517.c>

#define RS232_TX_PIN    PIN_B6
#define RS232_RX_PIN    PIN_B7

#pin_select U1TX=RS232_TX_PIN
#pin_select U1RX=RS232_RX_PIN
#use rs232(xmit=RS232_TX_PIN, rcv=RS232_RX_PIN, baud=115200)

void PrintCANStats(CAN_RX_HEADER *Header)
{
   uint8_t Count = 0;
   
   if(Header->rtr || Header->err_ovfl || Header->Format)
   {
      printf(" - ");
      
      if(Header->rtr)
      {
         putc('R');
         Count++;
      }

      if(Header->err_ovfl)
      {
         if(Count)
            putc(',');
         putc('O');
         Count++;
      }
      
      if(Header->Format)
      {
         if(Count)
            putc(',');
         printf("FD");
      }
   }
}
