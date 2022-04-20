/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_adc_base.h>

struct adc_sync_descriptor ADC_0;

struct usart_sync_descriptor USART_0;

struct usart_sync_descriptor USART_2;

struct usart_sync_descriptor USART_3;

struct i2c_m_sync_desc I2C_0;

struct usart_sync_descriptor USART_1;

struct wdt_descriptor WDT_0;

void ADC_0_PORT_init(void)
{

	// Disable digital pin circuitry
	gpio_set_pin_direction(ADC_BATT, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(ADC_BATT, PINMUX_PA02B_ADC_AIN0);
}

void ADC_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	adc_sync_init(&ADC_0, ADC, (void *)NULL);
}

void USART_0_PORT_init(void)
{

	gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);

	gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);
}

void USART_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM0, (void *)NULL);
	USART_0_PORT_init();
}

void USART_2_PORT_init(void)
{

	gpio_set_pin_function(PA08, PINMUX_PA08D_SERCOM2_PAD0);

	gpio_set_pin_function(PA09, PINMUX_PA09D_SERCOM2_PAD1);
}

void USART_2_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM2);
	_gclk_enable_channel(SERCOM2_GCLK_ID_CORE, CONF_GCLK_SERCOM2_CORE_SRC);
}

void USART_2_init(void)
{
	USART_2_CLOCK_init();
	usart_sync_init(&USART_2, SERCOM2, (void *)NULL);
	USART_2_PORT_init();
}

void USART_3_PORT_init(void)
{

	gpio_set_pin_function(PA16, PINMUX_PA16D_SERCOM3_PAD0);

	gpio_set_pin_function(PA17, PINMUX_PA17D_SERCOM3_PAD1);
}

void USART_3_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

void USART_3_init(void)
{
	USART_3_CLOCK_init();
	usart_sync_init(&USART_3, SERCOM3, (void *)NULL);
	USART_3_PORT_init();
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_pull_mode(PA12,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA12, PINMUX_PA12D_SERCOM4_PAD0);

	gpio_set_pin_pull_mode(PA13,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA13, PINMUX_PA13D_SERCOM4_PAD1);
}

void I2C_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM4);
	_gclk_enable_channel(SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC);
	_gclk_enable_channel(SERCOM4_GCLK_ID_SLOW, CONF_GCLK_SERCOM4_SLOW_SRC);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();
	i2c_m_sync_init(&I2C_0, SERCOM4);
	I2C_0_PORT_init();
}

void USART_1_PORT_init(void)
{

	gpio_set_pin_function(PA22, PINMUX_PA22D_SERCOM5_PAD0);

	gpio_set_pin_function(PA23, PINMUX_PA23D_SERCOM5_PAD1);
}

void USART_1_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM5);
	_gclk_enable_channel(SERCOM5_GCLK_ID_CORE, CONF_GCLK_SERCOM5_CORE_SRC);
}

void USART_1_init(void)
{
	USART_1_CLOCK_init();
	usart_sync_init(&USART_1, SERCOM5, (void *)NULL);
	USART_1_PORT_init();
}

void WDT_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, WDT);
	_gclk_enable_channel(WDT_GCLK_ID, CONF_GCLK_WDT_SRC);
}

void WDT_0_init(void)
{
	WDT_0_CLOCK_init();
	wdt_init(&WDT_0, WDT);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA06

	gpio_set_pin_level(RN2384_RESET,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(RN2384_RESET, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(RN2384_RESET, GPIO_PIN_FUNCTION_OFF);

	ADC_0_init();

	USART_0_init();

	USART_2_init();

	USART_3_init();

	I2C_0_init();

	USART_1_init();

	WDT_0_init();
}
