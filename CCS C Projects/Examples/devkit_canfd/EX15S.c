//Set address in Master's flash were the Slave program is stored.
#define SLAVE_PROGRAM_START_ADDR       0x10000

#include <33CH128MP506S1.h>

//Set the clock speed of the slave core, setting it to 40.96MHz
//so the PWM will be 10kHz with a 12-bit duty cycle, full range
//of the ADC.
#use delay(clock=40.96MHz, crystal=20MHz)

//Create hex file with above offset.
#export(file=EX15S.hex, HEX, offset=SLAVE_PROGRAM_START_ADDR)

#pin_select CCP1OUT=PIN_B14

void main(void)
{
   unsigned int16 Duty;
   
   delay_ms(100);
   
   //Enable FIFO reads from Master core.
   setup_msi(MSI_READ_FIFO_ENABLED);

   //Setup CCP1 to produce 10kHz PWM
   set_timer_period_ccp1(4095);  //10kHz
   set_pwm1_duty(4096);
   setup_ccp1(CCP_PWM | CCP_FOSC);
   
   while(TRUE)
   {
      //Check if Master sent PWM Duty reading.
      if((msi_fifo_status() & MSI_READ_FIFO_EMPTY) != MSI_READ_FIFO_EMPTY)
      {
         msi_read_fifo(&Duty);
         
         set_pwm1_duty(4095 - Duty);
      }
   }
}
