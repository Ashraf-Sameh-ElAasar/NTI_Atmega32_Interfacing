/*
 * SevenSegment.c
 *
 * Created: 2/21/2023 3:29:19 PM
 *  Author: Dell
 */ 
#include "SevenSegment.h"

void SevenSegmentInit(){
	dio_vidConfigChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,OUTPUT);
	dio_vidConfigChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,OUTPUT);
	dio_vidConfigChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,OUTPUT);
	dio_vidConfigChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,OUTPUT);
	
	dio_vidConfigChannel(SevenSegementFirstDigitPort,SevenSegementFirstDigitPin,OUTPUT);
	dio_vidConfigChannel(SevenSegementSecondDigitPort,SevenSegementSecondDigitPin,OUTPUT);
	dio_vidConfigChannel(SevenSegementThirdDigitPort,SevenSegementThirdDigitPin,OUTPUT);
	dio_vidConfigChannel(SevenSegementFourthDigitPort,SevenSegementFourthDigitPin,OUTPUT);
}







void SevenSegmentDisplay(u16 DisplayedValue){
	dio_vidWriteChannel(SevenSegementFirstDigitPort,SevenSegementFirstDigitPin,!STD_HIGH);
	dio_vidWriteChannel(SevenSegementFourthDigitPort,SevenSegementFourthDigitPin,!STD_LOW);
	SevenSegmentDisplayNumber(DisplayedValue%10);
	DisplayedValue/=10;
	_delay_ms(SevenSegmentDelay);
	dio_vidWriteChannel(SevenSegementFourthDigitPort,SevenSegementFourthDigitPin,!STD_HIGH);
	dio_vidWriteChannel(SevenSegementThirdDigitPort,SevenSegementThirdDigitPin,!STD_LOW);
	SevenSegmentDisplayNumber(DisplayedValue%10);
	DisplayedValue/=10;
	_delay_ms(SevenSegmentDelay);
	dio_vidWriteChannel(SevenSegementThirdDigitPort,SevenSegementThirdDigitPin,!STD_HIGH);
	dio_vidWriteChannel(SevenSegementSecondDigitPort,SevenSegementSecondDigitPin,!STD_LOW);
	SevenSegmentDisplayNumber(DisplayedValue%10);
	DisplayedValue/=10;
	_delay_ms(SevenSegmentDelay);
	dio_vidWriteChannel(SevenSegementSecondDigitPort,SevenSegementSecondDigitPin,!STD_HIGH);
	dio_vidWriteChannel(SevenSegementFirstDigitPort,SevenSegementFirstDigitPin,!STD_LOW);
	SevenSegmentDisplayNumber(DisplayedValue%10);
	_delay_ms(SevenSegmentDelay);
}

void SevenSegmentDisplayNumber(u8 Number){
	switch(Number){
		case 0:SevenSegmentDisplayZero();break;
		case 1:SevenSegmentDisplayOne();break;
		case 2:SevenSegmentDisplayTwo();break;
		case 3:SevenSegmentDisplayThree();break;
		case 4:SevenSegmentDisplayFour();break;
		case 5:SevenSegmentDisplayFive();break;
		case 6:SevenSegmentDisplaySix();break;
		case 7:SevenSegmentDisplaySeven();break;
		case 8:SevenSegmentDisplayEight();break;
		case 9:SevenSegmentDisplayNine();break;
	}
}
void SevenSegmentDisplayZero(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);
}
void SevenSegmentDisplayOne(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplayTwo(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplayThree(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplayFour(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplayFive(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplaySix(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplaySeven(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_LOW);	
}
void SevenSegmentDisplayEight(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_HIGH);	
}
void SevenSegmentDisplayNine(){
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinA,STD_HIGH);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinB,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinC,STD_LOW);
	dio_vidWriteChannel(SevenSegementMultiplexerPort,SevenSegementMultiplexerPinD,STD_HIGH);	
}