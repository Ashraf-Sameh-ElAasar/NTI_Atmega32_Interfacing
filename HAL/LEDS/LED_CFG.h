/*
 * LED_CFG.h
 *
 * Created: 3/2/2023 5:52:50 PM
 *  Author: Ashraf
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "CFG.h"

#define NUMBER_OF_LEDS 4

typedef enum
{
	LED_RED ,
	LED_GREEN ,
	LED_BLUE ,
	LED_YELLOW
	}LED_ID;

typedef enum
{
	SOURCE ,
	SINK
	}LED_STATE;


typedef struct
{
	
	PORTx  Port ;
	PINx   Pin  ;
	LED_STATE  State;
	LED_ID Led_Num  ;
	}LED_CONFIG;

LED_CONFIG LEDS[NUMBER_OF_LEDS];

#endif /* LED_CFG_H_ */