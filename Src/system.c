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

volatile uint32_t btn_flags = 0;

volatile uint8_t display_brightness_var = 0;
volatile bool display_refresh = true;

void System()
{
	SYS_Start();

	SYS_Loop();
}

void SYS_Start()
{
	TERM_Start();

	// Output
	//ANA_Start();

	// Display inits
	SDRAM_Init();
	DISPLAY_Init();
	GUI_Init();
	sys_var.display_brightness = 50;
}

void SYS_Loop()
{
	TERM_Print("PSU OK\n");

	uint32_t tick = 0;

	while (1)
	{
		tick = HAL_GetTick();

		// Poll the terminal
		TERM_Poll();

		// Check the buttons
		if (tick > (btn_poll_stamp + SYS_BTN_POLL_TIME_MS))
		{
			btn_poll_stamp = tick;

			BTN_Poll();

			display_refresh = true;
		}
		/*
		// Update the analogue values
		if (tick > (ana_poll_stamp + SYS_ANA_POLL_TIME_MS))
		{
			ana_poll_stamp = tick;

			sys_var.read_voltage = ANA_GetOutputVoltage();
			sys_var.read_current = ANA_GetOutputCurrent();

			display_refresh = true;
		}
	*/
		// Update the display
		if (display_refresh)
		{
			display_refresh = false;

			GUI_UpdateDisplay(sys_var.output_voltage, sys_var.output_current,
							  sys_var.read_voltage, sys_var.read_current, sys_var.output_en,
							  (char *)sys_var.user_input);

			DISPLAY_Refresh();
		}
		/*
		// Update the output voltage
		if (sys_var.output_voltage != ana_vlts_current_val)
		{
			ana_vlts_current_val = sys_var.output_voltage;

			ANA_SetOutputVoltage(sys_var.output_voltage);

			display_refresh = true;
		}

		// Update the output current
		if (sys_var.output_current != ana_amps_current_val)
		{
			ana_amps_current_val = sys_var.output_current;

			ANA_SetOutputCurrent(sys_var.output_current);

			display_refresh = true;
		}

		// Update the relay
		if (sys_var.output_en != ana_output_en_current_val)
		{
			ana_output_en_current_val = sys_var.output_en;

			ANA_SetOutputRelay(sys_var.output_en);

			display_refresh = true;
		}
*/
		// If there's something has come in on the uart
		if (term_string[0])
		{
			// Parse the command
			command = CMD_Parser((char *)term_string);

			// Reset the input string
			memset((char *)term_string, 0, TERM_BUFFER_LEN);
		}

		// If there's a command to execute
		if (command.cmd)
		{
			SYS_CommandExecuter();

			// Reset the command
			command.cmd = CMD_NOP;
		}

		// If there's any button presses
		if (btn_flags)
		{
			uint32_t mask = 0;

			// Go through all the flags one by one
			for (uint8_t i = 0; i < 32; i++)
			{
				mask = (1 << i);

				// Do the right thing, bro
				if (btn_flags & mask)
				{
					SYS_ButtonHandler(mask);
				}
			}

			// Reset the flags
			btn_flags = 0;
		}

		// Change in display brightness
		if (sys_var.display_brightness != display_brightness_var)
		{
			display_brightness_var = sys_var.display_brightness;

			DISPLAY_SetBackLight(sys_var.display_brightness);
		}
	}
}

void SYS_CommandExecuter()
{
	/*

		Do nothing.

	*/
	if (command.cmd == CMD_NOP)
	{
		asm("NOP");
	}

	/*

		Set the output voltage.

	*/
	if (command.cmd == CMD_SET_VLTS)
	{
		// Number of params check
		if (command.n_params)
		{
			double voltage = atof((char *)command.params[0]);

			if (voltage < SYS_MAX_VOLTAGE && voltage > SYS_MIN_VOLTAGE)
			{
				sys_var.output_voltage = voltage;

				TERM_Send("OK.\n");
			}

			else
			{
				TERM_Send("ERROR. Requested voltage outside of valid range.\n");
			}
		}

		else
		{
			TERM_Send("ERROR. Not enough parameters.\n");
		}
	}

	/*

		Set the output current.

	*/
	if (command.cmd == CMD_SET_AMPS)
	{
		// Number of params check
		if (command.n_params)
		{
			double current = atof((char *)command.params[0]);

			if (current < SYS_MAX_CURRENT && current > SYS_MIN_CURRENT)
			{
				sys_var.output_current = current;

				TERM_Send("OK.\n");
			}

			else
			{
				TERM_Send("ERROR. Requested current outside of valid range.\n");
			}
		}

		else
		{
			TERM_Send("ERROR. Not enough parameters.\n");
		}
	}

	/*

		Get the output voltage.

	*/
	if (command.cmd == CMD_GET_VLTS)
	{
		TERM_Print("%fV\n", sys_var.read_voltage);
	}

	/*

		Get the output current.

	*/
	if (command.cmd == CMD_GET_AMPS)
	{
		TERM_Print("%fA\n", sys_var.read_current);
	}

	/*

		Get the output state.

	*/
	if (command.cmd == CMD_GET_OUT_STATE)
	{
		TERM_Print("%u\n", sys_var.output_en);
	}

	/*

		Set the output state.

	*/
	if (command.cmd == CMD_SET_OUT_STATE)
	{
		// Number of params check
		if (command.n_params < 1)
		{
			uint8_t state = atoi((char *)command.params[0]);

			if (state)
			{
				sys_var.output_en = true;
			}

			else
			{
				sys_var.output_en = false;
			}

			TERM_Send("OK.\n");
		}

		else
		{
			TERM_Send("ERROR. Not enough parameters.\n");
		}
	}

	/*

		Set the display brightness.

	*/
	if (command.cmd == CMD_SET_BRIGHTNESS)
	{
		// Number of params check
		if (command.n_params < 1)
		{
			uint8_t brightness = atoi((char *)command.params[0]);

			if (brightness > 100)
			{
				sys_var.display_brightness = 100;
			}

			else
			{
				sys_var.display_brightness = brightness;
			}

			TERM_Send("OK.\n");
		}

		else
		{
			TERM_Send("ERROR. Not enough parameters.\n");
		}
	}
}

void SYS_ButtonHandler(uint32_t button_press)
{
	double temp = 0;

	switch (button_press)
	{
	case BTN_0_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "0");
		}
		break;

	case BTN_1_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "1");
		}
		break;

	case BTN_2_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "2");
		}
		break;

	case BTN_3_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "3");
		}
		break;

	case BTN_4_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "4");
		}
		break;

	case BTN_5_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "5");
		}
		break;

	case BTN_6_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "6");
		}
		break;

	case BTN_7_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "7");
		}
		break;

	case BTN_8_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "8");
		}
		break;

	case BTN_9_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, "9");
		}
		break;

	case BTN_CLR_FLAG:
		memset((char *)sys_var.user_input, 0, SYS_USER_INPUT_LEN);
		break;

	case BTN_DP_FLAG:
		if (strlen((char *)sys_var.user_input) < SYS_USER_INPUT_LEN)
		{
			strcat((char *)sys_var.user_input, ".");
		}
		break;

	case BTN_A_FLAG:
		temp = (double)atof((char *)sys_var.user_input);
		if (temp < SYS_MAX_VOLTAGE && temp > 0)
		{
			sys_var.output_voltage = temp;
		}
		memset((char *)sys_var.user_input, 0, SYS_USER_INPUT_LEN);
		break;

	case BTN_V_FLAG:
		temp = (double)atof((char *)sys_var.user_input);
		if (temp < SYS_MAX_CURRENT && temp > 0)
		{
			sys_var.output_current = temp;
		}
		memset((char *)sys_var.user_input, 0, SYS_USER_INPUT_LEN);
		break;

	case BTN_ONOFF_FLAG:
		sys_var.output_en = 0;
		break;

	case BTN_S_0_FLAG:

		break;

	case BTN_S_1_FLAG:
		if (sys_var.display_brightness != 0)
		{
			sys_var.display_brightness--;
		}
		break;

	case BTN_S_2_FLAG:

		break;

	case BTN_S_3_FLAG:

		break;

	case BTN_S_4_FLAG:

		break;

	case BTN_S_5_FLAG:

		break;

	case BTN_S_6_FLAG:

		break;

	case BTN_S_7_FLAG:
		if (sys_var.display_brightness < 100)
		{
			sys_var.display_brightness++;
		}
		break;

	case BTN_S_8_FLAG:

		break;

	case BTN_S_9_FLAG:

		break;

	case BTN_S_CLR_FLAG:
		sys_var.user_input[strlen((char *)sys_var.user_input)] = 0;
		break;

	case BTN_S_DP_FLAG:

		break;

	case BTN_S_A_FLAG:
		sys_var.output_voltage = SYS_MAX_VOLTAGE;
		break;

	case BTN_S_V_FLAG:
		sys_var.output_current = SYS_MAX_CURRENT;
		break;

	case BTN_S_ONOFF_FLAG:
		sys_var.output_en = 1;
		break;
	}
}

void BTN_CallBack(uint32_t button_flags)
{
	btn_flags = button_flags;
}

void TERM_Callback(char *str)
{
	memcpy((char *)term_string, str, TERM_BUFFER_LEN);
}