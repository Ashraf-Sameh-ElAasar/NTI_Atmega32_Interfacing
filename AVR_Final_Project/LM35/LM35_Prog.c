/*
 * LM35_Prog.c
 *
 * Created: 3/12/2023 11:39:31 AM
 *  Author: Ashraf
 */ 


#include "ADC_int.h"
#include "LM35_Int.h"

void LM35_voidInit(void)
{
	ADC_voidInit();
	/*ADC_voidStartConversion(); //Made BY ABDO*/
	
}

u16 LM35_ReadTemp(void)
{
	u16 ValueInmV = ADC_u16ReadADCInMV(LM35_PIN);
	
	u16 ValueCelsius = ValueInmV / 2.5;
	
	return ValueCelsius;
}