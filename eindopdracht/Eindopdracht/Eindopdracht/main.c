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
#include "BM.h"

int speed = 0;

int main(void)
{
	
	
	

	/* Enable receiver and transmitter */
	//UCSR3B = (1<<RXEN2);
	/* Set frame format: 8data, 1stop bit */
	//UCSR3C = (0<<USBS3)|(3<<UCSZ03);
	SD_init();
	SD_set_drive_direction(STILL);
	BM_init();
	for(;;){
		BM_handle_data();
	}
		
}