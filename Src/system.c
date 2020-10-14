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

}

void SYS_Loop()
{

}