#include <16F887.h>
#device ADC=10
#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=None,rcv=None,bits=8,stream=PORT1,FORCE_SW)

