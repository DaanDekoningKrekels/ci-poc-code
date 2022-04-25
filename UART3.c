/*
* UART3.c
*
* Created: 23-Apr-22 14:49:57
*  Author: Birk Tamm
*/

#include "UART3.h"
#include "driver_init.h"

struct io_descriptor *uart3_io;

volatile static uint8_t data_arrived = 0;

static void tx_cb_UART3(const struct usart_async_descriptor *const io_descr) {
	/* Transfer completed */
}
static void rx_cb_UART3(const struct usart_async_descriptor *const io_descr){
	/* Receive completed */
	data_arrived = 1;
}
void UART3_init(void) {
	
	usart_async_register_callback(&USART_3, USART_ASYNC_TXC_CB, tx_cb_UART3);
	usart_async_register_callback(&USART_3, USART_ASYNC_RXC_CB, rx_cb_UART3);
	/*usart_async_register_callback(&USART_3, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_3, &uart3_io);
	usart_async_enable(&USART_3);
}

void UART3_write(const char *msg) {
	io_write(uart3_io, (uint8_t *)msg, strlen(msg));
}

void UART3_read(void) {
	uint8_t recv_char;
	if (data_arrived == 0) {
		//continue;
	}
	while (io_read(&USART_3.io, &recv_char, 1) == 1) {
		while (io_write(&USART_3.io, &recv_char, 1) != 1) {
		}
	}
	data_arrived = 0;
}
