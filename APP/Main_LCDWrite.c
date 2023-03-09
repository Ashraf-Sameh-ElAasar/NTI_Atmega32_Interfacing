/*
 * NTI_Atmega32_Interfacing.c
 *
 * Created: 3/6/2023 10:08:41 PM
 * Author : Ashraf
 */ 

#define F_CPU 16000000UL
#include "LED_Int.h"
#include "PSH_BTN_Int.h"
#include "LCD_Int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>



int main(void)
{
	LED_voidINIT();
	BUTTON_voidInit();
	LCD_Init();
    /* Replace with your application code */
    while (1) 
    {
		LCD_DisplayChar('a');
		_delay_ms(1000);
		LCD_SendCmd(ClearLCD);
		_delay_ms(1000);
    }
}