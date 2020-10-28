#include "dac.h"

const uint8_t dac_i2c_addr[] = {DAC_VLTS_I2C_ADDR, DAC_AMPS_I2C_ADDR};

/*
    Both DACS should have an output gain of x1
    The voltage DAC should have a vref gain of x1
    The amps DAC should have a vref gain of x0.5

    Initially, both DACs output's are set to 0
 */

void DAC_Start()
{
	// Setup the voltage DAC
	if (HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)dac_i2c_addr[DAC_VLTS], (uint8_t[]){DAC_CMD_GAIN, 1, 1}, 3, 50) != HAL_OK)
	{
		asm("NOP");
	}
	if (HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)dac_i2c_addr[DAC_VLTS], (uint8_t[]){DAC_CMD_DATA, 0, 0}, 3, 50) != HAL_OK)
	{
		asm("NOP");
	}

	// Setup the current DAC
	if (HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)dac_i2c_addr[DAC_AMPS], (uint8_t[]){DAC_CMD_GAIN, 1, 0}, 3, 50) != HAL_OK)
	{
		asm("NOP");
	}
	if (HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)dac_i2c_addr[DAC_AMPS], (uint8_t[]){DAC_CMD_DATA, 0, 0}, 3, 50) != HAL_OK)
	{
		asm("NOP");
	}
}

void DAC_SetValue(uint8_t device, uint16_t value)
{

	uint8_t dac_data[] = {DAC_CMD_DATA, 0xFF & (value >> 8), value & 0xFF};

	if (HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)dac_i2c_addr[device], dac_data, 3, 50) != HAL_OK)
	{
		asm("NOP");
	}
}
