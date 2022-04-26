/*
* I2C.c
*
* Created: 25-Apr-22 15:05:05
*  Author: Birk Tamm
*/

#include "driver_init.h"
#include "UART2.h"
#include "RN2483.h"

struct io_descriptor *i2c_io;
uint8_t               c[2];

void I2C_init(void){
	i2c_m_sync_get_io_descriptor(&I2C_0, &i2c_io);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x08, I2C_M_SEVEN);
	i2c_m_sync_enable(&I2C_0);
}
void I2C_read(void) {
	io_read(i2c_io, &c[0], 2);
	RN2483_send(c);
}