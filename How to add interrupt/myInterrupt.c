#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void main(void){
	DDRC=0xff;
	MCUCR=(1<<ISC01)|(1<<ISC00);
	GICR=(1<<INT0);
	sei();
	while(1){
		PORTC=0x0f|PORTC;
		_delay_ms(1000);
		PORTC=0x00;
		_delay_ms(1000);
	}
	
}

ISR(INT0_vect){
	PORTC=0xf0|PORTC;
	_delay_ms(10);
}