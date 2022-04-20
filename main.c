#include <atmel_start.h>
#include <string.h>

#include "UART0.h"
#include "UART2.h"
#include "RN2483.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	UART0_init();
	UART2_init();
	
	UART2_write("Opgestart!\n");
	RN2483_init();
	UART0_write("sys reset\r\n");
	delay_ms(500);
	UART0_write("sys get hweui\r\n");
	delay_ms(100);
	UART0_write("sys get ver\r\n");
	delay_ms(100);
	RN2483_reset_band("868");
	delay_ms(100);
	RN2483_mac_set();
	delay_ms(100);
	/* Replace with your application code */
	while (1) {
		RN2483_join();
		delay_ms(3000);
	}
}

