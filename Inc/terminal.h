#ifndef __TER_H__
#define __TER_H__

#include "main.h"

#include "usart.h"

#define TERM_BUFFER_LEN     256
#define TERM_UART_PERPH     huart1

void TERM_Start();
void TERM_Poll();
void TERM_Send(char * str);
void TERM_Log(char * str);
void TERM_Print(const char * format, ... );
void TERM_Callback(char * str);

#endif