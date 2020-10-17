#ifndef __GUI_H__
#define __GUI_H__

#include "main.h"

#include "display.h"

#define GUI_ASCII_OFFSET            32

#define GUI_OUTPUT_VLTS_LOC_X       3
#define GUI_OUTPUT_VLTS_LOC_Y       3

#define GUI_OUTPUT_AMPS_LOC_X       3
#define GUI_OUTPUT_AMPS_LOC_Y       3

#define GUI_READ_VLTS_LOC_X         3
#define GUI_READ_VLTS_LOC_Y         3

#define GUI_READ_AMPS_LOC_X         3
#define GUI_READ_AMPS_LOC_Y         3

#define GUI_USER_INPUT_LOC_X        3
#define GUI_USER_INPUT_LOC_Y        3

#define GUI_CHAR_SPACING            3

void GUI_Init();
void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char * user_input);
void GUI_DrawChar(uint32_t x, uint32_t y, char c);

#endif