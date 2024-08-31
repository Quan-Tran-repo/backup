#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
#define RS pin_e0
#define RW pin_e1
#define E  pin_e2
#BIT TMR1IF = 0x0C.0
void lcd_command(unsigned int8 cm)
   {
      output_low(RW);
      output_low(RS);
      output_d(cm);
      output_low(e);
      output_high(e);
      delay_ms(1);
   }
void lcd_data(unsigned int8 dt)
   {
      output_low(RW);
      output_high(RS);
      output_d(dt);
      output_low(e);
      output_high(e);      
      delay_ms(1);
   }
void lcd_setup()
   {
      delay_ms(5);
      lcd_command(0x38);
      delay_ms(5);
      lcd_command(0x0C);
      lcd_command(0x06);
      lcd_command(0x01);
      delay_ms(2);
   }
void main()
{    
   char count, sec=0;
   lcd_setup();
   set_tris_d(0);
   set_tris_e(0);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   set_timer1(3036);
   while (true)
      {
         for (count=0;count<10;count++)
            {
               while(TMR1IF==0)
                  {
                     set_timer1(3035);
                  }
               TMR1IF=0;
            }
         sec++;
         if (sec==60) sec=0;
         lcd_command(0xc7);
         lcd_data(sec/10 +0x30);
         lcd_data(sec%10 +0x30);
      }
}
