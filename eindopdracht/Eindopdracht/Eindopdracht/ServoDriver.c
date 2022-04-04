/*
 * ServoDriver.c
 *
 * Created: 23-3-2022 14:47:17
 *  Author: luca1
 */ 
	#include "ServoDriver.h"
	#define SDFullSpeed 2000
	#define SDMinSpeed 800
	#define SDTurningFullL 1450
	#define SDTurningFullR 1550
	#define SDZeroSpeed 1500
	
	#define RightServo 1
	#define LeftServo 0
	
	SD_Direction_t currentDirection = STILL;
	
	/*
	* This method will initialize the servo driver
	*/
	void SD_init(void){
		DDRE = 0xFF;
		TCNT3 = 0;
		TCCR3A = 0b00101001;
		TCCR3B = 0b01010010;
		OCR3A = 20750;
		OCR3B = 1500;
		OCR3C = 1500;
	}
	
	/* 
	*
	* @param	servo is the servo to set the speed
	*			speed is the speed between 2250 and 750
	*/
	void SD_set_speed(int servo, int speed){
		if(servo == LeftServo){
			OCR3B = speed;
		} else if(servo == RightServo){
			OCR3C = speed;
		}
		TCNT3 = 0;
	}
	
	/* 
	* sets the driver to drive a certain direction
	*/
	void SD_set_drive_direction(SD_Direction_t direction){
		if(currentDirection != direction){
			switch (direction){
				case FORWARDS:
				SD_set_speed(LeftServo, SDMinSpeed);
				SD_set_speed(RightServo, SDFullSpeed);
				break;
				case BACKWARDS:
				SD_set_speed(LeftServo, SDFullSpeed);
				SD_set_speed(RightServo, SDMinSpeed);
				break;
				case LEFT:
				SD_set_speed(RightServo, SDZeroSpeed);
				SD_set_speed(LeftServo, SDTurningFullL);
				break;
				case RIGHT:
				SD_set_speed(LeftServo, SDZeroSpeed);
				SD_set_speed(RightServo, SDTurningFullR);
				break;
				case STILL:
				SD_set_speed(LeftServo, SDZeroSpeed);
				SD_set_speed(RightServo, SDZeroSpeed);
				break;
			}
		} else {
			SD_set_speed(LeftServo, SDZeroSpeed);
			SD_set_speed(RightServo, SDZeroSpeed);
		}
		currentDirection = direction;
	
	}