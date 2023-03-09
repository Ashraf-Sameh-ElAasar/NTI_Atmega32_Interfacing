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
	u8 i;
	for(i = 0; i < NUMBER_OF_SevSeg; i++)
	{
		dio_voidConfigChannel(SevSegs[i].Data_Port,SevSegs[i].SevSeg_A,OUTPUT);
		dio_voidConfigChannel(SevSegs[i].Data_Port,SevSegs[i].SevSeg_B,OUTPUT);
		dio_voidConfigChannel(SevSegs[i].Data_Port,SevSegs[i].SevSeg_C,OUTPUT);
		dio_voidConfigChannel(SevSegs[i].Data_Port,SevSegs[i].SevSeg_D,OUTPUT);
		
		
		dio_voidConfigChannel(SevSegs[i].Enable_Port,SevSegs[i].SevSeg_EN,OUTPUT);
	}
}
void SevSeg_DisplayNum(u16 num)
{
	u8 thous = num / 1000;
	u8 hund = num % 1000 / 100;
	u8 tenth = num %1000 %100 /10;
	u8 units = num %1000 %100 % 10;
	
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[3].Enable_Port,SevSegs[3].SevSeg_EN,STD_LOW);
	
	
	if(thous > 7)
	/*if(thous % 4 == 0 || thous == 9 )*/
	{
		DIO_PORTB_REG = thous + 8;
	}
	else
	{
		DIO_PORTB_REG = thous;
	}
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_HIGH);
	_delay_us(10);
	
	
	
	
	if(hund > 7)
	/*if(hund % 4 == 0 || hund == 9 )*/
	{
		DIO_PORTB_REG = hund + 8;
	}
	else
	{
		DIO_PORTB_REG = hund;
	}
	dio_voidWriteChannel(SevSegs[0].Enable_Port,SevSegs[0].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_HIGH);
	//SEVSEG_Disable1();
	//SEVSEG_Enable2();
	_delay_us(10);
	
	
	
	
	
	if(tenth > 7)
	/*if(tenth % 4 == 0 || tenth == 9 )*/
	{
		DIO_PORTB_REG = tenth + 8;
	}
	else
	{
		DIO_PORTB_REG = tenth;
	}
	dio_voidWriteChannel(SevSegs[1].Enable_Port,SevSegs[1].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_HIGH);
	_delay_us(10);
	
	
	if(units > 7)
	/*if(units % 4 == 0 || units == 9 )*/
	{
		DIO_PORTB_REG = units + 8;
	}
	else
	{
		DIO_PORTB_REG = units;
	}
	dio_voidWriteChannel(SevSegs[2].Enable_Port,SevSegs[2].SevSeg_EN,STD_LOW);
	dio_voidWriteChannel(SevSegs[3].Enable_Port,SevSegs[3].SevSeg_EN,STD_HIGH);
	_delay_us(10);
}