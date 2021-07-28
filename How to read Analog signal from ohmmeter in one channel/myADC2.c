#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
unsigned char nums[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // Declare an array with led patterns corresponding to decimal numbers from 0 to 9//
unsigned int dig[]={1,2,2,4}; // declare an array to store a value in a digit
unsigned int reading;
void decodeSSD(unsigned int val);  // this method separates given number and store it as digit wise.
void initDDR(void);
void readAnalog(void);
void displaySSD(void);


main(void){
	initDDR();
	while(1){
		PORTA=(0<<PA2);
		readAnalog();
		
	
	}
}



void decodeSSD(unsigned int val){
	dig[3]=val%10;
	dig[2]=(val%100)/10;
	dig[1]=(val%1000)/100;
	dig[0]=(val%10000)/1000;
}


void initDDR(void){
	DDRC=0xff;   // Set data direction register C all output
	DDRA=(0<<PA2)|(1<<PA4)|(1<<PA5)|(1<<PA6)|(1<<PA7);  // Set PA4,PA5,PA6,PA7 as outputs and PA0 as input
}

void readAnalog(void){
	ADMUX=(1<<REFS0)|(1<<MUX1);  // set voltage reference value - AVCC with external capacitor at AREF pin in ADMUX register
	ADCSRA=(1<<ADEN)|(1<<ADATE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // set ADEN,ADATE,ADPS2,ADPS1,ADPS0 in ADCSRA register
	
	ADCSRA=ADCSRA|(1<<ADSC); //starting the conversion by setting ADSC.
	while(!(ADCSRA&(1<<ADSC))){} // run loop until ADSC in ADCSRA set by 1. Because after finishing conversion ADSC becomes 0
	decodeSSD(ADC); // decode the value of ADC
	displaySSD();  // Display the SSD
	
	
}


void displaySSD(void){
	for(int i=0;i<4;i++){
			PORTA=(1<<i+4);
			PORTC=nums[dig[i]];
			_delay_ms(1);
			PORTC=0x00;
		}
}
