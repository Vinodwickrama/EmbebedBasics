#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd4bit.h"
unsigned int count;

main(void){
	DDRC=0xff;
	PORTC=0x00;
	LCDInit(0);
	LCDClear();
	MCUCR=(1<<ISC01)|(1<<ISC00);
	GICR=(1<<INT0);
	sei();
	
	while(1){
		LCDWriteStringXY(2,1,"Count = ");
		LCDWriteIntXY(count,3);
	}
}


ISR(INT0_vect){
	PORTC=0xff;
	_delay_ms(10);
	PORTC=0x00;
	count++;
	LCDClear();
}