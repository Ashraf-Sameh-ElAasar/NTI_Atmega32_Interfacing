/*
 * NTI_SPI_Slave.c
 *
 * Created: 3/5/2023 10:50:32 AM
 * Author : Ashraf
 */ 

#define F_CPU 16000000UL
#include "DIO.h"
#include "SPI_Int.h"
#include "LED.h"
#include "GIE_Int.h"
#include <util/delay.h>


int main(void)
{
	u8 data = 0;
	LED_INIT();
	//Please create a struct that can be inputted in the function below and be sure to set role as Slave
	SPI_VoidInit();
	//GIE_voidENABLE();
	/*LED_TOGGLE(LED_YELLOW);*/
	/* Replace with your application code */
	while (1)
	{
		data = SPI_u8SendRecData();
		
		if(data == 0)
		{
			//do nothing
		}
		else if (data == 'a')
		{
			LED_TOGGLE(LED_YELLOW);
			_delay_ms(1000);
		}
		else
		{
			LED_TOGGLE(LED_GREEN);
			_delay_ms(1000);
		}
	}
}
