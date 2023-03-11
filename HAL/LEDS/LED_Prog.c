/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LED_Prog.c			     			*/
/****************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LED_CFG.h"
#include "LED_Int.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


void LED_voidINIT ( void )
{
	u8 iterations;
	for(iterations = 0 ; iterations < NUMBER_OF_LEDS ; iterations++ )
	{
		dio_voidConfigChannel(LEDS[iterations].Port , LEDS[iterations].Pin, OUTPUT );
	}
}


void LED_voidON ( LED_ID led_col )
{
	u8 iterations;
	for(iterations = 0 ; iterations < NUMBER_OF_LEDS ; iterations++)
	{
		if( led_col == LEDS[iterations].Led_Num )
		{
			switch( LEDS[iterations].State )
			{
				case SOURCE :  
				dio_voidWriteChannel(LEDS[iterations].Port , LEDS[iterations].Pin , STD_HIGH );
				break ;
				case SINK   :  
				dio_voidWriteChannel(LEDS[iterations].Port , LEDS[iterations].Pin , STD_LOW );
				break ;
			}
		}
	}	
}


void LED_voidOFF ( LED_ID led_col)
{
	u8 iterations ;
	for(iterations = 0 ; iterations < NUMBER_OF_LEDS ; iterations++)
	{
		if(led_col == LEDS[iterations].Led_Num)
		{
			switch(LEDS[iterations].State)
			{
				case SOURCE :  
				dio_voidWriteChannel(LEDS[iterations].Port , LEDS[iterations].Pin , STD_LOW ); 
				break ;
				case SINK   : 
				dio_voidWriteChannel(LEDS[iterations].Port , LEDS[iterations].Pin , STD_HIGH ); 
				break ;
			}
		}
	}

	
	
}
void LED_voidTOGGLE ( LED_ID led_col)
{
	u8 iterations ;
	for(iterations = 0 ; iterations < NUMBER_OF_LEDS ; iterations++)
	{
		if(led_col == LEDS[iterations].Led_Num)
		{
			dio_voidFlipChannel( LEDS[iterations].Port , LEDS[iterations].Pin );
		}
	}
}