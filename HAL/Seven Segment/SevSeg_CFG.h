/*
 * SevSeg_CFG.h
 *
 * Created: 3/9/2023 7:42:15 PM
 *  Author: Ashraf
 */ 


#ifndef SEVSEG_CFG_H_
#define SEVSEG_CFG_H_

#include "CFG.h"

#define NUMBER_OF_SevSeg	4

typedef struct  
{
	PORTx	Data_Port;
	PORTx	Enable_Port;
	PINx	SevSeg_A;
	PINx	SevSeg_B;
	PINx	SevSeg_C;
	PINx	SevSeg_D;
	PINx	SevSeg_EN;
}SEVSEG_CONFIG;

SEVSEG_CONFIG SevSegs[NUMBER_OF_SevSeg];

#endif /* SEVSEG_CFG_H_ */