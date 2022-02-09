/*
 * main.c
 *
 * Created: 2/9/2022 10:29:16 AM
 *  Author: luca1
 */ 

#define F_CPU 8e6
#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	/* setup */
	DDRC = 0xFF;
	DDRD = 0x00;
	PORTC = 0x01;
	EICRA |= 0x0F;
	EIMSK |= 0x03;
	sei();
	
    while(1)
    {
        /* empty while loop */
		wait(10);
    }
}


ISR(INT0_vect){
	if(PORTC == 0x80){
		PORTC = 0x01;
	}  else {
		PORTC = (PORTC << 1);
	}
}

ISR(INT1_vect){
	if(PORTC == 0x01){
		PORTC = 0x80;
		}  else {
		PORTC = (PORTC >> 1);
	}
}

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}