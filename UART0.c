/*
* UART0.c
*
* Created: 13-Apr-22 16:14:54
*  Author: Birk Tamm
*/

#include "UART0.h"
#include "driver_init.h"

struct io_descriptor *uart0_io;

volatile static uint8_t data_arrived = 0;

static void tx_cb_UART0(const struct usart_async_descriptor *const io_descr) {
	/* Transfer completed */
}
static void rx_cb_UART0(const struct usart_async_descriptor *const io_descr){
	/* Receive completed */
	data_arrived = 1;
}
void UART0_init(void) {
	
	usart_async_register_callback(&USART_0, USART_ASYNC_TXC_CB, tx_cb_UART0);
	usart_async_register_callback(&USART_0, USART_ASYNC_RXC_CB, rx_cb_UART0);
	/*usart_async_register_callback(&USART_3, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_0, &uart0_io);
	usart_async_enable(&USART_0);
}

void UART0_write(const char *msg, uint8_t read) {
	io_write(uart0_io, (uint8_t *)msg, strlen(msg));
	if (read > 0){
		UART0_read();
	}
}

uint8_t UART0_read(void) {
	uint8_t recv_char;
	if (data_arrived == 0) {
		//continue;
	}
	while (io_read(&USART_0.io, &recv_char, 1) == 1) {
		while (io_write(&USART_2.io, &recv_char, 1) != 1) {
		}
	}
	data_arrived = 0;
}