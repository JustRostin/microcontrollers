/*
 * main.c
 *
 * Created: 2/2/2022 2:13:32 PM
 *  Author: luca1
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
    while(1)
    {
		
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