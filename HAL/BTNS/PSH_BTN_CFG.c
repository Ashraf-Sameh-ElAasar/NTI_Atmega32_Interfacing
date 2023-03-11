/*
 * PSH_BTN_CFG.c
 *
 * Created: 3/8/2023 2:21:20 PM
 *  Author: Ashraf
 */ 


#include "PSH_BTN_CFG.h"

BUTTONS_CONFIG BTNS[NUMBER_OF_BUTTONS]= {
	{
		.Port = PORTD,
		.Pin = PIN7,
		.State = PULLUP,
		.Button_Num = BUTTON1,
		.Setup = PHYSICAL
	},
	
	{
		.Port = PORTD,
		.Pin = PIN6,
		.State = PULLUP,
		.Button_Num = BUTTON2,
		.Setup = PHYSICAL
	},
	
	{
		.Port = PORTD,
		.Pin = PIN5,
		.State = PULLUP,
		.Button_Num = BUTTON3,
		.Setup = PHYSICAL
	},
	
	{
		.Port = PORTD,
		.Pin = PIN3,
		.State = PULLUP,
		.Button_Num = BUTTON4,
		.Setup = PHYSICAL
	}
};