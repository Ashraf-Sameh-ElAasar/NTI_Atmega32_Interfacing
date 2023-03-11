/*
 * SPI_TRANS.c
 *
 * Created: 1/21/2022 9:33:16 PM
 * Author : Doha
 */ 

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

int main(void)
{
	
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	I2C_Slave_voidInit(0x10);
	I2C_Error_State Error=I2C_OK;
	u8* Data=0;
	while (1)
	{
		I2C_Slave_voidListen();		
		Error=I2C_Slave_enuReadu8Data(Data);
		if( Error== I2C_OK && *Data =='H')
		{
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		
		}
		else if ( Error== I2C_OK && *Data =='L')
		{
			DIO_voidSetPinValue(PORTA,PIN0,LOW);
		}
	}
}


