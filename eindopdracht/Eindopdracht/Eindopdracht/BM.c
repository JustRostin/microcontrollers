/*
 * BM.c
 *
 * Created: 31-3-2022 11:25:55
 *  Author: luca1
 */ 

#include "BM.h"

void BM_init(void){
	UBRR3 = 8;
	UCSR3B = 0b00010000;
	UCSR3C = 0b00001110;
}

void BM_handle_data(void){
	while(!(UCSR3A & (1<<RXC3))){PINA = UCSR3A;};
	unsigned char dummy = UDR3;
	
	if(dummy == 0b00000001){
		SD_set_drive_direction(FORWARDS);
	} else if(dummy == 0b00000011){
		SD_set_drive_direction(LEFT);
	} else if(dummy == 0b00000111){
		SD_set_drive_direction(RIGHT);
	} else if(dummy == 0b00001111){
		SD_set_drive_direction(STILL);
	}
}