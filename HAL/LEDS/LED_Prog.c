/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LED_Prog.c			     			*/
/****************************************************************/

#include "LED_CFG.h"
#include "LED_Int.h"
#include "DIO.h"

void LED_voidINIT ( void )
{
	u8 i;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++ )
	{
		dio_voidConfigChannel(LEDS[i].Port , LEDS[i].Pin, OUTPUT );
	}
}


void LED_voidON ( LED_ID led_col )
{
	u8 i;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if( led_col == LEDS[i].Led_Num )
		{
			switch( LEDS[i].State )
			{
				case SOURCE :  dio_voidWriteChannel(LEDS[i].Port , LEDS[i].Pin , STD_HIGH );
				break ;
				case SINK   :  dio_voidWriteChannel(LEDS[i].Port , LEDS[i].Pin , STD_LOW );
				break ;
			}
		}
	}	
}


void LED_voidOFF ( LED_ID led_col)
{
	u8 i ;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if(led_col == LEDS[i].Led_Num)
		{
			switch(LEDS[i].State)
			{
				case SOURCE :  dio_voidWriteChannel(LEDS[i].Port , LEDS[i].Pin , STD_LOW ); 
				break ;
				case SINK   :  dio_voidWriteChannel(LEDS[i].Port , LEDS[i].Pin , STD_HIGH ); 
				break ;
			}
		}
	}

	
	
}
void LED_voidTOGGLE ( LED_ID led_col)
{
	u8 i ;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if(led_col == LEDS[i].Led_Num)
		{
			dio_voidFlipChannel( LEDS[i].Port , LEDS[i].Pin );
		}
	}
}