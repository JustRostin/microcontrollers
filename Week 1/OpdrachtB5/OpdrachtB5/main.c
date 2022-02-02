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

#define timeDelay 800

typedef struct {
		char state;
		int delay;
	} STATE_AND_DELAY_STRUCT;

STATE_AND_DELAY_STRUCT pattern[] = {
	{0x01, timeDelay}, {0x03, timeDelay}, {0x07, timeDelay}, {0x0F, timeDelay}, {0x1F, timeDelay}, {0x3F, timeDelay}, {0x7F, timeDelay},{0xFF, timeDelay}, {0x7F, timeDelay}, {0x3F, timeDelay}, {0x1F, timeDelay}, {0x0F, timeDelay}, {0x07, timeDelay}, {0x03, timeDelay}, {0x01, timeDelay},{0x00, 0x00}
	
	};

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
    while(1)
    {
		int index = 0;
		while(pattern[index].delay > 0){
			PORTA = pattern[index].state;
			PORTB = pattern[index].state;
			PORTC = pattern[index].state;
			PORTD = pattern[index].state;
			
			wait(pattern[index].delay);
			index++;
		}
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