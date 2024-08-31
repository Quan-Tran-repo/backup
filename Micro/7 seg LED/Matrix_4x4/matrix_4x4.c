#include <matrix_4x4.h>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
const int8 Anode[16]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,
0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
unsigned int8 keypad()
{
   unsigned int8 key=0xFF, col, row=0xFF,scan ;
check:
   for (col=0,scan=0xFE; col<4; col++,scan=(scan<<1)+1)
      {
         output_b(scan);
         if (!input(pin_B4)) {row=0; break;}
         if (!input(pin_B5)) {row=1; break;}
         if (!input(pin_B6)) {row=2; break;}
         if (!input(pin_B7)) {row=3; break;}
      }
   if (row != 0xFF)
      {
         key= col*4+row;
         row=0xFF;
         delay_ms(20); goto check;
      }
   return key;
}
         
void main()
{  
   unsigned int8 key;
   set_tris_b(0xFF);
   set_tris_d(0xFF);
   while(TRUE)
      {
         key=keypad();
         if (key!=0xFF)
            {
               output_d(Anode[key]);
            }
      }

}
