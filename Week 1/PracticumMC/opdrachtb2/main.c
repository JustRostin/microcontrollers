/*
 * main.c
 *
 * Created: 2-2-2022 12:51:20
 * Author: Luca
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

/*Main function that will turn a LED on when the button is pressed */
int main( void ){
	DDRD = 0b11111111;
	DDRC = 0b00000000;
		
	while(1){
		if(PINC == 0x01){
			PORTD = 0x01;
			wait(500);
			PORTD = 0x00;
			wait(500);
		}
	}
	return 0;
}

void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
*******************************************************************/
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}