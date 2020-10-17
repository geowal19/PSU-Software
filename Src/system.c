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
#include "display.h"
#include "gui.h"
#include "sdram.h"
#include "terminal.h"
#include "commands.h"

volatile SysVar sys_var = {0};

volatile uint32_t btn_poll_stamp = 0;
volatile uint32_t ana_poll_stamp = 0;
volatile uint32_t dsp_poll_stamp = 0;

volatile double ana_vlts_current_val = 0;
volatile double ana_amps_current_val = 0;
volatile bool ana_output_en_current_val = false;

volatile char term_string[TERM_BUFFER_LEN] = {0};
volatile CMDContainer command = {0};

void System()
{
	SYS_Start();

	SYS_Loop();
}

void SYS_Start()
{
	TERM_Log("SYS_Start: System starting.\n");

	// Output 
	ANA_Start();


	// Display inits
	SDRAM_Init();
	DISPLAY_Init();


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
			
			DISPLAY_Refresh();
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

		// If there's something has come in on the uart
		if(term_string[0])
		{
			// Parse the command
			command = CMD_Parser((char*)term_string);

			// Reset the input string
			memset((char*)term_string, 0, TERM_BUFFER_LEN);
		}

		// If there's a command to execute
		if(command.cmd)
		{
			// Reset the command
			command.cmd = CMD_NOP;
		}

		

		

		// Do some other stuff...
	}
}

void SYS_CommandExecuter()
{
	/*

		Do nothing.

	*/
	if(command.cmd == CMD_NOP)
	{

	}

	/*

		Set the output voltage.

	*/
	if(command.cmd == CMD_SET_VLTS)
	{
		double voltage = atof((char*)command.params[0]);

		if(voltage < SYS_MAX_VOLTAGE && voltage > SYS_MIN_VOLTAGE)
		{
			sys_var.output_voltage = voltage;

			TERM_Send("OK\n");
		}

		else
		{
			TERM_Send("ERROR. Requested voltage outside of valid range.\n");
		}
	}

	/*

		Set the output current.

	*/
	if(command.cmd == CMD_SET_AMPS)
	{
		double current = atof((char*)command.params[0]);

		if(current < SYS_MAX_CURRENT && current > SYS_MIN_CURRENT)
		{
			sys_var.output_current = current;

			TERM_Send("OK\n");
		}

		else
		{
			TERM_Send("ERROR. Requested current outside of valid range.\n");
		}
	}

	

}

void SYS_ButtonHandler(uint32_t button_press)
{
	
}

void BTN_CallBack(uint32_t button_flags)
{
	SYS_ButtonHandler(button_flags);
}

void TERM_Callback(char * str)
{
	asm ("NOP");
}