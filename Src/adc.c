#include "adc.h"

void ADC_SPI_Transceive(uint8_t * tx_data, uint16_t tx_len, uint8_t * rx_data, uint16_t rx_len)
{
    uint16_t len = rx_len + rx_len;
    uint8_t tx[len], rx[len];

    memcpy(tx, tx_data, tx_len);

    HAL_SPI_TransmitReceive(&hspi1, tx, rx, len, 5);

    memcpy(rx_data, rx, rx_len);
}

void ADC_Start()
{

}

uint16_t ADC_ReadGetValue()
{

    return 0;
}

void ADC_Handler()
{

}

__weak void ADC_CallBack()
{
    asm("NOP");
}

