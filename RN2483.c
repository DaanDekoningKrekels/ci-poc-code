/*
 * RN2483.c
 *
 * Created: 14-Apr-22 15:14:01
 *  Author: Birk Tamm
 */ 
#include "RN2483.h"
#include "UART0.h"
#include "UART2.h"
#include "driver_init.h"

#define APP_EUI 0000000000000000
#define APP_KEY 9F96481D933BD01F8FDA414DADAE1B06
#define DEV_EUI 0004A30B0020F589
#define PWRIDX 1
#define DR 5
#define ADR on
#define TRY_JOIN 7 // totally arbitrary value, this can be as high or as low as you want. higher values consume more power in areas with bad coverage from The Things Network

bool joined = false;

void RN2483_init(void)
{
	// Reset the RN2483
	gpio_set_pin_level(RN2384_RESET, false); 
	delay_ms(500);
	gpio_set_pin_level(RN2384_RESET, true);
	delay_ms(500); // wait for RN2483 startup
}
void RN2483_reset_band(const char* band)
{
	char *reset = "mac reset ";
	char *command ;
	if((command = malloc(strlen(reset)+strlen(band)+1)) != NULL){
		command[0] = '\0';   // ensures the memory is an empty string
		strcat(command, reset);
		strcat(command, band);
		} else {
		UART2_write("malloc failed!\n");
	}
	
	UART0_write("mac reset deveui\r\n");
}

void RN2483_mac_set(void)
{
	UART2_write("mac set deveui 0004A30B0020F589\n"); // DEBUG
	UART0_write("mac set deveui 0004A30B0020F589\r\n"); // TODO: get deveui from defined DEV_EUI;
	delay_ms(200);
	UART2_write("mac set appeui 0000000000000000\n"); // DEBUG
	UART0_write("mac set appeui 0000000000000000\r\n"); // TODO: get appeui from defined APP_EUI;
	delay_ms(200);
	UART2_write("mac set appkey F96481D933BD01F8FDA414DADAE1B06\n"); // DEBUG
	UART0_write("mac set appkey F96481D933BD01F8FDA414DADAE1B06\r\n"); // TODO: get appkey from defined APP_KEY;
	delay_ms(200);
	UART2_write("mac set pwridx 1\n"); // DEBUG
	UART0_write("mac set pwridx 1\r\n"); // TODO: get pwridx from defined PWRIDX;
	delay_ms(200);
	UART2_write("mac set dr 5\n"); // TODO: DEBUG
	UART0_write("mac set dr 5\r\n"); // TODO: get datarate from defined DR;
	delay_ms(200);
	UART2_write("mac set adr on\n"); // TODO: DEBUG
	UART0_write("mac set adr on\r\n"); // TODO: get adaptive data rate value from defined ADR;
	delay_ms(200);
	UART2_write("mac set ar off\n"); // TODO: DEBUG
	UART0_write("mac set ar off\r\n"); // TODO: set automatic replies off;
	delay_ms(200);
	UART2_write("mac save\n"); // DEBUG
	UART0_write("mac save\r\n"); //save the settings we have set;
}
void RN2483_join(void)
{
	/*
	for (int i; i=0;i<TRY_JOIN && !joined; i++)
	{
		UART0_write("mac join otaa");
		uint8_t *msg;
		io_read(&USART_0.io, &msg, 3);
		if (&msg == "ok")
		{
			UART2_write("message is ok");
			io_read(&USART_0.io, &msg, 3);
			if (&msg == "ac")
			{
				UART2_write("joined!");
				joined = true;
			}
		}
	}
	*/
	UART0_write("mac join otaa\r\n");
}