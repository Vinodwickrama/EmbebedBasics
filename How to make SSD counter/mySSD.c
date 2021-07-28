#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
unsigned char nums[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // Declare an array with led patterns corresponding to decimal numbers from 0 to 9//
unsigned int dig[]={1,2,3,4}; // declare an array to store a value in a digit.
void countUp(void);   // Increasing the ssd value
void decodeSSD(unsigned int val);  // this method separates given number and store it as digit wise.

main(void){
	DDRC=0xff;
	DDRA=0xff;
	
	while(1){
		countUp();
	
	}
}

void countUp(void){
	for(int j=0;j<10000;j++){
		for(int i=0;i<4;i++){
			PORTA=(1<<i+4);
			decodeSSD(j);
			PORTC=nums[dig[i]];
			_delay_ms(1);
			PORTC=0x00;
		}
		
	}

}

void decodeSSD(unsigned int val){
	dig[3]=val%10;
	dig[2]=(val%100)/10;
	dig[1]=(val%1000)/100;
	dig[0]=(val%10000)/1000;
}


