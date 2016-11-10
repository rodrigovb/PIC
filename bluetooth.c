#include <xc.h>
#pragma config WDTE=OFF, FOSC=XT, CPD=OFF, LVP=OFF
#define _XTAL_FREQ 4000000
#include <stdio.h>
//#include <htc.h>
#include "usart.h"


/* A simple demonstration of serial communications which
 * incorporates the on-board hardware USART of the Microchip
 * PIC16Fxxx series of devices. */

void main(void){
	unsigned char input;
        TRISE=0x00;
        TRISD=0x00;
     
	INTCON=0;	// purpose of disabling the interrupts.

	init_comms();	// set up the USART - settings defined in usart.h

	// Output a message to prompt the user for a keypress	
//	printf("\r Ok\n");
	while(1){
		input = getch();	// read a response from the user
	//	printf("[%c]",input);
                // echo it back
                
                if (input=='E') {
                    PORTD=0xff;
                }
                if (input=='A') {
                    PORTD=0x00;
                }
             //   putch(input);
   
	}
}
