/*
 * LED_CFG.c
 *
 * Created: 3/2/2023 5:53:06 PM
 *  Author: Ashraf
 */ 



#include "LED_CFG.h"

LED_CONFIG LEDS[NUMBER_OF_LEDS]  = {
	
	{
		.Port = PORTB ,
		.Pin  = PIN7  ,
		.State = SOURCE ,
		.Led_Num   = LED_RED
		
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN5  ,
		.State = SOURCE ,
		.Led_Num   = LED_BLUE
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN4  ,
		.State = SOURCE ,
		.Led_Num   = LED_GREEN
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN6  ,
		.State = SOURCE ,
		.Led_Num   = LED_YELLOW
	}
	
};