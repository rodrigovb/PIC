#include <xc.h>
#pragma config WDTE=OFF, FOSC=XT, CPD=OFF, LVP=OFF
#define _XTAL_FREQ 4000000
#include <stdio.h>
#include "usart.h"


void main(void){

	ADCON0=0xC1;
    ADCON1=0x8E;
     
	INTCON=0;	// purpose of disabling the interrupts.

	init_comms();	// set up the USART - settings defined in usart.h

	while(1){
		GO=1;
            while (GO);
            if(getch()==107){
                putch(ADRESH);
                __delay_ms(50); 
                putch(ADRESL);
            } 
    }
}
