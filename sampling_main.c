/* Routine that sends data serially via bluetooth of a sampling circuit of analog signal */

void main(void){
	unsigned char input;
        TRISE=0x00;
        TRISD=0x00;
        char buf[10];
int num;
float vol;
float watt;
int rodri;
float precio;

	ADCON0=0xC1;
    ADCON1=0x8E;
     
	INTCON=0;	// purpose of disabling the interrupts.

	init_comms();	// set up the USART - settings defined in usart.h

	// Output a message to prompt the user for a keypress	
//	printf("\r Ok\n");
	while(1){
		 GO=1;
              while (GO);
              num=(int)ADRESH*256+(int)ADRESL;
               rodri=RD0;
               vol= (float)num*50.0/1023.0;
               watt=vol*220.0;
               precio=precio+((350.0*watt)/3600000.0);
        sprintf(buf,"%1.2f",vol);
        rodri=0;
        for(rodri=0;rodri<=9;rodri++){
            input=buf[rodri];
            putch(input);
        }
        __delay_ms(990);        
	}
}
