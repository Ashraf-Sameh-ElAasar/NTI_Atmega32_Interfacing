/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/
#define F_CPU 16000000UL
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "LCD_Int.h"
#include <util/delay.h>

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

void (*pf1)(void);

static u8 ADC_u8SelAdj(u8 Copy_u8Adj);
static u8 ADC_u8Prescale(u8 Copy_u8Scale);
static u8 ADC_u8SelChannel(u8 Copy_u8Channel, u8 Copy_u8Mode);
static u8 ADC_u8RefVolt(u8 Copy_u8Ref);


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	ADMUX &= CHANNEL_MASK;
	ADMUX |= ADC_CHANNEL_NUMBER;
	
	/* End ( if ) condition for Macros */	
	
	/* Voltage reference option = AVCC */
	#if VOLTAGE_REFERENCE == AREF
	CLEAR_BIT(ADMUX, REFS0);
	CLEAR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REFERENCE == AVCC
	SET_BIT(ADMUX, REFS0);
	CLEAR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);

	#endif

	/* Adjustment option = LEFT_ADJUSTMENT */
	#if ADJUSTMENT == RIGHT_ADJUSTMENT
	CLEAR_BIT(ADMUX, ADLAR);

	#elif ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX, ADLAR);

	#endif

	/* ADC_AUTO_TRIGGER_ENABLE option = DISABLED */
	#if ADC_AUTO_TRIGGER_ENABLE == ENABLED
	SET_BIT(ADCSRA, ADATE);
	ADC_voidAutoTrigger();
	
	#elif ADC_AUTO_TRIGGER_ENABLE == DISABLED
	CLEAR_BIT(ADCSRA, ADATE);

	#endif

	/* ADC_INTERRUPT_ENABLE option = DISABLED */
	#if ADC_INTERRUPT_ENABLE == ENABLED
	SET_BIT(ADCSRA, ADIE);

	#elif ADC_INTERRUPT_ENABLE == DISABLED
	CLEAR_BIT(ADCSRA, ADIE);

	#endif


	/* configure prescaler bits */
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= DIVID_BY_128;

	/* ADC Enable */
	ADC_voidEnable();

}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , ADEN );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , ADIE );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , ADEN );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , ADSC );
	
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

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 channel)
{
	u16 number = 0;
	ADMUX &= CHANNEL_MASK;
	ADMUX |= channel;
	
	/* start conversion */
	ADC_voidStartConversion();

	/* wait until the conversion is clear */
	while(CHECK_BIT(ADCSRA, ADIF) == 0);

	/* clear the conversion flag */
	SET_BIT(ADCSRA, ADIF);
	
	number = (u16) ADCL + (u16) ADCH *256;
	
	/* check if left Adjustment or right (8 bit or 10 bit) */
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	return ADCH;
	
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	return number;

	#endif
	
}

u16 ADC_read()
{
	/*---------------------------------------------------Ashraf Add Flag condition-----------------------------------------------------*/
	/*-----------------------------this function only reads the values after the auto trigger is fired by EXTI0------------------------*/
		u16 number = 0;
		number = (u16) ADCL + (u16) ADCH *256;
		
		/* check if left Adjustment or right (8 bit or 10 bit) */
		#if ADJUSTMENT == LEFT_ADJUSTMENT
		return ADCH;
		
		#elif ADJUSTMENT == RIGHT_ADJUSTMENT
		return number;
		#endif
}

void ADC_voidReadADCInterrupt(u8 channel)
{
	// select channel
	ADC_u8SelChannel(channel, ADC_MODE_SINGLE);
	//ADC_VoidStartConversion();
	ADC_voidStartConversion();

	//enable ADC Interrupt
	//	ADC_voidInterrputEnable();

}


void ADC_voidCallBack(void (*addresscpy)(void))
{
	/*ADMUX &= CHANNEL_MASK;*/
	/*ADMUX |= channel;*/
	if(addresscpy != NULL)
	{
		pf1 = addresscpy;
	}
}

void ADC_display(void)
{
	LCD_voidDisplayNum((u16) ADCL + (u16) ADCH * 256);
	_delay_ms(50);
	LCD_SendCmd(ClearLCD);
}

void __vector_16(void)
{
	pf1();
}

static u8 ADC_u8SelChannel(u8 Copy_u8Channel, u8 Copy_u8Mode)
{
	u8 Local_Error = 0;

	if(Copy_u8Mode == ADC_MODE_SINGLE)
	{
		ADMUX &= ADC_CH_MASK;
		ADMUX |= Copy_u8Channel;

	}
	else if(Copy_u8Mode == ADC_MODE_DIFF)
	{
		//NOT IMPLEMENTED YET
	}
	return Local_Error;
}


static u8 ADC_u8RefVolt(u8 Copy_u8Ref)
{

	ADMUX &= 0b00111111;

	if(Copy_u8Ref == AVCC)
	{
		ADMUX |= ADC_REF_AVCC_MASK;
	}
	else if(Copy_u8Ref == AREF)
	{
		ADMUX |= ADC_REF_AREF_MASK;
	}
	else if(Copy_u8Ref == INTERNAL)
	{
		ADMUX |= ADC_REF_INTERNAL_MASK;
	}




	return 0;
}


static u8 ADC_u8SelAdj(u8 Copy_u8Adj)
{
	if(Copy_u8Adj == LEFT_ADJUSTMENT)
	{
		SET_BIT(ADMUX, ADLAR);
	}
	else if(Copy_u8Adj == RIGHT_ADJUSTMENT)
	{
		CLEAR_BIT(ADMUX, ADLAR);
	}

	return 0;
}

static u8 ADC_u8Prescale(u8 Copy_u8Scale)
{
	switch(Copy_u8Scale)
	{
		ADCSRA &= 0b11111000;
		case DIVID_BY_2: 							break;
		case DIVID_BY_4: 	ADCSRA|= 0b00000010;	break;
		case DIVID_BY_8: 	ADCSRA|= 0b00000011;	break;
		case DIVID_BY_16: 	ADCSRA|= 0b00000100;	break;
		case DIVID_BY_32: 	ADCSRA|= 0b00000101;	break;
		case DIVID_BY_64: 	ADCSRA|= 0b00000110;	break;
		case DIVID_BY_128: 	ADCSRA|= 0b00000111;	break;
	}


	return 0;
}


void ADC_voidRead8channels(u8* an_reads)
{
	u8 arr_an_channels[] = {0, 1, 2, 3,4, 5, 6, 7};

	for(u8 idx= 0; idx<NUMBER_CHANNELS; idx++)
	{
		an_reads[idx] = ADC_u16ReadADCInMV(arr_an_channels[idx]);
	}

}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
