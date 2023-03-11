/*
 * EEPROM.c
 *
 * Created: 1/28/2023 9:32:48 PM
 *  Author: AMIT
 */ 
#define  F_CPU 1000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "I2C.h"
#include "EEPROM.h"
void EEPROM_INIT()
{
	I2C_Init();
}
void EEPROM_Write(char page , char add ,char data)
{
	char page_add = (page<<1)+0xA0;
	I2C_Start(page_add);			/* Start I2C with device write address */
	I2C_Write(add);					/* Write start memory address for data write */
	I2C_Write(data);
	_delay_ms(10);
	I2C_Stop();					/* Stop I2C */
}
char EEPROM_Read(char page , char add)
{
	char data =0; 
	char page_write_add = (page<<1)+0xA0;
	char page_read_add  = page_write_add + 1;
	_delay_ms(10);
	I2C_Start(page_write_add);							/* Start I2C with device write address */
	I2C_Write(add);							/* Write start memory address */
	I2C_Repeated_Start(page_read_add);			/* Repeat start I2C SLA+R */
	data = I2C_Read_Ack();
	I2C_Stop();		
	return data;							/* Stop I2C */
}