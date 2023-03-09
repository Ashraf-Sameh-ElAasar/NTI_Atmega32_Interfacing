/*
 * Unipolar_Stepper_Motor_Prog.c
 *
 * Created: 3/9/2023 11:09:29 PM
 *  Author: Ashraf
 */ 

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "DIO.h"
#include "Unipolar_Stepper_Motor_Config.h"
#include "Unipolar_Stepper_Motor_Int.h"
#include <util/delay.h>


void uStep_Motor_voidInit(void)
{
	u8 i;
	for(i = 0 ; i < NUMBER_OF_STEPPER_MOTORS ; i++ )
	{
		// OutPut Pins
		dio_voidConfigChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1, OUTPUT);
		dio_voidConfigChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2, OUTPUT);
		dio_voidConfigChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3, OUTPUT);
		dio_voidConfigChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4, OUTPUT);
		// Clear Pins
		dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
		dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
		dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
		dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
	}
}

void uStep_Motor_voidRotate_Clock(u8 Stepper_Motor_Num, u16 StepCount)
{
	u8 i;
	for(i = 0 ; i < StepCount ; i++ ){
		
		switch (CONFIG_Stepper_Motor[Stepper_Motor_Num].Mode){
			
			case Full :
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			break ;
			
			case Half :
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			
			_delay_ms(5);
			break;
			
			
		}
		
	}
}
void uStep_Motor_voidRotate_Anti_Clock(u8 Stepper_Motor_Num, u16 StepCount)
{
	u8 i;
	for(i = 0 ; i < StepCount ; i++ )
	{
		
		switch (CONFIG_Stepper_Motor[Stepper_Motor_Num].Mode)
		{
			
			case Full :
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			_delay_ms(5);
			break ;
			
			case Half :
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_LOW);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_HIGH);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			_delay_ms(5);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin1 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin2 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin3 , STD_LOW);
			dio_voidWriteChannel(CONFIG_Stepper_Motor[i].Port , CONFIG_Stepper_Motor[i].Pin4 , STD_HIGH);
			_delay_ms(5);
			break;
			
			
		}
		
	}
}