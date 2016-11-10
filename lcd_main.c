 //#define _LEGACY_HEADERS
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h"
#pragma config WDTE=OFF, FOSC=XT, CPD=OFF, LVP=OFF, BOREN=OFF
#define _XTAL_FREQ 4000000

void main(void){
    

char buf[10];
int num;
float vol;
float watt;
int rodri;
float precio;


 
	lcd_init();


	ADCON0=0xC1;

	ADCON1=0x8F;
        TRISC=0X01;
       
		 
	for(;;){

              GO=1;
              while (GO);
              num=(int)ADRESH*256+(int)ADRESL;
               rodri=RC0;
            if(rodri==0){
                precio=0;
                lcd_goto(0);
                vol= (float)num*50.0/1023.0;
                sprintf(buf,"Amp: %1.2f A",vol);
                lcd_puts(buf);
                lcd_puts("    ");
                lcd_goto(0x40);
                watt=vol*220.0;
                sprintf(buf,"Watt: %1.2f W",watt);
                lcd_puts(buf);
                lcd_puts("    ");
            }

            if(rodri==1){
                lcd_goto(0);
                vol= (float)num*50.0/1023.0;
                watt=vol*220.0;
                precio=precio+((350.0/3600.0)*(watt/1000.0));
                sprintf(buf,"Amp: %1.2f A",vol);
                lcd_puts(buf);
                lcd_puts("    ");
                lcd_goto(0x40);
                vol= (float)num*50.0/1023.0;
                watt=vol*220.0;
                precio=precio+((350.0/(3600.0*2.0))*watt);
                __delay_ms (500);
                sprintf(buf,"%1.2f G",precio);
                lcd_puts(buf);
                lcd_puts("    ");
            }
    }
}
