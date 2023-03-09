/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Digital Input Output Prog.c			*/
/****************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_REG.h"
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void dio_voidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction);
void dio_voidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level);
void dio_voidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask);
void dio_voidFlipChannel(dio_portId_t port, dio_channelId_t channel);
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel);
void dio_voidEnablePullUp(dio_portId_t port, dio_channelId_t channel);
void Dio_voidWriteChannelGroup(dio_portId_t port , u8 mask , u8 value );
u8 Dio_u8ReadChannelGroup(dio_portId_t port , u8 mask );




#endif /* DIO_H_ */