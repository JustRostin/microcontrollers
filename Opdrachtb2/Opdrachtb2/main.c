/*
 * main.c
 *
 * Created: 2/2/2022 2:07:46 PM
 *  Author: luca1
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	DDRD = 0xFF;
	
    while(1)
    {
        PORTD = 0x80;
		wait(500);
		PORTD = 0x40;
		wait(500);
    }
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