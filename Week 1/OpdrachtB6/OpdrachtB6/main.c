/*
 * main.c
 *
 * Created: 2/2/2022 3:03:56 PM
 *  Author: luca1
 */ 
#define F_CPU 8e6

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);
void checkForButton();
typedef enum {false, true} Boolean; 

Boolean isBlinkingFast = false;
Boolean released = true;

int main(void)
{
	/* sets the input and output params */
	DDRD = 0xFF;
	DDRC = 0x00;
	
    while(1)
    {
		/*turns the light on */
		PORTD = 0x80;
		wait(50);
		checkForButton();
		PORTD = 0x00;
		if(isBlinkingFast == true){
			wait(250);
		} else {
			wait(1000);
		}
		checkForButton();
		
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

void checkForButton(){
	/* checks if the button is on and if it is released */
	if(PINC == 0x00 && released == true){
		released = false;
		if(isBlinkingFast == false){
			isBlinkingFast = true;
			} else {
			isBlinkingFast = false;
		}
	}
	
	if (PINC == 0x01 && released == false)
	{
		released = true;
	}
}