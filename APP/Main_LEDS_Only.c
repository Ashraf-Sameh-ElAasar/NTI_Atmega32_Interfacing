/*
 * NTI_Atmega32_Interfacing.c
 *
 * Created: 3/6/2023 10:08:41 PM
 * Author : Ashraf
 */ 

#define F_CPU 16000000UL
#include "LED_Int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>



int main(void)
{
	LED_voidINIT();
    /* Replace with your application code */
    while (1) 
    {
		LED_voidTOGGLE(LED_YELLOW);
		LED_voidTOGGLE(LED_BLUE);
		LED_voidTOGGLE(LED_GREEN);
		LED_voidTOGGLE(LED_RED);
		_delay_ms(1500);
    }
}

