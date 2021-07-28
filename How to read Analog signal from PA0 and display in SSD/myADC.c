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
		PORTA=(0<<PA0);
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
	DDRC=0xff;
	DDRA=(0<<PA0)|(1<<PA4)|(1<<PA5)|(1<<PA6)|(1<<PA7);
}

void readAnalog(void){
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADATE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADCSRA=ADCSRA|(1<<ADSC);
	while(!(ADCSRA&(1<<ADSC))){}
	decodeSSD(ADC);
	displaySSD();
	
	
}


void displaySSD(void){
	for(int i=0;i<4;i++){
			PORTA=(1<<i+4);
			PORTC=nums[dig[i]];
			_delay_ms(1);
			PORTC=0x00;
		}
}
