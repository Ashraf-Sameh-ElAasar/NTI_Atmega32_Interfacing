/*
 * LCD_CFG.c
 *
 * Created: 3/9/2023 11:43:29 AM
 *  Author: Ashraf
 */ 

#include "LCD_CFG.h"

LCD_CONFIG LCDS[NUMBER_OF_LCDS] = {
	{
		.LCD_Command_PORT = PORTA,
		.LCD_DATA_PORT    = PORTB,
		.D4               = PIN0,
		.D5               = PIN1,
		.D6               = PIN2,
		.D7               = PIN4,
		.EN               = PIN2,
		.RS               = PIN3
	}
};