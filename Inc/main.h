/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_AMPS_Pin GPIO_PIN_13
#define BTN_AMPS_GPIO_Port GPIOC
#define BTN_CANCEL_Pin GPIO_PIN_14
#define BTN_CANCEL_GPIO_Port GPIOC
#define BTN_0_Pin GPIO_PIN_15
#define BTN_0_GPIO_Port GPIOC
#define OUTPUT_RELAY_EN_Pin GPIO_PIN_6
#define OUTPUT_RELAY_EN_GPIO_Port GPIOF
#define BTN_3_Pin GPIO_PIN_7
#define BTN_3_GPIO_Port GPIOF
#define BTN_9_Pin GPIO_PIN_8
#define BTN_9_GPIO_Port GPIOF
#define BTN_2_Pin GPIO_PIN_9
#define BTN_2_GPIO_Port GPIOF
#define ADC_DRDY_Pin GPIO_PIN_1
#define ADC_DRDY_GPIO_Port GPIOC
#define ADC_DRDY_EXTI_IRQn EXTI1_IRQn
#define DISP_PWM_Pin GPIO_PIN_0
#define DISP_PWM_GPIO_Port GPIOA
#define ADC_SPI_SCLK_Pin GPIO_PIN_5
#define ADC_SPI_SCLK_GPIO_Port GPIOA
#define ADC_SPI_MOSI_Pin GPIO_PIN_7
#define ADC_SPI_MOSI_GPIO_Port GPIOA
#define BTN_6_Pin GPIO_PIN_4
#define BTN_6_GPIO_Port GPIOC
#define BTN_DP_Pin GPIO_PIN_5
#define BTN_DP_GPIO_Port GPIOC
#define BTN_VOLTS_Pin GPIO_PIN_2
#define BTN_VOLTS_GPIO_Port GPIOB
#define BTN_5_Pin GPIO_PIN_12
#define BTN_5_GPIO_Port GPIOB
#define BTN_8_Pin GPIO_PIN_13
#define BTN_8_GPIO_Port GPIOB
#define FT_UART_RX_Pin GPIO_PIN_14
#define FT_UART_RX_GPIO_Port GPIOB
#define FT_UART_TX_Pin GPIO_PIN_15
#define FT_UART_TX_GPIO_Port GPIOB
#define BTN_1_Pin GPIO_PIN_11
#define BTN_1_GPIO_Port GPIOD
#define BTN_4_Pin GPIO_PIN_12
#define BTN_4_GPIO_Port GPIOD
#define BTN_7_Pin GPIO_PIN_13
#define BTN_7_GPIO_Port GPIOD
#define BTN_OUT_CONT_Pin GPIO_PIN_2
#define BTN_OUT_CONT_GPIO_Port GPIOG
#define BTN_SHIFT_Pin GPIO_PIN_3
#define BTN_SHIFT_GPIO_Port GPIOG
#define DISP_EN_Pin GPIO_PIN_8
#define DISP_EN_GPIO_Port GPIOC
#define ADC_SPI_MISO_Pin GPIO_PIN_9
#define ADC_SPI_MISO_GPIO_Port GPIOG
#define ADC_SPI_CS_Pin GPIO_PIN_10
#define ADC_SPI_CS_GPIO_Port GPIOG
#define DAC_I2C_SCL_Pin GPIO_PIN_6
#define DAC_I2C_SCL_GPIO_Port GPIOB
#define DAC_I2C_SDA_Pin GPIO_PIN_7
#define DAC_I2C_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
