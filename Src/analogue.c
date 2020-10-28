#include "analogue.h"

volatile uint16_t ana_vlts_values[ANA_AVERAGING_LEN] = {0};
volatile uint16_t ana_amps_values[ANA_AVERAGING_LEN] = {0};

volatile uint32_t ana_vlts_values_ptr = 0;
volatile uint32_t ana_amps_values_ptr = 0;

volatile uint8_t ana_conv_channel = ADC_CHN_VLTS;

void ANA_Start()
{
    // Use timer 17 for ADC conversion initiations, master clock is at 240MHz, output at 50Hz
    htim17.Instance = TIM17;
    htim17.Init.Prescaler = 60000;
    htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim17.Init.Period = 80;
    htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim17.Init.RepetitionCounter = 0;
    htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
    {
        Error_Handler();
    }

    // Disable the output
    ANA_SetOutputRelay(false);

    // Start the DACs
    DAC_Start();

    // Start the timer
    HAL_TIM_Base_Start_IT(&htim17);
}

void ANA_Stop()
{
    // Disable the output
    ANA_SetOutputRelay(false);

    // Set the outputs to 0
    ANA_SetOutputVoltage(0);
    ANA_SetOutputCurrent(0);

    // Stop ADC conversions
    HAL_TIM_Base_Start_IT(&htim17);
}

double ANA_GetOutputVoltage()
{
    volatile double mean = 0; //meas_mean((double*)ana_vlts_values, ANA_AVERAGING_LEN);

    for (uint32_t i = 0; i < ANA_AVERAGING_LEN; i++)
    {
        mean += ana_vlts_values[i];
    }

    mean = mean / (double)ANA_AVERAGING_LEN;

    mean = mean / (double)ANA_VLTS_ADC_CONV_FACTOR;

    return mean;
}

double ANA_GetOutputCurrent()
{
    volatile double mean = 0; //meas_mean((double*)ana_vlts_values, ANA_AVERAGING_LEN);

    for (uint32_t i = 0; i < ANA_AVERAGING_LEN; i++)
    {
        mean += ana_amps_values[i];
    }

    mean = mean / (double)ANA_AVERAGING_LEN;

    mean = mean / (double)ANA_AMPS_ADC_CONV_FACTOR;

    return mean;
}

void ANA_SetOutputVoltage(double voltage)
{
    DAC_SetValue(DAC_VLTS, (uint16_t)(voltage * ANA_VLTS_DAC_CONV_FACTOR));
}

void ANA_SetOutputCurrent(double current)
{
    DAC_SetValue(DAC_AMPS, (uint16_t)(current * ANA_AMPS_DAC_CONV_FACTOR));
}

void ANA_SetOutputRelay(bool state)
{
    HAL_GPIO_WritePin(OUTPUT_RELAY_EN_GPIO_Port, OUTPUT_RELAY_EN_Pin, state);
}

void ANA_TimerHandler()
{
    ADC_StartConversion(ana_conv_channel);
}

void ADC_CallBack(uint16_t value)
{
    /*
    if (ana_conv_channel == ADC_CHN_VLTS)
    {
        // Swap the channel
        ana_conv_channel = ADC_CHN_AMPS;

        // Assign to the relevant averaging array
        ana_vlts_values[ana_vlts_values_ptr++] = value;

        // Deal with pointer overflow
        if (ana_vlts_values_ptr == ANA_AVERAGING_LEN)
            ana_vlts_values_ptr = 0;
    }

    else
    {
        // Swap the channel
        ana_conv_channel = ADC_CHN_VLTS;

        // Assign to the relevant averaging array
        ana_amps_values[ana_amps_values_ptr++] = value;

        // Deal with pointer overflow
        if (ana_amps_values_ptr == ANA_AVERAGING_LEN)
            ana_amps_values_ptr = 0;
    }
    */

    ana_conv_channel = ADC_CHN_VLTS;

    // Assign to the relevant averaging array
    ana_vlts_values[ana_vlts_values_ptr++] = value;

    // Deal with pointer overflow
    if (ana_vlts_values_ptr == ANA_AVERAGING_LEN)
        ana_vlts_values_ptr = 0;
}
