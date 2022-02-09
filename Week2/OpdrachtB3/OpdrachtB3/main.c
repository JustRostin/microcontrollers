/*
 * OpdrachtB3.c
 *
 * Created: 9-2-2022 12:05:08
 * Author : luca1
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void display(int digit);

int number[] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
	0b01110111,
	0b01111100,
	0b00111001,
	0b01011110,
	0b01111001,
	0b01110001
	};
	
	void wait(int ms);

int currentNumber;

int main(void)
{
	/* setup */
	DDRC = 0xFF;
	DDRD = 0x00;
	EICRA |= 0x0F;
	EIMSK |= 0x3;
	sei();
	currentNumber = 0;
	display(currentNumber);
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}



ISR(INT0_vect){
	currentNumber++;
	display(currentNumber);
	wait(5);
}

ISR(INT1_vect){
	currentNumber--;
	display(currentNumber);
	wait(5);
}

/* waits a certain amount of time */
void wait(int ms){
	for(int i = 0; i < ms; i++){
		_delay_ms(1);
	}
}

/* sets the display to a certain digit */
void display(int digit){
	if(digit >= 16){
		PORTC = number[14];
		} else {
		PORTC = number[digit];
	}
}
