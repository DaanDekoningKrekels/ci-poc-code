/*
* UART2.h
*
* Created: 13-Apr-22 16:15:49
*  Author: Birk Tamm
*/

#include <strings.h>

#ifndef UART0_H_
#define UART0_H_

void UART0_init(void);

void UART0_write(const char* msg, uint8_t read);
uint8_t UART0_read(void);
#endif /* UART0_H_ */