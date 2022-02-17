/*
 * OpdrachtB1.c
 *
 * Created: 16-2-2022 12:14:39
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCDmodule.h"

int counter = 0;

int main(void)
{
	DDRD = 0x00;
	TIMSK = 0x80;
	OCR2 = 1;
	sei();
	TCCR2 = 0x07;
	TCNT2 = 0;
	
	init();
	clear_screen();
	lcd_write_string("Hallo");
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

/* Compaires the  */
ISR(TIMER2_COMP_vect){
	counter++;
	TCNT2 = 0;
	clear_screen();
	char stringInt[30] = "";
	sprintf(stringInt, "C: %d", counter);
	lcd_write_string(stringInt);
}

