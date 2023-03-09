/*
 * LCD_Prog.c
 *
 * Created: 3/9/2023 11:44:06 AM
 *  Author: Ashraf
 */ 


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#define F_CPU 16000000UL
#include "LCD_Int.h"
#include <util/delay.h>
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
		
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Description                                                                         
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LCD_SendCmd(lcd_Cmd_Type cmd)
{
	u8 i;
	for(i = 0; i < NUMBER_OF_LCDS; i++)
	{
		//Initializing LCD Data Port to Zero
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,STD_LOW);
		//Setting LCD to Command Mode
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].RS,STD_LOW);
		//Sending Higher nibble to Data Port
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,(CHECK_BIT(cmd,4)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,(CHECK_BIT(cmd,5)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,(CHECK_BIT(cmd,6)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,(CHECK_BIT(cmd,7)));
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_HIGH);
		_delay_us(1);
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_LOW);
		//Sending Lower nibble to Data Port
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,(CHECK_BIT(cmd,0)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,(CHECK_BIT(cmd,1)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,(CHECK_BIT(cmd,2)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,(CHECK_BIT(cmd,3)));
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_HIGH);
		_delay_us(1);
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_LOW);
		//Busy wait to allow LCD to process the command
		_delay_ms(2);
	}	
}
void LCD_SendData(u8 data)
{
	u8 i;
	for(i = 0; i < NUMBER_OF_LCDS; i++)
	{
		//Initializing LCD Data Port to Zero
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,STD_LOW);
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,STD_LOW);
		//Setting to LCD to data mode
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].RS,STD_HIGH);
		//Sending Higher nibble to Data Port
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,(CHECK_BIT(data,4)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,(CHECK_BIT(data,5)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,(CHECK_BIT(data,6)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,(CHECK_BIT(data,7)));
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_HIGH);
		_delay_us(1);
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_LOW);
		//Sending Lower nibble to Data Port
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,(CHECK_BIT(data,0)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,(CHECK_BIT(data,1)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,(CHECK_BIT(data,2)));
		dio_voidWriteChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,(CHECK_BIT(data,3)));
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_HIGH);
		_delay_us(1);
		dio_voidWriteChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,STD_LOW);
		//Busy wait to allow LCD to process the command
		_delay_ms(2);
	}
}
void LCD_DisplayChar(u8 chr)
{
	LCD_SendData(chr);
}
void LCD_DisplayStr(u8* str)
{
	while((*str))
		LCD_DisplayChar(*str++);	
}
void LCD_GoToRowColumn(u8 row, u8 column)
{
	u8 CursorPosition=0x80;
	switch(row)
	{
		case 0:
		CursorPosition=0x80;
		CursorPosition+=column;
		LCD_SendCmd(CursorPosition);
		break;
		case 1:CursorPosition=0xC0;
		CursorPosition+=column;
		LCD_SendCmd(CursorPosition);
		break;
		case 2:
		CursorPosition=0x94;
		CursorPosition+=column;
		LCD_SendCmd(CursorPosition);
		break;
		case 3:
		CursorPosition=0xD4;
		CursorPosition+=column;
		LCD_SendCmd(CursorPosition);
		break;
	}
}
void LCD_Init(void)
{
	u8 i;
	for(i = 0; i < NUMBER_OF_LCDS; i++)
	{
		//Setting Command Port Channels as OUTPUT
		dio_voidConfigChannel(LCDS[i].LCD_Command_PORT,LCDS[i].RS,OUTPUT);
		dio_voidConfigChannel(LCDS[i].LCD_Command_PORT,LCDS[i].EN,OUTPUT);
		//Setting Data Port Channels as OUTPUT
		dio_voidConfigChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D4,OUTPUT);
		dio_voidConfigChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D5,OUTPUT);
		dio_voidConfigChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D6,OUTPUT);
		dio_voidConfigChannel(LCDS[i].LCD_DATA_PORT,LCDS[i].D7,OUTPUT);
		//Returns Cursor To Home Position
		LCD_SendCmd(HomeReturn);
		//Starting LCD 4-bit 5*8 Matrix 2-line Mode
		LCD_SendCmd(MatrixFiveByTen);
		//Hiding Cursor
		LCD_SendCmd(HideCursor);
		//Clearing LCD
		LCD_SendCmd(ClearLCD);
	}
}
void LCD_voidDisplayNum(u16 num)
{
	u8 num_to_char_array[100], iterator = 0;
	while(num != 0)
	{
		num_to_char_array[iterator] = (u8)(num % 10);
		num /= 10;
		iterator++;
	}
	for(;iterator > 0; iterator--)
	{
		LCD_SendData('0' + (num_to_char_array[iterator-1]));
	}
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
