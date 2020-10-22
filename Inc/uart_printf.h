#ifndef __U_PRINTF_H__
#define __U_PRINTF_H__

#include "main.h"

#include "usart.h"

void __uart_printf(UART_HandleTypeDef * huart, const char * format, va_list va_args);

#endif