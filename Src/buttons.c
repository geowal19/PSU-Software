#include "buttons.h"

const GPIO_TypeDef *button_gpio_ports[] = {BTN_0_GPIO_Port, BTN_1_GPIO_Port, BTN_2_GPIO_Port, BTN_3_GPIO_Port, BTN_4_GPIO_Port, BTN_5_GPIO_Port, BTN_6_GPIO_Port, BTN_7_GPIO_Port, BTN_8_GPIO_Port, BTN_9_GPIO_Port, BTN_CANCEL_GPIO_Port, BTN_DP_GPIO_Port, BTN_VOLTS_GPIO_Port, BTN_AMPS_GPIO_Port, BTN_SHIFT_GPIO_Port, BTN_OUT_CONT_GPIO_Port};
const uint16_t button_gpio_pins[] = {BTN_0_Pin, BTN_1_Pin, BTN_2_Pin, BTN_3_Pin, BTN_4_Pin, BTN_5_Pin, BTN_6_Pin, BTN_7_Pin, BTN_8_Pin, BTN_9_Pin, BTN_CANCEL_Pin, BTN_DP_Pin, BTN_VOLTS_Pin, BTN_AMPS_Pin, BTN_SHIFT_Pin, BTN_OUT_CONT_Pin};

volatile uint32_t button_state = 0;

void BTN_Poll()
{
	// Extra shifting for shift button press
	uint8_t shift_state = BTN_ReadButton(BTN_SHIFT);
	if (shift_state)
		shift_state = 16;

	// Remember the previous state
	uint32_t prev = button_state;
	button_state = 0;

	// Get the current button states
	for (uint8_t i = 0; i < BTN_N_BUTTONS; i++)
	{
		if ((button_gpio_ports[i]->IDR & button_gpio_pins[i]) != 0x00U)
		{
			button_state |= (1 << i);
		}
	}

	uint32_t flags = 0;

	// Check for rising edges
	for (uint8_t i = 0; i < BTN_N_BUTTONS; i++)
	{
		if (!(prev & (1 << i)) && (button_state & (1 << i)))
		{
			flags |= (1 << (i + shift_state));
		}
	}

	// Send the flags if there are any
	if (flags)
	{
		BTN_CallBack(flags);
	}
}

bool BTN_ReadButton(uint8_t button)
{
	if (button > BTN_ONOFF)
		return false;

	if ((button_gpio_ports[button]->IDR & button_gpio_pins[button]) != 0x00U)
	{
		return true;
	}

	return false;
}

__weak void BTN_CallBack(uint32_t button_flags)
{
	asm("NOP");
}
