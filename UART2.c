/*
* UART2.c
*
* Created: 13-Apr-22 14:54:52
*  Author: Birk Tamm
*/

#include "UART2.h"
#include "driver_init.h"

struct io_descriptor *uart2_io;

volatile static uint8_t data_arrived = 0;

static void tx_cb_UART2(const struct usart_async_descriptor *const io_descr) {
	/* Transfer completed */
}
static void rx_cb_UART2(const struct usart_async_descriptor *const io_descr){
	/* Receive completed */
	data_arrived = 1;
}
void UART2_init(void) {
	
	usart_async_register_callback(&USART_2, USART_ASYNC_TXC_CB, tx_cb_UART2);
	usart_async_register_callback(&USART_2, USART_ASYNC_RXC_CB, rx_cb_UART2);
	/*usart_async_register_callback(&USART_3, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_2, &uart2_io);
	usart_async_enable(&USART_2);
}

void UART2_write(const char *msg) {
	io_write(uart2_io, (uint8_t *)msg, strlen(msg));
}

void UART2_read(void) {
	uint8_t recv_char;
	if (data_arrived == 0) {
		//continue;
	}
	while (io_read(&USART_2.io, &recv_char, 1) == 1) {
		while (io_write(&USART_2.io, &recv_char, 1) != 1) {
		}
	}
	data_arrived = 0;
}
