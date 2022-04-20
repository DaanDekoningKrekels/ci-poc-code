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

void UART0_write(const char* msg);

/*
*****  NOT WORKING  ******
* for some reason only   *
* the first two chars    *
* get read from the      *
* buffer.                *
* I have tried changing  *
* The value of length in *
* the io_read() function *
* but the function fails *
* if a value higher than *
* 3 is given.            *
************************

uint8_t* UART0_read(uint16_t msgLength);
*/
#endif /* UART0_H_ */