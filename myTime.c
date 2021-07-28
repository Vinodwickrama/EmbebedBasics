#define CPU8000000UL
#include <avr/io.h>
#include <util/delay.h>
void iniTime(void);

void main(void){
	
	DDRC = 0xff;
	iniTime();
	
	
	while(1){
		
	}
}


void iniTime(void){
	TCCR0=TCCR0|(1<<CS00)|(1<<CS02);
	TCNT0=0;
}

ISR(TIMER0_COMP){
	
			PORTC ^= 0xff;  
			
}



