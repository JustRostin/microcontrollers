/*
 * Opdracht B4.c
 *
 * Created: 16-3-2022 10:54:58
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "LCDmodule.h"


int main(void)
{
	
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	ADMUX = 0b01100001;
	ADCSRA = 0b11100110;

	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = ADCL;
		PORTA = ADCH;		
		_delay_ms(500);
		
    }
}

