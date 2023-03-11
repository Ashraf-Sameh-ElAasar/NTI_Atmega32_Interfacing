/*
 * EXT1_prog.c
 *
 * Created: 2/24/2023 11:38:54 AM
 *  Author: Ashraf
 */ 

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#define NULL 0
#include "dio.h"
#include "STD_Types.h"
#include "Bit_Math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI1_INT.h"
#include "EXTI1_Config.h"
#include "EXTI0_private.h" 


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

volatile pf x1;

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT1_voidInit (void)
{
	dio_voidConfigChannel(DIO_PORTD,DIO_PIN3,INPUT);
	dio_voidWriteChannel(DIO_PORTD,DIO_PIN3,STD_HIGH);
	/*  ( if / else if ) condition for Macros */
	#if EXT1_SENSE_MODE == IOC
	SET_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == RISING
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT1 in initialization function  **/
/** like : void EXT1_voidDisable(); 		  */
	CLEAR_BIT( GICR , 7 );
	SET_BIT(GIFR , 7 ) ;
	
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT1			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidEnable()
{
	
	SET_BIT( GICR , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT1			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidDisable()
{
	
	CLEAR_BIT( GICR , 7 );
	
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		x1 = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidSetSignalch(u8 SenseCpy)
{
	if(SenseCpy== IOC)
	{
		SET_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
	}
	
	
	if(SenseCpy== RISING)
	{
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}
	
	
	if(SenseCpy== FALLING)
	{
		CLEAR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}
	
	
	if(SenseCpy== LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
	}

	
	
}



void __vector_2(void)
{
	x1();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/