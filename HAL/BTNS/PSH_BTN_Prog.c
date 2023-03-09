/*
 * PSH_BTN_Prog.c
 *
 * Created: 3/8/2023 2:20:33 PM
 *  Author: Ashraf
 */ 
#include "PSH_BTN_Int.h"
#include "DIO.h"


void BUTTON_voidInit(void)
{
	u8 i;
	for(i = 0; i < NUMBER_OF_BUTTONS; i++)
	{
		dio_voidConfigChannel(BTNS[i].Port , BTNS[i].Pin ,INPUT);
		if(BTNS[i].State == PULLUP)
		{
			switch(BTNS[i].Setup)
			{
				case PHYSICAL:
				/*--------Do Nothing-------*/
				break;
				case SOFTWARE:
				dio_voidWriteChannel(BTNS[i].Port , BTNS[i].Pin , STD_HIGH);
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
	u8 i;
	for(i = 0; i < NUMBER_OF_BUTTONS; i++)
	{
		if(button == BTNS[i].Button_Num)
		{
			switch(BTNS[i].State)
			{
				case PULLDOWN :
				if(dio_dioLevelReadChannel(BTNS[i].Port,BTNS[i].Pin))
				{
					return PRESSED ;
				}
				else
				{
					return RELEASED ;
				}
				break;
				case PULLUP :
				if(!dio_dioLevelReadChannel(BTNS[i].Port,BTNS[i].Pin))
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