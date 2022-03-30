/*
 * OpdrachtB1.c
 *
 * Created: 23-2-2022 12:54:44
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

void initADC();
int main(void)
{
	DDRF = 0x00;
	DDRA = 0xFF;
	initADC();
    /* Replace with your application code */
    while (1) 
    {
		ADCSRA |= 0x40;
		while(ADCSRA & 0x40);
		PORTA = ADCH;
		_delay_ms(100);
    }
}

void initADC(){
	ADMUX = 0b01100011;
	ADCSRA = 0b10000110;
}

