/*
 * PSH_BTN_Int.h
 *
 * Created: 3/8/2023 2:20:48 PM
 *  Author: Ashraf
 */ 


#ifndef PSH_BTN_INT_H_
#define PSH_BTN_INT_H_

#include "PSH_BTN_CFG.h"

void BUTTON_voidInit(void);

BUTTON_STATUS BUTTON_StatusGetPress(BUTTON_ID button);



#endif /* PSH_BTN_INT_H_ */