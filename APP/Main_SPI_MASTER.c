/*
 * NTI_SPI.c
 *
 * Created: 3/4/2023 1:15:31 PM
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
	//Please create a struct that can be inputted into the function below SPI_VoidInit as be sure to set role as master
	SPI_VoidInit();
	SPI_u8Enable();
	//GIE_voidENABLE();
    /* Replace with your application code */
	_delay_ms(500);
    while (1) 
    {
		SPI_u8SendRecData('a');
		_delay_ms(500);
		SPI_u8SendRecData('b');
		_delay_ms(2500);
    }
}



