#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void initInterrupt(void);
unsigned int state=0;

void main(void){
	DDRC=0x0f;
	initInterrupt();
	while(1){
		
	}
	
}

void initInterrupt(void){
	MCUCR=(1<<ISC01)|(1<<ISC00); 
	GICR=(1<<INT0);
	sei();
}



ISR(INT0_vect){
	PORTC=(1<<PC3)^PORTC;
}