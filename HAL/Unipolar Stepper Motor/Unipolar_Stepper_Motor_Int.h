/*
 * Unipolar_Stepper_Motor_Int.h
 *
 * Created: 3/9/2023 11:14:17 PM
 *  Author: Ashraf
 */ 


#ifndef UNIPOLAR_STEPPER_MOTOR_INT_H_
#define UNIPOLAR_STEPPER_MOTOR_INT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
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

void uStep_Motor_voidInit(void);

void uStep_Motor_voidRotate_Clock(u8 Stepper_Motor_Num, u16 StepCount);

void uStep_Motor_voidRotate_Anti_Clock(u8 Stepper_Motor_Num, u16 StepCount);





#endif /* UNIPOLAR_STEPPER_MOTOR_INT_H_ */