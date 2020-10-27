#ifndef __GUI_H__
#define __GUI_H__

#include "main.h"

#include "display.h"

#define GUI_ASCII_OFFSET 48
#define GUI_ASCII_HEIGHT 90

#define GUI_OUTPUT_VLTS_LOC_X 3
#define GUI_OUTPUT_VLTS_LOC_Y 3

#define GUI_OUTPUT_AMPS_LOC_X 3
#define GUI_OUTPUT_AMPS_LOC_Y 3

#define GUI_READ_VLTS_LOC_X 3
#define GUI_READ_VLTS_LOC_Y 3

#define GUI_READ_AMPS_LOC_X 3
#define GUI_READ_AMPS_LOC_Y 3

#define GUI_USER_INPUT_LOC_X 3
#define GUI_USER_INPUT_LOC_Y 3

#define GUI_CHAR_SPACING 3

#define GUI_SCREEN_WIDTH 800
#define GUI_SCREEN_HEIGHT 480

void GUI_Init();
void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char *user_input);
void GUI_DrawChar(uint32_t x, uint32_t y, char c);
void GUI_DrawRectangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t pix_val);

#endif