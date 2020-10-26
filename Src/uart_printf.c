#include "uart_printf.h"

void __uart_printf(UART_HandleTypeDef *huart, const char *format, va_list va_args)
{
	uint8_t str[1024];
	memset(str, 0, 1024);
	uint32_t str_len = 0;

	while (*format != '\0')
	{
		// If a number
		if (*format == '%')
		{
			// Get to the specificer
			format++;

			// Do the right thing bro
			switch (*format)
			{
			case 's':
				str_len = strlen((char *)str);
				sprintf((char *)&str[str_len], "%s", va_arg(va_args, const char *));
				break;

			case 'd':
				str_len = strlen((char *)str);
				sprintf((char *)&str[str_len], "%d", va_arg(va_args, int));
				break;

			case 'f':
				str_len = strlen((char *)str);
				sprintf((char *)&str[str_len], "%.3f", va_arg(va_args, double));
				break;

			case 'u':
				str_len = strlen((char *)str);
				sprintf((char *)&str[str_len], "%u", va_arg(va_args, int));
				break;
			}
		}
		// Otherwise it's just a char
		else
		{
			str_len = strlen((char *)str);
			str[str_len] = *format;
		}

		// Increment the argument count
		format++;
	}

	// Print out on the RS485
	HAL_UART_Transmit_IT(huart, str, strlen((char *)str));

	va_end(va_args);
}