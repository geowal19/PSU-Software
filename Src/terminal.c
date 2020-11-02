#include "terminal.h"

#include "uart_printf.h"

volatile uint8_t term_uart_buffer[TERM_BUFFER_LEN];

void TERM_Start()
{
	memset((char *)term_uart_buffer, 0, TERM_BUFFER_LEN);
	HAL_UART_Abort_IT(&TERM_UART_PERPH);
	HAL_UART_Receive_IT(&TERM_UART_PERPH, (uint8_t *)term_uart_buffer, TERM_BUFFER_LEN);
}

void TERM_Poll()
{
	if (strstr((const char *)term_uart_buffer, "\n"))
	{
		TERM_Callback((char *)term_uart_buffer);

		TERM_Start();
	}
}

void TERM_Send(char *str)
{
	HAL_UART_Transmit_IT(&TERM_UART_PERPH, (uint8_t *)str, (uint16_t)strlen(str));
}

void TERM_SendStream(uint32_t tick, double volts, double amps)
{
	char str[100] = {0};
	sprintf(str, "%lu,%f,%f\n", tick, volts, amps);
	HAL_UART_Transmit(&TERM_UART_PERPH, (uint8_t *)str, (uint16_t)strlen(str), 10);
}

void TERM_Log(char *str)
{
#ifdef TERM_LOG
	HAL_UART_Transmit_IT(&TERM_UART_PERPH, (uint8_t *)str, (uint16_t)strlen(str));
#endif
}

void TERM_Print(const char *format, ...)
{
	va_list _args;

	va_start(_args, format);

	__uart_printf(&TERM_UART_PERPH, format, _args);
}

__weak void TERM_Callback(char *str)
{
	asm("NOP");
}
