/*
 * TIMR2_int.h
 *
 * Created: 3/9/2023 11:02:38 PM
 *  Author: Ashraf
 */ 


#ifndef TIMR2_INT_H_
#define TIMR2_INT_H_

void TIMER2_void_Init(void);

u8 TIMER2_GetTimerReg(void);

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER2_void_EnableOVInt(void);

void TIMER2_void_DisableOVInt(void);

void TIMER2_void_EnableCTCInt(void);

void TIMER2_void_DisableCTCInt(void);

void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;




#endif /* TIMR2_INT_H_ */