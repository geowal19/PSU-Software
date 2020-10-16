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

volatile SysVar sys_var = {0};

volatile uint32_t btn_poll_stamp = 0;
volatile uint32_t ana_poll_stamp = 0;
volatile uint32_t dsp_poll_stamp = 0;

volatile double ana_vlts_current_val = 0;
volatile double ana_amps_current_val = 0;
volatile bool ana_output_en_current_val = false;

void System()
{
	SYS_Start();

	SYS_Loop();
}

void SYS_Start()
{
	TERM_Log("SYS_Start: System starting.\n");

	ANA_Start();
}

void SYS_Loop()
{
	uint32_t tick = 0;

	while(1)
	{
		tick = HAL_GetTick();

		// Check the buttons
		if(tick > (btn_poll_stamp + SYS_BTN_POLL_TIME_MS))
		{
			btn_poll_stamp = tick;

			BTN_Poll();
		}

		// Update the analogue values
		if(tick > (ana_poll_stamp + SYS_ANA_POLL_TIME_MS))
		{
			ana_poll_stamp = tick;

			sys_var.read_voltage = ANA_GetOutputVoltage();
			sys_var.read_current = ANA_GetOutputCurrent();
		}

		// Update the display
		if(tick > (dsp_poll_stamp + SYS_DSP_POLL_TIME_MS))
		{
			dsp_poll_stamp = tick;

		}

		// Update the output voltage
		if(sys_var.output_voltage != ana_vlts_current_val)
		{
			ana_vlts_current_val = sys_var.output_voltage;

			ANA_SetOutputVoltage(sys_var.output_voltage);
		}

		// Update the output current
		if(sys_var.output_current != ana_amps_current_val)
		{
			ana_amps_current_val = sys_var.output_current;

			ANA_SetOutputCurrent(sys_var.output_current);
		}

		// Update the relay
		if(sys_var.output_en != ana_output_en_current_val)
		{
			ana_output_en_current_val = sys_var.output_en;

			ANA_SetOutputRelay(sys_var.output_en);
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