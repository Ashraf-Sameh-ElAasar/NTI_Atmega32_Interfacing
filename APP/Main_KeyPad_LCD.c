/*
 * NTI_Atmega32_Interfacing.c
 *
 * Created: 3/6/2023 10:08:41 PM
 * Author : Ashraf
 */ 

#define F_CPU 16000000UL
#include "LCD_Int.h"
#include "KeyPad_Int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>



int main(void)
{
	u8 Key = 0;
	LCD_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		if(TRUE == keypad_bolIsPressed())
		{
			Key = keypad_u8GetKey();
			LCD_DisplayChar(Key);
		}
		else
		{
			//Do Nothing
		}
    }
}

