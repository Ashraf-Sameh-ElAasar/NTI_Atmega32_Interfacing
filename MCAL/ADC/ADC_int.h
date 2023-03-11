/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    2 May 2019  						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							and Sense Mode Definition [int.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_INT_H
#define _ADC_INT_H


/****************************************************************/	
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/
#include "std_types.h"
#define AVCC 					5
#define AREF 					4
#define INTERNAL				2.56

#define REFS1					7
#define REFS0					6
#define ADLAR					5
#define CHANNEL_MASK		0b11100000

#define ADEN					7
#define ADSC					6
#define ADATE					5
#define ADIF					4
#define ADIE					3

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1

#define DISABLED				0
#define ENABLED					1

#define PRESCALER_MASK		0b11111000
#define DIVID_BY_2				1
#define DIVID_BY_4				2
#define DIVID_BY_8				3
#define DIVID_BY_16				4
#define DIVID_BY_32				5
#define DIVID_BY_64				6
#define DIVID_BY_128			7


#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7

#define ADC_CH_MASK			0xE0

#define ADC_REF_AREF_MASK		0x00
#define ADC_REF_AVCC_MASK		0x40
#define ADC_REF_INTERNAL_MASK	0xc0

#define ADC_MODE_SINGLE		0
#define ADC_MODE_DIFF		1


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void);


//****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable();


/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable();


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable();


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
u8 ADC_u8ReadADC(u8 addresscpy);



/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion();


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

void ADC_voidAutoTrigger();



/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 Copy_u8Channel);

void ADC_voidCallBack(void (*addresscpy)(void));

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
void __vector_16(void) __attribute__(( signal , used ));

void ADC_display(void);


u16 ADC_read();

#endif	/** !comment  :  End of guard                          **/
