/*
 * LM35_Inte.h
 *
 * Created: 3/12/2023 11:40:54 AM
 *  Author: Ashraf
 */ 


#ifndef LM35_INT_H_
#define LM35_INT_H_

#include "STD_TYPES.h"
#include "LM35_CFG.h"

void LM35_voidInit(void);

u16 LM35_ReadTemp(void);


#endif /* LM35_INT_H_ */