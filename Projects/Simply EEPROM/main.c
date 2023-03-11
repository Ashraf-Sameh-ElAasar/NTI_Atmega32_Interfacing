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
/////////////////////////////////////////////////EEPROM without function////////////////////////////////////////////////////////////////


int main(void)
{


	I2C_Init();			/* Initialize I2C */
	DDRA = 0xff ;
	while(1)
	{
		///////////////////////////////send 0xAA //////////////////////////////////
		I2C_Start(0xA0); /* Start I2C with device write address */
		I2C_Write(0x11);		/* Write start memory address for data write */
		I2C_Write(0xAA);       // 1010 1010     --> 0101 0101
		I2C_Stop();			/* Stop I2C */
		_delay_ms(1000);
		I2C_Start(0xA0);         /* Start I2C with device write address */
		I2C_Write(0x11);		/* Write start memory address */
		I2C_Repeated_Start(0xA1);/* Repeat start I2C SLA+R */
		PORTA = I2C_Read_Ack();
		I2C_Stop();			/* Stop I2C */
		//////////////////////////////send 0x55 ///////////////////////////////////////
		_delay_ms(1000);
		I2C_Start(0xA0);/* Start I2C with device write address */
		I2C_Write(0x11);		/* Write start memory address for data write */
		I2C_Write(0x55);
		I2C_Stop();			/* Stop I2C */
		_delay_ms(1000);
		I2C_Start(0xA0);/* Start I2C with device write address */
		I2C_Write(0x11);		/* Write start memory address */
		I2C_Repeated_Start(0xA1);/* Repeat start I2C SLA+R */
		PORTA = I2C_Read_Ack();
		I2C_Stop();			/* Stop I2C */
		_delay_ms(1000);
	}
	return 0;
}

/////////////////////////////////////////////////EEPROM with function////////////////////////////////////////////////////////////////

/*
int main()
{
	EEPROM_INIT();		/ * Initialize EEPROM * /
	DDRA = 0xff ;
	char data =0;
	while(1)
	{
		EEPROM_Write(1,0x12,0xAA);
		data = EEPROM_Read(1,0x12);
		PORTA = data ;
		_delay_ms(1000);
		EEPROM_Write(0,0x12,0x55);
		data = EEPROM_Read(0,0x12);
		PORTA = data ;
		_delay_ms(1000);
		
	}
	return 1 ;
}*/