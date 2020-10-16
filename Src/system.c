#include "system.h"

#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "ltdc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

#include "adc.h"
#include "analogue.h"
#include "buttons.h"
#include "dac.h"
#include "gui.h"
#include "sdram.h"
#include "terminal.h"

volatile uint32_t btn_poll_stamp = 0;

void System()
{
	SYS_Start();

	SYS_Loop();
}

void SYS_Start()
{
	TERM_Log("SYS_Start: System starting.\n");
}

void SYS_Loop()
{
	while(1)
	{
		// Check the buttons
		if(HAL_GetTick() > (btn_poll_stamp + SYS_BTN_POLL_TIME_MS))
		{
			btn_poll_stamp = HAL_GetTick();

			BTN_Poll();
		}

		// Do some other stuff...
	}
}

void BTN_CallBack(uint32_t button_flags)
{
	asm ("NOP");
}

void TERM_Callback(char * str)
{
	asm ("NOP");
}