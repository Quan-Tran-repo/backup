#include <16F887.h>
#device ADC=10
#use delay(internal=20MHz)
#use rs232(baud=9600,parity=N,xmit=None,rcv=None,bits=8,stream=PORT1,FORCE_SW)

