#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"

#include "spi.h"
#include "gpio.h"

#define ADC_DATA_LEN        256

#define ADC_CMD_SYNC        0x08
#define ADC_CMD_RDTA        0x10

enum {ADC_CHN_VLTS, ADC_CHN_AMPS};

void ADC_StartConversion(uint8_t channel);
uint16_t ADC_ReadValue();
void ADC_Handler();
__weak void ADC_CallBack(uint16_t value);

#endif