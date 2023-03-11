/*
 * I2C.c
 *
 * Created: 10/20/2022 8:00:51 PM
 * Author : ahmed
 */ 
#define F_CPU 1000000ul
#include <avr/io.h>
#include <math.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "I2C.h"
#include "EEPROM.h"

int main(void)
{
	I2C_Init();
    /* Replace with your application code */
    while (1) 
    {
		I2C_Start(0x20);
		I2C_Write(0x55);
		I2C_Repeated_Start(0x22);
		I2C_Write(0xBB);
		I2C_Stop();
		_delay_ms(1000);
    }
}

