/*
 * ICU.c
 *
 * Created: 3/10/2023 10:45:03 AM
 * Author : Ashraf
 */ 

#define	F_CPU 8000000UL
#include <avr/io.h>
#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_Int.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include "TIMER0_int.h"
//#include <avr/interrupt.h>

#include "LCD_int.h"
#include <util/delay.h>



int firstReading = 1 ;
int ovf = 0 ;
int previousState = 0 ;
volatile unsigned char flag ;
int No_of_EXTI = 0;

float ton = 0 ;
float toff = 0 ;
void TOVF_APP (void)
//void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;
//void __vector_11 (void)
//ISR(TIMER0_OVF_vect)
{
	ovf++;
}
void EXTI0_APP (void)
//void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
//void __vector_1 (void)
//ISR(INT0_vect)
{
	if(No_of_EXTI == 0)
	{
		EXT0_voidSetSignalch(FALLING);
		TIMER0_void_setTCNT0(0);
	}
	else if(No_of_EXTI == 1)
	{
		
		EXT0_voidSetSignalch(RISING);
		ton = (TIMER0_void_getTCNT0() + (256 * ovf)) * ((float) 1024.0 / 8000000.0);
		TIMER0_void_intialization();
		ovf=0;
	}
	else if(No_of_EXTI == 2)
	{
		EXT0_voidSetSignalch(FALLING);
		toff = (TIMER0_void_getTCNT0() + (256 * ovf)) * ((float) 1024.0 / 8000000.0);
		TIMER0_void_intialization();
		ovf=0;
	}
	if(No_of_EXTI < 2)
	{
		No_of_EXTI++;
	}
	else
	{
		No_of_EXTI = 1;
	}
}




int main()
{
	TIMER0_OVERFLOW_void_setCallBack(TOVF_APP);
	EXT0_voidCallBack(EXTI0_APP);
	int duty = 0 ;
	int freq = 0 ;
	float f = 0 ;
	DIO_voidInitialization();
	EXT0_voidInit();
	LCD_vidInit();

	TIMER0_void_intialization();

	TIMER0_void_overflowInterruptEnable();

	EXT0_voidEnable();
	GIE_voidEnable();
	/*	pre 1024 .. mode CTC "Duty 50%" .. F = fcpu/(pre* counts) = 30.5 HZ	*/
	TCCR2 = 0b00011111;
	OCR2 = 127;

	while(1)
	{
		duty = (100 * ton) /( ton + toff);
		f = 1 / (ton + toff); // Tperiod = TON + TOFF
		freq = (int) f ;
		LCD_vidSendCmd(0x80);
		LCD_vidWriteString((u8 *)"Freq = ");
		LCD_vidWriteChar((freq/100)+48);
		LCD_vidWriteChar(((freq/10)%10)+48);
		LCD_vidWriteChar((freq%10)+48);
		LCD_vidWriteString((u8 *)" HZ");
		LCD_vidGotoXY(2 , 0);
		LCD_vidWriteString((u8 *)  "Duty = ");
		LCD_vidWriteChar(( duty / 10 ) + 48);
		LCD_vidWriteChar(( duty % 10) + 48);
		LCD_vidWriteChar(' ');
		LCD_vidWriteChar('%');
		//_delay_ms(500);
	}
	return 0;
}
