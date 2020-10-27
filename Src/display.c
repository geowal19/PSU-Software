#include "display.h"

void DISPLAY_Init()
{
	// Init the drivers
	LTDC_LayerCfgTypeDef pLayerCfg = {0};

	hltdc.Instance = LTDC;
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	hltdc.Init.HorizontalSync = 4;
	hltdc.Init.VerticalSync = 5;
	hltdc.Init.AccumulatedHBP = 50; //45
	hltdc.Init.AccumulatedVBP = 23;
	hltdc.Init.AccumulatedActiveW = 880; // 845
	hltdc.Init.AccumulatedActiveH = 504;
	hltdc.Init.TotalWidth = 896; // 865
	hltdc.Init.TotalHeigh = 550; // 550
	hltdc.Init.Backcolor.Blue = 0;
	hltdc.Init.Backcolor.Green = 0;
	hltdc.Init.Backcolor.Red = 0;
	if (HAL_LTDC_Init(&hltdc) != HAL_OK)
	{
		Error_Handler();
	}

	pLayerCfg.WindowX0 = 30;
	pLayerCfg.WindowX1 = 830;
	pLayerCfg.WindowY0 = 0;
	pLayerCfg.WindowY1 = 480;
	pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_L8;
	pLayerCfg.Alpha = 255;
	pLayerCfg.Alpha0 = 255;
	pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg.FBStartAdress = DISP_BUFFER;
	pLayerCfg.ImageWidth = 800;
	pLayerCfg.ImageHeight = 480;
	pLayerCfg.Backcolor.Blue = 0;
	pLayerCfg.Backcolor.Green = 0;
	pLayerCfg.Backcolor.Red = 0;
	if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
	{
		Error_Handler();
	}

	// Enable the display
	HAL_Delay(10);
	HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, 1);

	// Start the backlight (~10kHz output)
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 480;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 100; // Period in microseconds
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
	sConfigOC.Pulse = 0; // Start at 0% brightness
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}

	HAL_TIM_MspPostInit(&htim2);

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void DISPLAY_Refresh()
{
	HAL_LTDC_Reload(&hltdc, LTDC_RELOAD_VERTICAL_BLANKING);
}

void DISPLAY_SetBackLight(uint8_t percentage)
{
	if (percentage > 100)
		percentage = 100;

	htim2.Instance->CCR1 = (uint32_t)percentage;
}