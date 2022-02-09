/*
 * main.c
 *
 * Created: 9-2-2022 15:07:47
 *  Author: luca1
 */ 

#define F_CPU 8e6
#include "LCDmodule.h"
#include <util/delay.h>

int main(void){
	
	init();
	
	
	while(1){
		display_text("Hallooo");
		_delay_ms(1000);
		clear_screen();
		display_text("Bla bla");
		_delay_ms(1000);
		clear_screen();
	}
	
	return 0;
}