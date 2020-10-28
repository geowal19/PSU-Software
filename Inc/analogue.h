#ifndef __ANALOGUE_H__
#define __ANALOGUE_H__

#include "main.h"

#include "tim.h"

#include "adc.h"
#include "dac.h"
#include "maths.h"

#define ANA_AVERAGING_LEN 10

#define ANA_VLTS_ADC_CONV_FACTOR (3700.8)
#define ANA_AMPS_ADC_CONV_FACTOR (37008)
#define ANA_VLTS_DAC_CONV_FACTOR (6553.5)
#define ANA_AMPS_DAC_CONV_FACTOR (65535)

void ANA_Start();
void ANA_Stop();

double ANA_GetOutputVoltage();
double ANA_GetOutputCurrent();

void ANA_SetOutputVoltage(double voltage);
void ANA_SetOutputCurrent(double current);

void ANA_SetOutputRelay(bool state);

void ANA_TimerHandler();

#endif