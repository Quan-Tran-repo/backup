#define SLAVE_PROGRAM_START_ADDR       0x10000
#define SLAVE_PROGRAM_END_ADDR         0x103FE
#define SLAVE_PROGRAM_INSTRUCTIONS     512

#include <33CH128MP506.h>
#device ADC=12
#fuses WDT_SW, S1_WDT_SW, S1_PLLWAIT, S1_CKSFSM

#fuses CPRB=0xBFFF   //PIN_B14 controlled by slave, all other PORTB pins controlled by Master

#use delay(clock=180MHz, crystal=20Mhz, SLAVE: crystal=20MHz, AUX: clock=80MHz)

#include "CCSCANFDA_M.c"

//Sets aside Master's flash memory used to store the Slave's program.
#org SLAVE_PROGRAM_START_ADDR,SLAVE_PROGRAM_END_ADDR {}

//Import Slave's program into Master's flash
#import(file="EX15S.hex", HEX, range=SLAVE_PROGRAM_START_ADDR:SLAVE_PROGRAM_END_ADDR)

void main(void)
{
   CAN_RX_HEADER Header;
   uint8_t Data[CAN_ACTUAL_MAX_RX_PAYLOAD_SIZE];
   uint16_t SlaveVerify;
   TICK cTick, ADCTick, LEDTick;
   int1 SlaveRunning = FALSE;
   uint16_t ADCReading;
   int1 isHigh = TRUE;
   
   output_high(GREEN_LED);    //turn off
   output_high(YELLOW_LED);   //turn off
   
   delay_ms(100);
   
   //Load and verify slave program into slave core
   load_slave_program(SLAVE_PROGRAM_START_ADDR, SLAVE_PROGRAM_INSTRUCTIONS);
   SlaveVerify = verify_slave_program(SLAVE_PROGRAM_START_ADDR, SLAVE_PROGRAM_INSTRUCTIONS);
   
   if(SlaveVerify == 0) //no verification errors
   {
      output_low(GREEN_LED);
      
      //Enable slave core, and enable FIFO write communication
      setup_msi(MSI_SLAVE_ENABLE | MSI_WRITE_FIFO_ENABLED);
   }
   
   can_init();    //always initialize the CAN
   
   //Setup ADC to read channel AN0
   setup_adc_ports(sAN0, VSS_VDD);
   setup_adc(ADC_CLOCK_SYSTEM | ADC_CLOCK_DIV_2 | ADC_SHARED_CLOCK_DIV_2 | 
             ADC_SHARED_TAD_MUL_1025 | ADC_ENABLE_SHARED_CORE);
   set_adc_channel(0);
   
   LEDTick = ADCTick = TickGet();
   
   while(TRUE)
   {
      cTick = TickGet();
      
      //Toggle LED on Node C
      if(TickDifference(cTick, LEDTick) >= (TICKS_PER_SECOND / 4))
      {
         if(isHigh)
            write_c_led(GREEN, TRUE);
         else
            write_c_led(GREEN, FALSE);
         
         isHigh++;
         LEDTick = cTick;
      }
      
      //Read ADC every 100 ms and send to save code and display
      //on Node D 7-segments.
      if(TickDifference(cTick, ADCTick) >= (TICKS_PER_SECOND / 10))
      {
         ADCReading = read_adc();
         
         if(SlaveRunning)
            msi_write_fifo(ADCReading);
         else
         {
            if((msi_status() & MSI_SLAVE_IN_RESET) == 0)
            {
               SlaveRunning = TRUE;
               
               output_low(YELLOW_LED); //turn on
            }
         }
         
         write_7_segments(ADCReading, 16);
         
         ADCTick = cTick;
      }
      
      //Read any received CAN messages
      if(can_kbhit())
      {
         can_getd(&Header, Data);
      }
   }
}
