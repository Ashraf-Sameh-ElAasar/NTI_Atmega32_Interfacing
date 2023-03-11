/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for EXT0		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "STD_Types.h"
#include "Bit_Math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI0_int.h"
#include "EXTI0_Config.h"
#include "EXTI0_private.h" 


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
volatile pf x;


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT0_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXT0_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;
	
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidEnable()
{
	
	SET_BIT( GICR , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidDisable()
{
	
	CLEAR_BIT( GICR , 6 );
	
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

void EXT0_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		x = addresscpy;
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
void EXT0_voidSetSignalch(u8 SenseCpy)
{
	/*  ( if / else if ) condition for Macros */
	if(SenseCpy== IOC)
	{
		SET_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);
	}
	
	
	if(SenseCpy== RISING)
	{
		SET_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	
	
	if(SenseCpy== FALLING)
	{
		CLEAR_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	
	
	if(SenseCpy== LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);
	}
	
	
	/* End ( if ) condition for Macros */

	
	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;

	
	
}
/** Linker Problem solved */
void __vector_1(void) __attribute__(( signal , used ));


void __vector_1(void)
{
	x();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/