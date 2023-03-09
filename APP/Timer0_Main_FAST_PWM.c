/*
 * NTI_Timer0.c
 *
 * Created: 2/26/2023 11:05:06 AM
 * Author : Ashraf
 */ 
#define F_CPU 16000000UL
#include "dio.h"
#include "std_types.h"
#include "bit_math.h"
#include "TIMR0_int.h"
#include "led.h"
#include "TIMR00_priv.h"
#include "util/delay.h"

/*u16 count = 0;*/

/*void toggle_led(void);*/
int main(void)
{
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);
	//TIMER0_void_SetCTCCallBack(toggle_led);
	TIMER0_void_Init();
	
	led_init();
	//TIMER0_void_EnableOVInt();
	//TIMER0_void_EnableCTCInt();
	/*SET_BIT(SREG,7);*/
	
	
    /* Replace with your application code */
    while (1) 
    {
		for (u8 i = 0 ; i < 255 ; i++)
		{
			TIMER0_void_SetCompareVal(i);
			_delay_ms(8);
		}
    }
}


/*
void toggle_led(void)
{
	count++;
	if(count == 32)
	{
		led_toggle(LED_RED);
		count = 0;
	}
}*/

