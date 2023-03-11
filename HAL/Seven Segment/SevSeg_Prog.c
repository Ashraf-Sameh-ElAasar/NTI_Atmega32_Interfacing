/*
 * SevSeg_Prog.c
 *
 * Created: 3/9/2023 7:43:04 PM
 *  Author: Ashraf
 */ 

#define F_CPU 16000000UL
#include "SevSeg_CFG.h"
#include "SevSeg_Int.h"
#include "DIO.h"
#include <util/delay.h>

void SevSeg_voidInit()
{
	u8 iterations;
	for(iterations = 0; iterations < NUMBER_OF_SevSeg; iterations++)
	{
		dio_voidConfigChannel(SevSegs[iterations].Data_Port,SevSegs[iterations].SevSeg_A,OUTPUT);
		dio_voidConfigChannel(SevSegs[iterations].Data_Port,SevSegs[iterations].SevSeg_B,OUTPUT);
		dio_voidConfigChannel(SevSegs[iterations].Data_Port,SevSegs[iterations].SevSeg_C,OUTPUT);
		dio_voidConfigChannel(SevSegs[iterations].Data_Port,SevSegs[iterations].SevSeg_D,OUTPUT);
		
		
		dio_voidConfigChannel(SevSegs[iterations].Enable_Port,SevSegs[iterations].SevSeg_EN,OUTPUT);
	}
}
void SevSeg_DisplayNum(u16 num)
{
	u8 thous = num / 1000;
	u8 hund = num % 1000 / 100;
	u8 tenth = num %1000 %100 /10;
	u8 units = num %1000 %100 % 10;
	//Disabling All SevSeg Enables
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[3].Enable_Port,SevSegs[3].SevSeg_EN,STD_LOW);
	
	//Enabling First SevSeg
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_HIGH);
	
	//Printing The Thousands SevSeg
	dio_voidWriteChannel(SevSegs[0].Data_Port,SevSegs[0].SevSeg_A,CHECK_BIT(thous,0)) ;
	dio_voidWriteChannel(SevSegs[1].Data_Port,SevSegs[1].SevSeg_B,CHECK_BIT(thous,1)) ;
	dio_voidWriteChannel(SevSegs[2].Data_Port,SevSegs[2].SevSeg_C,CHECK_BIT(thous,2)) ;
	dio_voidWriteChannel(SevSegs[3].Data_Port,SevSegs[3].SevSeg_D,CHECK_BIT(thous,3)) ;
	
	_delay_ms(5);
	//Disabling First SevSeg
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_LOW);
	
	
	//Enabling Second SevSeg
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_HIGH);
	//Printing The Hundreds SevSeg
	dio_voidWriteChannel(SevSegs[0].Data_Port,SevSegs[0].SevSeg_A,CHECK_BIT(hund,0)) ;
	dio_voidWriteChannel(SevSegs[1].Data_Port,SevSegs[1].SevSeg_B,CHECK_BIT(hund,1)) ;
	dio_voidWriteChannel(SevSegs[2].Data_Port,SevSegs[2].SevSeg_C,CHECK_BIT(hund,2)) ;
	dio_voidWriteChannel(SevSegs[3].Data_Port,SevSegs[3].SevSeg_D,CHECK_BIT(hund,3)) ;
	
	_delay_ms(5);
	//Disabling Second SevSeg
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_LOW);
	
	//Enabling Third SevSeg
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_HIGH);
	
	//Printing The Tenth SevSeg
	dio_voidWriteChannel(SevSegs[0].Data_Port,SevSegs[0].SevSeg_A,CHECK_BIT(tenth,0)) ;
	dio_voidWriteChannel(SevSegs[1].Data_Port,SevSegs[1].SevSeg_B,CHECK_BIT(tenth,1)) ;
	dio_voidWriteChannel(SevSegs[2].Data_Port,SevSegs[2].SevSeg_C,CHECK_BIT(tenth,2)) ;
	dio_voidWriteChannel(SevSegs[3].Data_Port,SevSegs[3].SevSeg_D,CHECK_BIT(tenth,3)) ;
	
	_delay_ms(5);
	//Disabling Third SevSeg
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_LOW);
	
	//Enabling Fourth SevSeg
	dio_voidWriteChannel(SevSegs[3].Enable_Port,SevSegs[3].SevSeg_EN,STD_HIGH);
	
	
	//Printing The Units SevSeg
	dio_voidWriteChannel(SevSegs[0].Data_Port,SevSegs[0].SevSeg_A,CHECK_BIT(units,0)) ;
	dio_voidWriteChannel(SevSegs[1].Data_Port,SevSegs[1].SevSeg_B,CHECK_BIT(units,1)) ;
	dio_voidWriteChannel(SevSegs[2].Data_Port,SevSegs[2].SevSeg_C,CHECK_BIT(units,2)) ;
	dio_voidWriteChannel(SevSegs[3].Data_Port,SevSegs[3].SevSeg_D,CHECK_BIT(units,3)) ;
	
	_delay_ms(5);
	//Disabling Fourth SevSeg
	dio_voidWriteChannel(SevSegs[3].Enable_Port,SevSegs[3].SevSeg_EN,STD_LOW);
}