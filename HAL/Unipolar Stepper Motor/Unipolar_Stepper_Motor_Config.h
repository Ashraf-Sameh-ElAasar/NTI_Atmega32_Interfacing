/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Unipolar_Stepper_Motor_Config.h		*/
/****************************************************************/

#ifndef UNIPOLAR_STEPPER_MOTOR_CONFIG_H_
#define UNIPOLAR_STEPPER_MOTOR_CONFIG_H_

#define NUMBER_OF_STEPPER_MOTORS	1

#include "CFG.h"

typedef enum {
Full  ,
Half
}Step_Mode;



typedef struct{

PORTx      Port ;
PINx       Pin1 ;
PINx       Pin2 ;
PINx       Pin3 ;
PINx       Pin4 ;
Step_Mode  Mode ;
}StepperMotor;

StepperMotor CONFIG_Stepper_Motor[NUMBER_OF_STEPPER_MOTORS] ;


#endif /* UNIPOLAR_STEPPER_MOTOR_CONFIG_H_ */