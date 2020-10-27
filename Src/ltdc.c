/**
 ******************************************************************************
 * File Name          : LTDC.c
 * Description        : This file provides code for the configuration
 *                      of the LTDC instances.
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

/* Includes ------------------------------------------------------------------*/
#include "ltdc.h"

/* USER CODE BEGIN 0 */
#define GFXMMU_VIRTUAL_BUFFER0_BASE 0
/* USER CODE END 0 */

LTDC_HandleTypeDef hltdc;

/* LTDC init function */
void MX_LTDC_Init(void)
{
}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef *ltdcHandle)
{

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if (ltdcHandle->Instance == LTDC)
	{
		/* USER CODE BEGIN LTDC_MspInit 0 */

		/* USER CODE END LTDC_MspInit 0 */
		/* LTDC clock enable */
		__HAL_RCC_LTDC_CLK_ENABLE();

		__HAL_RCC_GPIOE_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();
		/**LTDC GPIO Configuration
		   PE4     ------> LTDC_B0
		   PE5     ------> LTDC_G0
		   PE6     ------> LTDC_G1
		   PF10     ------> LTDC_DE
		   PA1     ------> LTDC_R2
		   PA2     ------> LTDC_R1
		   PA3     ------> LTDC_B5
		   PA4     ------> LTDC_VSYNC
		   PA6     ------> LTDC_G2
		   PB0     ------> LTDC_R3
		   PB1     ------> LTDC_R6
		   PB10     ------> LTDC_G4
		   PB11     ------> LTDC_G5
		   PG6     ------> LTDC_R7
		   PG7     ------> LTDC_CLK
		   PC6     ------> LTDC_HSYNC
		   PC7     ------> LTDC_G6
		   PC9     ------> LTDC_G3
		   PA8     ------> LTDC_B3
		   PA9     ------> LTDC_R5
		   PA10     ------> LTDC_B4
		   PA11     ------> LTDC_R4
		   PD3     ------> LTDC_G7
		   PD6     ------> LTDC_B2
		   PG12     ------> LTDC_B1
		   PG13     ------> LTDC_R0
		   PB8     ------> LTDC_B6
		   PB9     ------> LTDC_B7
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_9 | GPIO_PIN_11;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_8 | GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_12 | GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF10_LTDC;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_8;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF13_LTDC;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF12_LTDC;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_3 | GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		/* USER CODE BEGIN LTDC_MspInit 1 */

		/* USER CODE END LTDC_MspInit 1 */
	}
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef *ltdcHandle)
{

	if (ltdcHandle->Instance == LTDC)
	{
		/* USER CODE BEGIN LTDC_MspDeInit 0 */

		/* USER CODE END LTDC_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_LTDC_CLK_DISABLE();

		/**LTDC GPIO Configuration
		   PE4     ------> LTDC_B0
		   PE5     ------> LTDC_G0
		   PE6     ------> LTDC_G1
		   PF10     ------> LTDC_DE
		   PA1     ------> LTDC_R2
		   PA2     ------> LTDC_R1
		   PA3     ------> LTDC_B5
		   PA4     ------> LTDC_VSYNC
		   PA6     ------> LTDC_G2
		   PB0     ------> LTDC_R3
		   PB1     ------> LTDC_R6
		   PB10     ------> LTDC_G4
		   PB11     ------> LTDC_G5
		   PG6     ------> LTDC_R7
		   PG7     ------> LTDC_CLK
		   PC6     ------> LTDC_HSYNC
		   PC7     ------> LTDC_G6
		   PC9     ------> LTDC_G3
		   PA8     ------> LTDC_B3
		   PA9     ------> LTDC_R5
		   PA10     ------> LTDC_B4
		   PA11     ------> LTDC_R4
		   PD3     ------> LTDC_G7
		   PD6     ------> LTDC_B2
		   PG12     ------> LTDC_B1
		   PG13     ------> LTDC_R0
		   PB8     ------> LTDC_B6
		   PB9     ------> LTDC_B7
		 */
		HAL_GPIO_DeInit(GPIOE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6);

		HAL_GPIO_DeInit(GPIOF, GPIO_PIN_10);

		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11);

		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_8 | GPIO_PIN_9);

		HAL_GPIO_DeInit(GPIOG, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_12 | GPIO_PIN_13);

		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9);

		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_3 | GPIO_PIN_6);

		/* USER CODE BEGIN LTDC_MspDeInit 1 */

		/* USER CODE END LTDC_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
