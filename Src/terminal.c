#include "terminal.h"

volatile uint8_t term_uart_buffer[TERM_BUFFER_LEN];

void TERM_Start()
{
	memset((char*)term_uart_buffer, 0, TERM_BUFFER_LEN);
	HAL_UART_Receive_DMA(&TERM_UART_PERPH, (uint8_t*)term_uart_buffer, TERM_BUFFER_LEN);
}

void TERM_Poll()
{
	if(strstr((const char*)term_uart_buffer, "\n"))
	{
		TERM_Callback((char*)term_uart_buffer);

		TERM_Start();
	}
}

void TERM_Send(char * str)
{
	HAL_UART_Transmit_DMA(&TERM_UART_PERPH, (uint8_t*)str, (uint16_t)strlen(str));
}

void TERM_Log(char * str)
{
#ifdef TERM_LOG
	HAL_UART_Transmit_DMA(&TERM_UART_PERPH, (uint8_t*)str, (uint16_t)strlen(str));
#endif
}


__weak void TERM_Callback(char * str)
{
	asm ("NOP");
}
