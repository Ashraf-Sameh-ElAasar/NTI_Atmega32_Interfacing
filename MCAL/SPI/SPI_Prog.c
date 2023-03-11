/*
 * SPI_Prog.c
 *
 * Created: 3/11/2023 4:57:53 AM
 *  Author: Ashraf
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Int.h"
#include "SPI_Priv.h"
#include "DIO.h"
#include "LED_Int.h"



void (*SPI_PTR)(void);

void SPI_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		SPI_PTR = addresscpy;
	}
}




void SPI_VoidInit(SPI* Copy_spi)
{
	// Select Master or slave
	SPI_u8MasterSlaveSelect(Copy_spi->role);
	if(Copy_spi->role == SPI_MASTER)
	{
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN5, OUTPUT);	//MOSI
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN6, INPUT);	//MISO
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN7, OUTPUT);	//SCLK
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN4, INPUT);	//SS'

		dio_voidEnablePullUp(DIO_PORTB, DIO_PIN4);
		//select CLK rate
		SPI_u8PreScaler(Copy_spi -> Prescaler);
	}
	else if(Copy_spi->role == SPI_SLAVE)
	{

		dio_voidConfigChannel(DIO_PORTB, DIO_PIN5, INPUT);	//MOSI

		dio_voidConfigChannel(DIO_PORTB, DIO_PIN6, OUTPUT);	//MISO
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN7, INPUT);	//SCLK
		dio_voidConfigChannel(DIO_PORTB, DIO_PIN4, INPUT);	//SS'
		//DIO_u8ActivatePinPullup(DIO_u8PORTB, DIO_u8PIN4);
	}

	//select CLK polarity and phase
	SPI_u8CLKPolPhase(Copy_spi -> CLKPolPhase);

	//select Data order
	SPI_u8DataOrder(Copy_spi -> DataOrder);

	SPI_u8Enable();

}


u8 SPI_u8Enable()
{
	SET_BIT(SPCR, SPE);

	return 0;
}

u8 SPI_u8Disable()
{
	CLEAR_BIT(SPCR, SPE);
	return 0;
}

u8 SPI_u8MasterSlaveSelect(u8 Copy_u8Select)
{
	if(Copy_u8Select == SPI_MASTER)
	{
		SET_BIT(SPCR, MSTR);
	}
	else if(Copy_u8Select == SPI_SLAVE)
	{
		CLEAR_BIT(SPCR, MSTR);
	}

	return 0;
}

u8 SPI_u8CLKPolPhase(u8 Copy_u8PolPhase)
{
	switch(Copy_u8PolPhase)
	{
		case SPI_SAMPLE_RISING:		
		CLEAR_BIT(SPCR, CPOL);	
		CLEAR_BIT(SPCR, CPHA);	
		break;
		case SPI_SETUP_RISING:		
		CLEAR_BIT(SPCR, CPOL);	
		SET_BIT(SPCR, CPHA);	
		break;
		case SPI_SAMPLE_FALLING:	
		SET_BIT(SPCR, CPOL);	
		CLEAR_BIT(SPCR, CPHA);	
		break;
		case SPI_SETUP_FALLING:		
		SET_BIT(SPCR, CPOL);	
		SET_BIT(SPCR, CPHA);	
		break;
	}
	return 0;
}

u8 SPI_u8PreScaler(u8 Scale)
{
	//initialize clock rate bits with 0
	SPCR &= SPI_PRESCAL_MASK;
	//check for clock rate bits only (bit 1:0)
	SPCR|= (Scale<<6)>>6;

	//enable double speed mode if needed
	if(CHECK_BIT(Scale, 2) == 0)	//(for 4, 16, 64, 128)
	{
		CLEAR_BIT(SPSR, SPI2X);
	}
	else if(CHECK_BIT(Scale, 2) == 1)	//(for 2, 8, 32)
	{
		SET_BIT(SPSR, SPI2X);
	}
	return 0;
}


u8 SPI_u8DataOrder(u8 Dataorder)
{
	if(Dataorder == SPI_DATAORDER_LSB)
	{
		SET_BIT(SPCR, DORD);
	}
	else if(Dataorder == SPI_DATAORDER_MSB)
	{
		CLEAR_BIT(SPCR, DORD);
	}
	return 0;
}

u8 SPI_u8SelectSlave(u8 Coy_u8Port, u8 Copy_u8Pin)
{
	dio_voidConfigChannel(Coy_u8Port, Copy_u8Pin, OUTPUT);
	dio_voidWriteChannel(Coy_u8Port, Copy_u8Pin, STD_LOW);
	return 0;
}

u8 SPI_u8ReleaseSlave(u8 Coy_u8Port, u8 Copy_u8Pin)
{
	dio_voidConfigChannel(Coy_u8Port, Copy_u8Pin, OUTPUT);
	dio_voidWriteChannel(Coy_u8Port, Copy_u8Pin, STD_HIGH);

	return 0;
}

u8 SPI_u8SendRecData(u8 Data)
{
	/* Write Data Byte */
	u8 Local_temp = SPDR;
	SPDR = Data;
	/* wait until transmission is completed */
	while( (CHECK_BIT(SPSR,SPIF) == 0) && (CHECK_BIT(SPSR,WCOL) == 0) );
	Data = SPDR;
	return Data;

}

u8 SPI_u8RecDataSlave()
{

	/* wait until transmission is completed */
	while( (CHECK_BIT(SPSR,SPIF) == 0) && (CHECK_BIT(SPSR,WCOL) == 0) );
	return SPDR;

}

void SPI_voidInterruptEnable()
{
	SET_BIT(SPCR, SPIE);
}

u8 SPI_Data = 0;
u8 SPI_DATA_RECIVED_FLAG = 0;

void SPI_u8SendRecDataInterrupt(u8 Data)
{
	if(SPI_DATA_RECIVED_FLAG == 0)
	{
		SPDR = Data;
		SPI_DATA_RECIVED_FLAG=1;
	}


}

void __vector_12(void)
{
	SPI_PTR();
}


