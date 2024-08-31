#include <16F887.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
const unsigned int8 Anode[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned int8 i,x=0x00, y=0x00;
unsigned int8 temp=0;
void up()
{
    for (i=temp;(i<24)||(temp==0);i++)
   {
    x=Anode[i%10];
    y=Anode[i/10];
    output_c(y);
    output_d(x);
    delay_ms(100);
    if (!input(pin_A1))
      {temp=i;
      break;}
    if (i==23)
      i=0;
    }
}  
void down() 
{
    for (i=temp;(i>0)||(temp==0);i--)
   {
    x=Anode[i%10];
    y=Anode[i/10];
    output_c(y);
    output_d(x);
    delay_ms(100);
    if (!input(pin_A0))
      {temp=i;
      break;}
    if (i==1)
      i=23;
    }
}
void main()
{
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_a(0xFF);
   output_c(0xFF);
   output_d(0xFF);
   while(true)
   {
   if(!input(pin_a0))
         {
         up();
         }
   if(!input(pin_a1))
         {
         down();
         }
   }
}
