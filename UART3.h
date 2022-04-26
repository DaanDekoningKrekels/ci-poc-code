/*
 * UART3.h
 *
 * Created: 23-Apr-22 15:07:35
 *  Author: Birk Tamm
 */ 


#ifndef UART3_H_
#define UART3_H_

void UART3_init(void);
void UART3_write(const char *msg);
void UART3_read(void);

#endif /* UART3_H_ */