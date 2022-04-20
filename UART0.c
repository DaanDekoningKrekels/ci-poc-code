/*
* UART0.c
*
* Created: 13-Apr-22 16:14:54
*  Author: Birk Tamm
*/

#include "UART0.h"
#include "UART2.h"
#include "driver_init.h"

struct io_descriptor *uart0_io;


void UART0_init(void)
{
	usart_sync_get_io_descriptor(&USART_0, &uart0_io);
	usart_sync_enable(&USART_0);
}

void UART0_write(const char* msg)
{
	io_write(uart0_io, (uint8_t *)msg, strlen(msg));
}

/* 
uint8_t *UART0_read(uint16_t msgLength)
{
	uint8_t *msg;
	io_read(uart0_io, &msg, 3);
	UART2_write(&msg);
	return msg;
}
*/