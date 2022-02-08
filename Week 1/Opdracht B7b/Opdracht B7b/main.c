/*
 * main.c
 *
 * Created: 2/8/2022 2:17:33 PM
 *  Author: luca1
 */ 

#define F_CPU 8e6

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

typedef struct{
	int io;
	int value;
	}TYPE_DEF;

TYPE_DEF type[] = {
	{0b00001100, 0b00001000},
	{0b00001100, 0b00000100},
	{0b00000110, 0b00000100},
	{0b00000110, 0b00000010},
	{0b00001010, 0b00000010},
	{0b00001010, 0b00001000}
};

int main(void)
{
    while(1)
    {
		for(int i = 1; i <= 6; i++){
        setCharliePlexingLed(i);
		wait(1000);
		}
    }
}

void setCharliePlexingLed(int lednr){
	
	DDRA = type[lednr -1].io;
	PORTA = type[lednr -1].value;
	
	
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