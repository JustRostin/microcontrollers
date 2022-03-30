/*
 * ServoDriver.h
 *
 * Created: 23-3-2022 14:47:34
 *  Author: luca1
 */ 

#ifndef SERVO_DRIVER
#define SERVO_DRIVER
#define F_CPU 16000000L // Specify oscillator frequency
#include <avr/io.h>
#include <util/delay.h>

	typedef enum {
			FORWARDS,
			BACKWARDS,
			LEFT,
			RIGHT,
			STILL
		}SD_Direction_t;

	/*
	* This method will initialize the servo driver
	*/
	void SD_init(void);
	
	/* 
	*
	* @param	servo is the servo to set the speed
	*			speed is the speed between 2250 and 750
	*/
	void SD_set_speed(int servo, int speed);
	
	/* 
	* 
	*/
	void SD_set_drive_direction(SD_Direction_t direction);
	
#endif