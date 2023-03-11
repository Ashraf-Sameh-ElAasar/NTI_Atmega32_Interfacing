/*
 * PSH_BTN_CFG.h
 *
 * Created: 3/8/2023 2:21:05 PM
 *  Author: Ashraf
 */ 


#ifndef PSH_BTN_CFG_H_
#define PSH_BTN_CFG_H_

#include "CFG.h"


#define NUMBER_OF_BUTTONS 4
	
typedef enum
{
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4
	}BUTTON_ID;
typedef enum
{
	PULLDOWN,
	PULLUP
	}BUTTON_STATE;
	
typedef enum
{
	RELEASED,
	PRESSED
	}BUTTON_STATUS;
	
typedef enum
{
	PHYSICAL,
	SOFTWARE
	}BUTTON_SETUP;

typedef struct  
{
	PORTx Port;
	PINx Pin;
	BUTTON_STATE State;
	BUTTON_ID Button_Num;
	BUTTON_SETUP Setup;
}BUTTONS_CONFIG;



BUTTONS_CONFIG BTNS[NUMBER_OF_BUTTONS];

#endif /* PSH_BTN_CFG_H_ */