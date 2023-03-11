/*
 * EEPROM.h
 *
 * Created: 1/28/2023 9:33:45 PM
 *  Author: AMIT
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Write(char page , char add ,char data);
char EEPROM_Read(char page , char add);
void EEPROM_INIT();


#endif /* EEPROM_H_ */