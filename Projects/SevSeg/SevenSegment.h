/*
 * SevenSegment.h
 *
 * Created: 2/21/2023 3:29:29 PM
 *  Author: Dell
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "../../MCAL/DIO/dio.h"
#include "SevenSegmentCfg.h"
#include <util/delay.h>

void SevenSegmentInit();
void SevenSegmentDisplay(u16 DisplayedValue);
void SevenSegmentDisplayNumber(u8 Number);
void SevenSegmentDisplayZero();
void SevenSegmentDisplayOne();
void SevenSegmentDisplayTwo();
void SevenSegmentDisplayThree();
void SevenSegmentDisplayFour();
void SevenSegmentDisplayFive();
void SevenSegmentDisplaySix();
void SevenSegmentDisplaySeven();
void SevenSegmentDisplayEight();
void SevenSegmentDisplayNine();

#endif /* SEVENSEGMENT_H_ */