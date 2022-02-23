/*
 * OpdrachtB2.c
 *
 * Created: 23-2-2022 11:27:09
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int mscounter = 0;
int firstTime = 1;

int main(void)
{
	OCR2 = 250;
	TIMSK = 0x80;
	DDRD = 0xFF;
	sei();
	TCCR2 = 0b00001101;
	
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(10);
    }
}

/* starts interrupt when 1 millisecond has been passed with /32 prescaler */
ISR(TIMER2_COMP_vect){
	mscounter++;
	if(mscounter == 15 && firstTime == 1){
		mscounter = 0;
		PORTD = 0x00;
		firstTime = 0;
	} else if (mscounter == 25 && firstTime == 0){
		PORTD = 0x80;
		mscounter = 0;
		firstTime = 1;
	}
}

