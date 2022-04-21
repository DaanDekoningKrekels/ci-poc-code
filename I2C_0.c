/*
* I2C_0.c
*
* Created: 14-Apr-22 11:42:00
*  Author: Bavo Debraekeleer
*/

/*
BME280 example:

struct bme280_dev dev;
int8_t rslt = BME280_OK;
uint8_t dev_addr = BME280_I2C_ADDR_PRIM;

dev.intf_ptr = &dev_addr;
dev.intf = BME280_I2C_INTF;
dev.read = user_i2c_read;
dev.write = user_i2c_write;
dev.delay_ms = user_delay_ms;

rslt = bme280_init(&dev);
*/

#include "I2C_0.h"
#include "driver_init.h"
#include "bme280.h"
#include <iic.h>

struct io_descriptor *I2C_0_io;

void I2C_0_init(void)
{
	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	//i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	//io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}

uint8_t I2C_0_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
	//BME280 dev_addr=0x76 or 0X77
	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, dev_addr, I2C_M_SEVEN);
	io_read(I2C_0_io, data, len)
	
	return I2C_OK;
}
