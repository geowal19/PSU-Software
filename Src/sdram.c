#include "sdram.h"

void SDRAM_Init()
{
	FMC_SDRAM_CommandTypeDef Command;

	// Step 1:  Configure a clock configuration enable command
	Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

	// Step 2: Insert 100 us minimum delay
	HAL_Delay(1);

	// Step 3: Configure a PALL (precharge all) command
	Command.CommandMode = FMC_SDRAM_CMD_PALL;
	Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

	// Step 4 : Configure a Auto-Refresh command
	Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
	Command.AutoRefreshNumber = 8;
	Command.ModeRegisterDefinition = 0;
	HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

	// Step 5: Program the external memory mode register
	uint32_t tmpmrd = (uint32_t)(
		SDRAM_MODEREG_BURST_LENGTH_1            |
		SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL     |
		SDRAM_MODEREG_CAS_LATENCY_3             |
		SDRAM_MODEREG_OPERATING_MODE_STANDARD   |
		SDRAM_MODEREG_WRITEBURST_MODE_SINGLE);

	Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = tmpmrd;
	HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

	// Step 6: Set the refresh rate counter
	HAL_SDRAM_ProgramRefreshRate(&hsdram1, REFRESH_COUNT);
}

void SDRAM_Write(uint32_t loc, uint32_t * data, uint32_t n_words)
{
	uint32_t * addr = (uint32_t*)(SDRAM_BANK_ADDR + loc);

	// Copy in units of bytes
	memcpy((uint8_t*)addr, (uint8_t*)data, n_words * sizeof(uint32_t));
}

void SDRAM_Read(uint32_t loc, uint32_t * data, uint32_t n_words)
{
	uint32_t * addr = (uint32_t*)(SDRAM_BANK_ADDR + loc);

	// Copy in units of bytes
	memcpy((uint8_t*)data, (uint8_t*)addr, n_words * sizeof(uint32_t));
}