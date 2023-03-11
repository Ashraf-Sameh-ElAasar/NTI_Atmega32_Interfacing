/*
 * SevSeg_CFG.c
 *
 * Created: 3/9/2023 7:42:30 PM
 *  Author: Ashraf
 */ 

#include "SevSeg_CFG.h"

SEVSEG_CONFIG SevSegs[NUMBER_OF_SevSeg] = {
	{
		.Data_Port	=  PORTB,
		.Enable_Port=  PORTB,
		.SevSeg_A	=  PIN0,
		.SevSeg_B	=  PIN1,
		.SevSeg_C	=  PIN2,
		.SevSeg_D	=  PIN4,
		.SevSeg_EN	=  PIN6
	},				  
					  
	{				  
		.Data_Port	=  PORTB,
		.Enable_Port=  PORTB,
		.SevSeg_A	=  PIN0,
		.SevSeg_B	=  PIN1,
		.SevSeg_C	=  PIN2,
		.SevSeg_D	=  PIN4,
		.SevSeg_EN	=  PIN5
	},				  
					  
	{				  
		.Data_Port	=  PORTB,
		.Enable_Port=  PORTA,
		.SevSeg_A	=  PIN0,
		.SevSeg_B	=  PIN1,
		.SevSeg_C	=  PIN2,
		.SevSeg_D	=  PIN4,
		.SevSeg_EN	=  PIN2
	},				  
					  
	{				  
		.Data_Port	=  PORTB,
		.Enable_Port=  PORTA,
		.SevSeg_A	=  PIN0,
		.SevSeg_B	=  PIN1,
		.SevSeg_C	=  PIN2,
		.SevSeg_D	=  PIN4,
		.SevSeg_EN	=  PIN3
	}
};