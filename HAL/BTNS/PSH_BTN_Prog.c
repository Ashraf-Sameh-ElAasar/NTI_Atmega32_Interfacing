/*
 * PSH_BTN_Prog.c
 *
 * Created: 3/8/2023 2:20:33 PM
 *  Author: Ashraf
 */ 


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PSH_BTN_Int.h"
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

void BUTTON_voidInit(void)
{
	u8 iterations;
	for(iterations = 0; iterations < NUMBER_OF_BUTTONS; iterations++)
	{
		dio_voidConfigChannel(BTNS[iterations].Port , BTNS[iterations].Pin ,INPUT);
		if(BTNS[iterations].State == PULLUP)
		{
			switch(BTNS[iterations].Setup)
			{
				case PHYSICAL:
				/*--------Do Nothing-------*/
				break;
				case SOFTWARE:
				dio_voidWriteChannel(BTNS[iterations].Port , BTNS[iterations].Pin , STD_HIGH);
				break;
			}
		}
		else
		{
			//Do nothing
		}
	}
}

BUTTON_STATUS BUTTON_StatusGetPress(BUTTON_ID button)
{
	u8 iterations;
	for(iterations = 0; iterations < NUMBER_OF_BUTTONS; iterations++)
	{
		if(button == BTNS[iterations].Button_Num)
		{
			switch(BTNS[iterations].State)
			{
				case PULLDOWN :
				if(dio_dioLevelReadChannel(BTNS[iterations].Port,BTNS[iterations].Pin))
				{
					return PRESSED ;
				}
				else
				{
					return RELEASED ;
				}
				break;
				case PULLUP :
				if(!dio_dioLevelReadChannel(BTNS[iterations].Port,BTNS[iterations].Pin))
				{
					return PRESSED ;
				}
				else
				{
					return RELEASED ;
				}
				break;
			}
		}
	}
	return RELEASED;
}