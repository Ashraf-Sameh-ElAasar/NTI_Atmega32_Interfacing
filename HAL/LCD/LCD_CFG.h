/*
 * LCD_CFG.h
 *
 * Created: 3/9/2023 11:43:11 AM
 *  Author: Ashraf
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "CFG.h"

#define NUMBER_OF_LCDS	1

typedef enum{
	HomeReturn=0x02,
	ClearLCD=0x01,
	DisplayCursor=0x0E,
	HideCursor=0x0C,
	MatrixFiveByTen=0x28
}lcd_Cmd_Type;

typedef struct {
	PORTx LCD_Command_PORT ;
	PORTx LCD_DATA_PORT ;
	PINx  EN ;
	PINx  RS ;
	PINx  D4 ;
	PINx  D5 ;
	PINx  D6 ;
	PINx  D7 ;
}LCD_CONFIG;


LCD_CONFIG LCDS[NUMBER_OF_LCDS];




#endif /* LCD_CFG_H_ */