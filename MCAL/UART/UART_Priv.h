/*
 * UART_Priv.h
 *
 * Created: 3/11/2023 5:35:24 AM
 *  Author: Ashraf
 */ 


#ifndef UART_PRIV_H_
#define UART_PRIV_H_


#define UART_UDR_REG				(*(volatile u8* )0x2C)
#define UART_UCSRA_REG				(*(volatile u8* )0x2B)
#define UART_UCSRB_REG				(*(volatile u8* )0x2A)
#define UART_UBRRH_REG				(*(volatile u8* )0x40)
#define UART_UCSRC_REG				(*(volatile u8* )0x40)
#define UART_UBRRL_REG				(*(volatile u8* )0x29)


#define RXEN_BIT_NO						4
#define TXEN_BIT_NO						3
#define URSEL_BIT_NO					7
#define USBS_BIT_NO						3
#define UCSZ0_BIT_NO					1
#define UPM0_BIT_NO						4
#define UDRE_BIT_NO						5
#define RXC_BIT_NO						7

#define RX_BUFFER_SIZE				(25)

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)


#endif /* UART_PRIV_H_ */