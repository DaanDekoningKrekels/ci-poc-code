/*
* UART2.h
*
* Created: 13-Apr-22 15:00:49
*  Author: Birk Tamm
*/

#include <strings.h>

#ifndef UART2_H_
#define UART2_H_

void UART2_init(void);

void UART2_write(const char* msg);

#endif /* UART2_H_ */