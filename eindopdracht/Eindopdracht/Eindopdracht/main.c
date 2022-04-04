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

int main(void)
{
	SD_init();
	SD_set_drive_direction(STILL);
	BM_init();
	for(;;){
		BM_handle_data();
	}
		
}