/*
 * NTI_Atmega32_Interfacing.c
 *
 * Created: 3/6/2023 10:08:41 PM
 * Author : Ashraf
 */ 

#define F_CPU 16000000UL
#include "LED_Int.h"
#include "PSH_BTN_Int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>



int main(void)
{
	LED_voidINIT();
	BUTTON_voidInit();
    /* Replace with your application code */
    while (1) 
    {
		if(BUTTON_StatusGetPress(BUTTON1))
		{
			LED_voidTOGGLE(LED_YELLOW);
			while(BUTTON_StatusGetPress(BUTTON1));
		}
		
		else if(BUTTON_StatusGetPress(BUTTON2))
		{
			LED_voidTOGGLE(LED_BLUE);
			while(BUTTON_StatusGetPress(BUTTON2));
		}
		
		else if(BUTTON_StatusGetPress(BUTTON3))
		{
			LED_voidTOGGLE(LED_GREEN);
			while(BUTTON_StatusGetPress(BUTTON3));
		}
		
		else if(BUTTON_StatusGetPress(BUTTON4))
		{
			LED_voidTOGGLE(LED_RED);
			while(BUTTON_StatusGetPress(BUTTON4));
		}
		
    }
}

