/*
 * EEPROM_Priv.h
 *
 * Created: 3/11/2023 10:56:55 AM
 *  Author: Ashraf
 */ 


#ifndef EEPROM_PRIV_H_
#define EEPROM_PRIV_H_

#define EEAR		*((volatile u16 *)0x3F)
#define EEARH		*((volatile u8 *)0x3F)
#define EEARL		*((volatile u8 *)0x3E)
#define EEDR		*((volatile u8 *)0x3D)
#define EECR		*((volatile u8 *)0x3C)

typedef enum
{
	EEAR0 = 0,
	EEAR1,
	EEAR2,
	EEAR3,
	EEAR4,
	EEAR5,
	EEAR6,
	EEAR7
	};
	
typedef enum
{
	EEAR8 = 0,
	EEAR9
	};
	
#define LSB			0
#define MSB			7
	
typedef enum
{
	EERE = 0,
	EEWE,
	EEMWE,
	EERIE
	};



#endif /* EEPROM_PRIV_H_ */