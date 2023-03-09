/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Global Interrupt Enable Prog.c		*/
/****************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_int.h"
#include "GIE_priv.h"

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


/******************************************************************************
* \Syntax          : GIE_voidENABLE()       
* \Description     : this service for Enabling Global Interrupt                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none
* \Return value:   : None                            
*******************************************************************************/

void GIE_voidENABLE()
{

	SET_BIT(SREG , 7);
	
}

/******************************************************************************
* \Syntax          : GIE_voidENABLE()
* \Description     : this service for Disabling Global Interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : none
* \Return value:   : None
*******************************************************************************/

void GIE_voidDISABLE()
{
	
	CLEAR_BIT(SREG , 7);
	
}