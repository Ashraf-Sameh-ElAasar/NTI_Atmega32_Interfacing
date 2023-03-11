/*
 * EEPROM_Prog.c
 *
 * Created: 3/11/2023 10:57:22 AM
 *  Author: Ashraf
 */ 

#include "EEPROM_Int.h"
#include "EEPROM_Priv.h"

void EEPROM_Write(u16 u16Address, u8 u8Data)
{
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = u16Address;
	EEDR = u8Data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

u8 EEPROM_Read(u16 u16Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = u16Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}