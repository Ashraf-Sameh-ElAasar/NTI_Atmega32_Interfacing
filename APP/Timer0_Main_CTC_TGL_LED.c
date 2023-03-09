/*
 * NTI_Timer0.c
 *
 * Created: 2/26/2023 11:05:06 AM
 * Author : Ashraf
 */ 
// IN Config
// Please enable TIMER0_NORMAL
// TIMER0_DIV_BY_1024
// TIMER0_NO_ACTION
#include "std_types.h"
#include "bit_math.h"
#include "TIMR0_int.h"
#include "led.h"
#include "TIMR00_priv.h"

u16 count = 0;

void toggle_led(void);
int main(void)
{
	TIMER0_void_SetCTCCallBack(toggle_led);
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(199);
	led_init();
	//TIMER0_void_EnableOVInt();
	TIMER0_void_EnableCTCInt();
	SET_BIT(SREG,7);
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}


void toggle_led(void)
{
	count++;
	if(count == 32)
	{
		led_toggle(LED_RED);
		count = 0;
	}
}