#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"

#include "spi.h"
#include "gpio.h"



void ADC_Start();
uint16_t ADC_ReadGetValue();
void ADC_Handler();
void ADC_CallBack();

#endif