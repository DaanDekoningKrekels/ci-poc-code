#include <atmel_start.h>
#include <string.h>

#include "UART0.h"
#include "UART2.h"
#include "UART3.h"
#include "RN2483.h"
#include "driver_examples.h"

int main(void){
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	UART0_init();
	UART2_init();
	I2C_init();
	UART3_init();
	RN2483_init();
	
	UART2_write("Start up!\n");
	delay_ms(200);
	
	//RN2483_mac_set();
	//delay_ms(500);
	
	/* Replace with your application code */
	while (1) {
		RN2483_join();
		delay_ms(200);
		
		delay_ms(3000);
		UART2_write("data incoming\n");
		delay_ms(100);
		I2C_read();
		delay_ms(100);
		UART2_write("data finished\n");
		delay_ms(100);
	}
}