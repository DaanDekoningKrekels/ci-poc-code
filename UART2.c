/*
* UART2.c
*
* Created: 13-Apr-22 14:54:52
*  Author: Birk Tamm
*/

#include "UART2.h"
#include "driver_init.h"

struct io_descriptor *uart2_io;

void UART2_init(void)
{
	usart_sync_get_io_descriptor(&USART_2, &uart2_io);
	usart_sync_enable(&USART_2);
}

void UART2_write(const char* msg)
{
	io_write(uart2_io, (uint8_t *)msg, strlen(msg));
}