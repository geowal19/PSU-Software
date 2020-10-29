#include "adc.h"

const uint8_t adc_vlts_reading_config[] = {0x43, 0x81, 0x40, 0x00, 0x00};
const uint8_t adc_amps_reading_config[] = {0x43, 0x93, 0x40, 0x00, 0x00};

void ADC_SPI_Transceive(uint8_t *tx_data, uint16_t tx_len, uint8_t *rx_data, uint16_t rx_len)
{
	uint16_t len = tx_len + rx_len;
	uint8_t tx[len], rx[len];

	memcpy(tx, tx_data, tx_len);

	if (HAL_SPI_TransmitReceive(&hspi1, tx, rx, len, 5) != HAL_OK)
	{
		asm("NOP");
	}

	memcpy(rx_data, rx + tx_len, rx_len);
}

void ADC_StartConversion(uint8_t channel)
{
	if (channel == ADC_CHN_VLTS)
	{
		// Send the config
		ADC_SPI_Transceive((uint8_t *)adc_vlts_reading_config, (uint16_t)sizeof(adc_vlts_reading_config), (uint8_t[]){0}, 0);

		// Initiate the measure
		ADC_SPI_Transceive((uint8_t[]){ADC_CMD_SYNC}, 1, (uint8_t[]){0}, 0);
	}

	if (channel == ADC_CHN_AMPS)
	{
		// Send the config
		ADC_SPI_Transceive((uint8_t *)adc_amps_reading_config, (uint16_t)sizeof(adc_amps_reading_config), (uint8_t[]){0}, 0);

		// Initiate the measure
		ADC_SPI_Transceive((uint8_t[]){ADC_CMD_SYNC}, 1, (uint8_t[]){0}, 0);
	}
}

int16_t ADC_ReadValue()
{
	uint8_t data[2] = {0};

	ADC_SPI_Transceive((uint8_t[]){ADC_CMD_RDTA}, 1, data, 2);

	return (int16_t)((data[0] << 8) + (data[1]));
}

void ADC_Handler()
{
	ADC_CallBack(ADC_ReadValue());
}
