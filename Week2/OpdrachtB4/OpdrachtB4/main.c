/*
 * OpdrachtB4.c
 *
 * Created: 9-2-2022 13:03:07
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

char pattern[] = {
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000,
	0b00010000,
	0b00100000,
	0b00000001,
	0b01000000,
	0b00001000
};

int main(void)
{
	DDRC = 0xFF;
	int sizeofArray = sizeof(pattern) / sizeof(pattern[0]);
    /* Replace with your application code */
    while (1) 
    {
		for(int i = 0; i < sizeofArray; i++){
			PORTC = pattern[i];
			wait(200);
		}
    }
}

void wait(int ms){
	for(int i = 0; i < ms; i++){
		_delay_ms(1);
	}
}

