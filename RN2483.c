/*
 * RN2483.c
 *
 * Created: 14-Apr-22 15:14:01
 *  Author: Birk Tamm
 */ 

#include "RN2483.h"
#include "UART0.h"
#include "UART3.h"
#include "UART2.h"
#include "driver_init.h"

#define APP_EUI 0000000000000000
#define APP_KEY 9F96481D933BD01F8FDA414DADAE1B06
#define DEV_EUI 0004A30B0020F589
#define PWRIDX 1
#define DR 5
#define ADR on

void RN2483_init(void)
{
	// Reset the RN2483
	gpio_set_pin_level(RN2384_RESET, false); 
	delay_ms(500);
	gpio_set_pin_level(RN2384_RESET, true);
	delay_ms(500); // wait for RN2483 startup
}
void RN2483_mac_set(void)
{
	UART0_write("mac reset 868\r\n", 1);
	delay_ms(500);
	UART2_write("mac set deveui 3004A30B0020F589\n"); // DEBUG
	UART0_write("mac set deveui 3004A30B0020F589\r\n", 1); // TODO: get deveui from defined DEV_EUI;
	delay_ms(500);
	UART2_write("mac set appeui 0000000000000000\n"); // DEBUG
	UART0_write("mac set appeui 0000000000000000\r\n", 1); // TODO: get appeui from defined APP_EUI;
	delay_ms(500);
	UART2_write("mac set appkey 9643F6ED461630F9A6716C2B3529DA3B\n"); // DEBUG
	UART0_write("mac set appkey 9643F6ED461630F9A6716C2B3529DA3B\r\n", 1); // TODO: get appkey from defined APP_KEY;
	delay_ms(500);
	UART2_write("mac set pwridx 1\n"); // DEBUG
	UART0_write("mac set pwridx 1\r\n", 1); // TODO: get pwridx from defined PWRIDX;
	delay_ms(500);
	UART2_write("mac set dr 5\n"); // TODO: DEBUG
	UART0_write("mac set dr 5\r\n", 1); // TODO: get datarate from defined DR;
	delay_ms(500);
	UART2_write("mac set adr on\n"); // TODO: DEBUG
	UART0_write("mac set adr on\r\n", 1); // TODO: get adaptive data rate value from defined ADR;
	delay_ms(500);
	UART2_write("mac set ar off\n"); // TODO: DEBUG
	UART0_write("mac set ar off\r\n", 1); // TODO: set automatic replies off;
	delay_ms(500);
	UART2_write("mac save\n"); // DEBUG
	UART0_write("mac save\r\n", 1); //save the settings we have set;
}
void RN2483_join(void)
{
	uint8_t i = 0;
	while (i<7){
		UART0_write("mac join otaa\r\n", 1);
		delay_ms(7000);
		i++;
	}
}
void RN2483_send(uint8_t *data) {
	char msgBuffer[4*2 + 1];
	char buffer[3];
	for (unsigned i=0; i<4; i++) {
		sprintf(buffer, "%02X", data[i]);
		memcpy(&msgBuffer[i*2], &buffer, sizeof(buffer));
	}
	UART0_write("mac tx uncnf 1 ", 0);
	delay_ms(200);
	UART0_write(msgBuffer, 0);
	delay_ms(200);
	UART0_write("\r\n", 1);
	delay_ms(200);
}