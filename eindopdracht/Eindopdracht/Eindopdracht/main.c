/*
 * Eindopdracht.c
 *
 * Created: 16-3-2022 15:04:39
 * Author : luca1
 */ 

#define F_CPU 16000000L // Specify oscillator frequency
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ServoDriver.h"

int main(void)
{
	
	DDRA = 0xFF;
	DDRC = 0xFF;
	UBRR3 = 8;
	UCSR3B = 0b00010000;
	UCSR3C = 0b00001110;
	

	/* Enable receiver and transmitter */
	//UCSR3B = (1<<RXEN2);
	/* Set frame format: 8data, 1stop bit */
	//UCSR3C = (0<<USBS3)|(3<<UCSZ03);
	SD_init();
	

	for(;;){
		while(!(UCSR3A & (1<<RXC3))){PINA = UCSR3A;};
		//PINA = UCSR1A;
		unsigned char dummy = UDR3;
		
		PINC = dummy;
		
		if(dummy == 0b00000001){
			SD_set_drive_direction(FORWARDS);
		} else if(dummy == 0b00000011){
			SD_set_drive_direction(LEFT);
		} else if(dummy == 0b00000111){
			SD_set_drive_direction(RIGHT);
		} else if(dummy == 0b00001111){
			SD_set_drive_direction(BACKWARDS);
		}
		
	}
		
}