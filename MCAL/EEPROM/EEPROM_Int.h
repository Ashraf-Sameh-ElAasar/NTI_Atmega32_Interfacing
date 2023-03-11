/*
 * EEPROM_Int.h
 *
 * Created: 3/11/2023 10:55:36 AM
 *  Author: Ashraf
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include "STD_TYPES.h"

void EEPROM_Write(u16 u16address, u8 u8Data);

u8 EEPROM_Read(u16 u16address);



#endif /* EEPROM_INT_H_ */