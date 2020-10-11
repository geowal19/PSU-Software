/**
 ******************************************************************************
 * File Name          : TIM.c
 * Description        : This file provides code for the configuration
 *                      of the TIM instances.
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
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim14;
TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;

/* TIM2 init function */
void MX_TIM2_Init(void)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 0;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 4294967295;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_TIM_MspPostInit(&htim2);

}
/* TIM6 init function */
void MX_TIM6_Init(void)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim6.Instance = TIM6;
	htim6.Init.Prescaler = 0;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.Period = 65535;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}

}
/* TIM7 init function */
void MX_TIM7_Init(void)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim7.Instance = TIM7;
	htim7.Init.Prescaler = 0;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = 65535;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}

}
/* TIM13 init function */
void MX_TIM13_Init(void)
{

	htim13.Instance = TIM13;
	htim13.Init.Prescaler = 0;
	htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim13.Init.Period = 65535;
	htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
	{
		Error_Handler();
	}

}
/* TIM14 init function */
void MX_TIM14_Init(void)
{

	htim14.Instance = TIM14;
	htim14.Init.Prescaler = 0;
	htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim14.Init.Period = 65535;
	htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
	{
		Error_Handler();
	}

}
/* TIM16 init function */
void MX_TIM16_Init(void)
{

	htim16.Instance = TIM16;
	htim16.Init.Prescaler = 0;
	htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim16.Init.Period = 65535;
	htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim16.Init.RepetitionCounter = 0;
	htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
	{
		Error_Handler();
	}

}
/* TIM17 init function */
void MX_TIM17_Init(void)
{

	htim17.Instance = TIM17;
	htim17.Init.Prescaler = 0;
	htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim17.Init.Period = 65535;
	htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim17.Init.RepetitionCounter = 0;
	htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
	{
		Error_Handler();
	}

}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* tim_pwmHandle)
{

	if(tim_pwmHandle->Instance == TIM2)
	{
		/* USER CODE BEGIN TIM2_MspInit 0 */

		/* USER CODE END TIM2_MspInit 0 */
		/* TIM2 clock enable */
		__HAL_RCC_TIM2_CLK_ENABLE();

		/* TIM2 interrupt Init */
		HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
		/* USER CODE BEGIN TIM2_MspInit 1 */

		/* USER CODE END TIM2_MspInit 1 */
	}
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

	if(tim_baseHandle->Instance == TIM6)
	{
		/* USER CODE BEGIN TIM6_MspInit 0 */

		/* USER CODE END TIM6_MspInit 0 */
		/* TIM6 clock enable */
		__HAL_RCC_TIM6_CLK_ENABLE();

		/* TIM6 interrupt Init */
		HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
		/* USER CODE BEGIN TIM6_MspInit 1 */

		/* USER CODE END TIM6_MspInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM7)
	{
		/* USER CODE BEGIN TIM7_MspInit 0 */

		/* USER CODE END TIM7_MspInit 0 */
		/* TIM7 clock enable */
		__HAL_RCC_TIM7_CLK_ENABLE();

		/* TIM7 interrupt Init */
		HAL_NVIC_SetPriority(TIM7_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM7_IRQn);
		/* USER CODE BEGIN TIM7_MspInit 1 */

		/* USER CODE END TIM7_MspInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM13)
	{
		/* USER CODE BEGIN TIM13_MspInit 0 */

		/* USER CODE END TIM13_MspInit 0 */
		/* TIM13 clock enable */
		__HAL_RCC_TIM13_CLK_ENABLE();

		/* TIM13 interrupt Init */
		HAL_NVIC_SetPriority(TIM8_UP_TIM13_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
		/* USER CODE BEGIN TIM13_MspInit 1 */

		/* USER CODE END TIM13_MspInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM14)
	{
		/* USER CODE BEGIN TIM14_MspInit 0 */

		/* USER CODE END TIM14_MspInit 0 */
		/* TIM14 clock enable */
		__HAL_RCC_TIM14_CLK_ENABLE();

		/* TIM14 interrupt Init */
		HAL_NVIC_SetPriority(TIM8_TRG_COM_TIM14_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
		/* USER CODE BEGIN TIM14_MspInit 1 */

		/* USER CODE END TIM14_MspInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM16)
	{
		/* USER CODE BEGIN TIM16_MspInit 0 */

		/* USER CODE END TIM16_MspInit 0 */
		/* TIM16 clock enable */
		__HAL_RCC_TIM16_CLK_ENABLE();

		/* TIM16 interrupt Init */
		HAL_NVIC_SetPriority(TIM16_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM16_IRQn);
		/* USER CODE BEGIN TIM16_MspInit 1 */

		/* USER CODE END TIM16_MspInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM17)
	{
		/* USER CODE BEGIN TIM17_MspInit 0 */

		/* USER CODE END TIM17_MspInit 0 */
		/* TIM17 clock enable */
		__HAL_RCC_TIM17_CLK_ENABLE();

		/* TIM17 interrupt Init */
		HAL_NVIC_SetPriority(TIM17_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM17_IRQn);
		/* USER CODE BEGIN TIM17_MspInit 1 */

		/* USER CODE END TIM17_MspInit 1 */
	}
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(timHandle->Instance == TIM2)
	{
		/* USER CODE BEGIN TIM2_MspPostInit 0 */

		/* USER CODE END TIM2_MspPostInit 0 */

		__HAL_RCC_GPIOA_CLK_ENABLE();
		/**TIM2 GPIO Configuration
		   PA0     ------> TIM2_CH1
		 */
		GPIO_InitStruct.Pin = DISP_PWM_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(DISP_PWM_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM2_MspPostInit 1 */

		/* USER CODE END TIM2_MspPostInit 1 */
	}

}

void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* tim_pwmHandle)
{

	if(tim_pwmHandle->Instance == TIM2)
	{
		/* USER CODE BEGIN TIM2_MspDeInit 0 */

		/* USER CODE END TIM2_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM2_CLK_DISABLE();

		/* TIM2 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM2_IRQn);
		/* USER CODE BEGIN TIM2_MspDeInit 1 */

		/* USER CODE END TIM2_MspDeInit 1 */
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

	if(tim_baseHandle->Instance == TIM6)
	{
		/* USER CODE BEGIN TIM6_MspDeInit 0 */

		/* USER CODE END TIM6_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM6_CLK_DISABLE();

		/* TIM6 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
		/* USER CODE BEGIN TIM6_MspDeInit 1 */

		/* USER CODE END TIM6_MspDeInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM7)
	{
		/* USER CODE BEGIN TIM7_MspDeInit 0 */

		/* USER CODE END TIM7_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM7_CLK_DISABLE();

		/* TIM7 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM7_IRQn);
		/* USER CODE BEGIN TIM7_MspDeInit 1 */

		/* USER CODE END TIM7_MspDeInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM13)
	{
		/* USER CODE BEGIN TIM13_MspDeInit 0 */

		/* USER CODE END TIM13_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM13_CLK_DISABLE();

		/* TIM13 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM8_UP_TIM13_IRQn);
		/* USER CODE BEGIN TIM13_MspDeInit 1 */

		/* USER CODE END TIM13_MspDeInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM14)
	{
		/* USER CODE BEGIN TIM14_MspDeInit 0 */

		/* USER CODE END TIM14_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM14_CLK_DISABLE();

		/* TIM14 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM8_TRG_COM_TIM14_IRQn);
		/* USER CODE BEGIN TIM14_MspDeInit 1 */

		/* USER CODE END TIM14_MspDeInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM16)
	{
		/* USER CODE BEGIN TIM16_MspDeInit 0 */

		/* USER CODE END TIM16_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM16_CLK_DISABLE();

		/* TIM16 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM16_IRQn);
		/* USER CODE BEGIN TIM16_MspDeInit 1 */

		/* USER CODE END TIM16_MspDeInit 1 */
	}
	else if(tim_baseHandle->Instance == TIM17)
	{
		/* USER CODE BEGIN TIM17_MspDeInit 0 */

		/* USER CODE END TIM17_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM17_CLK_DISABLE();

		/* TIM17 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM17_IRQn);
		/* USER CODE BEGIN TIM17_MspDeInit 1 */

		/* USER CODE END TIM17_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
