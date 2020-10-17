#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "main.h"

#include "ltdc.h"
#include "tim.h"

#include "sdram.h"

void DISPLAY_Init();
void DISPLAY_Refresh();
void DISPLAY_SetBackLight(uint8_t percentage);

#endif