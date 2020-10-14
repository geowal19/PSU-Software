#include "system.h"

#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "ltdc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

#include "adc.h"
#include "analogue.h"
#include "buttons.h"
#include "dac.h"
#include "gui.h"
#include "sdram.h"
#include "terminal.h"

void System()
{
    SYS_Start();

    while(1)
    {
        SYS_Loop();
    }
}

void SYS_Start()
{
    TERM_Log("SYS_Start: System starting.\n");
}

void SYS_Loop()
{

}