/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    2 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

#include "DIO.h"
/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define VOLTAGE_REFERENCE			AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/	
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJUSTMENT				RIGHT_ADJUSTMENT



/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_CHANNEL_NUMBER		DIO_PIN0

#define ADC_Percision   TEN_BITPERCISION

/****************************************************************/
/** !comment : Please Enter the ADC_ATUO_TRIGGER_ENABLE			*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					ENABLED 			*/
/*						    				DISABLED 			*/
/****************************************************************/
#define ADC_AUTO_TRIGGER_ENABLE			ENABLED

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_AUTO_TRIGGER_SOURCE		EXTERNAL_INTERRPUT_REQUEST_0

/****************************************************************/
/** !comment : Please Enter the ADC_INTERRUPT_ENABLE				*/
/** 		   ADC_INTERRUPT_ENABLE can be : 						*/
/*					    					ENABLED 			*/
/*						    				DISABLED			*/
/****************************************************************/

#define ADC_INTERRUPT_ENABLE				ENABLED

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_PRESCALLER				DIVID_BY_128




#endif	/**!comment : End of the guard [_ADC_CONFIG_H]		   **/
