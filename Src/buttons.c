#include "buttons.h"

const GPIO_TypeDef * button_gpio_ports[] = {BTN_0_GPIO_Port, BTN_1_GPIO_Port, BTN_2_GPIO_Port, BTN_3_GPIO_Port, BTN_4_GPIO_Port, BTN_5_GPIO_Port, BTN_6_GPIO_Port, BTN_7_GPIO_Port, BTN_8_GPIO_Port, BTN_9_GPIO_Port, BTN_CANCEL_GPIO_Port, BTN_DP_GPIO_Port, BTN_VOLTS_GPIO_Port, BTN_AMPS_GPIO_Port, BTN_SHIFT_GPIO_Port, BTN_OUT_CONT_GPIO_Port};
const uint16_t button_gpio_pins[] = {BTN_0_Pin, BTN_1_Pin, BTN_2_Pin, BTN_3_Pin, BTN_4_Pin, BTN_5_Pin, BTN_6_Pin, BTN_7_Pin, BTN_8_Pin, BTN_9_Pin, BTN_CANCEL_Pin, BTN_DP_Pin, BTN_VOLTS_Pin, BTN_AMPS_Pin, BTN_SHIFT_Pin, BTN_OUT_CONT_Pin};

volatile uint32_t button_state = 0;

void BTN_Poll()
{
    uint32_t prev = button_state;
    button_state = 0;

    // Get the current button states
    for(uint8_t i = 0; i < BTN_N_BUTTONS; i++)
    {
        if((button_gpio_ports[i]->IDR & button_gpio_pins[i]) != 0x00U)
        {
            button_state |= (1 << i);
        }
    }

    uint32_t flags = 0;

    // Check for rising edges
    for(uint8_t i = 0; i < BTN_N_BUTTONS; i++)
    {
        if(!(prev & (1 << i)) && (button_state & (1 << i)))
        {
            flags |= (1 << i);
        }
    }

    if(flags)
    {
        BTN_CallBack(flags);
    }
}

__weak void BTN_CallBack(uint32_t button_flags)
{
    asm("NOP");
}
