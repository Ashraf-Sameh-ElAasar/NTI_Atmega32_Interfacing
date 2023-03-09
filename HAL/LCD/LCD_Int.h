/*
 * LCD_Int.h
 *
 * Created: 3/9/2023 11:43:45 AM
 *  Author: Ashraf
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "STD_TYPES.h"
#include "LCD_CFG.h"

void LCD_Init(void);
void LCD_SendData(u8 data);
void LCD_SendCmd(lcd_Cmd_Type cmd);
void LCD_GoToRowColumn(u8 row, u8 column);
void LCD_DisplayChar(u8 chr);
void LCD_DisplayStr(u8* str);
void LCD_CustomWrite(u8* custCfg);
void LCD_voidDisplayNum(u16 num);




#endif /* LCD_INT_H_ */