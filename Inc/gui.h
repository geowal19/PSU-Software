#ifndef __GUI_H__
#define __GUI_H__

#include "main.h"

#include "display.h"

#define GUI_ASCII_OFFSET 48
#define GUI_ASCII_HEIGHT 90
#define GUI_ASCII_SPACING 0

#define GUI_VSPACING (147)

#define GUI_OUTPUT_VLTS_LOC_X 15
#define GUI_OUTPUT_VLTS_LOC_Y 71

#define GUI_OUTPUT_AMPS_LOC_X GUI_OUTPUT_VLTS_LOC_X
#define GUI_OUTPUT_AMPS_LOC_Y (GUI_OUTPUT_VLTS_LOC_Y + GUI_VSPACING)

#define GUI_READ_VLTS_LOC_X 414
#define GUI_READ_VLTS_LOC_Y GUI_OUTPUT_VLTS_LOC_Y

#define GUI_READ_AMPS_LOC_X GUI_READ_VLTS_LOC_X
#define GUI_READ_AMPS_LOC_Y GUI_OUTPUT_AMPS_LOC_Y

#define GUI_USER_INPUT_LOC_X GUI_OUTPUT_VLTS_LOC_X
#define GUI_USER_INPUT_LOC_Y (GUI_OUTPUT_AMPS_LOC_Y + GUI_VSPACING)
#define GUI_USER_INPUT_MAX_LEN 5

#define GUI_OUTPUT_STATE_LOC_X GUI_READ_VLTS_LOC_X
#define GUI_OUTPUT_STATE_LOC_Y (GUI_OUTPUT_AMPS_LOC_Y + GUI_VSPACING)

#define GUI_SCREEN_WIDTH 800
#define GUI_SCREEN_HEIGHT 480

void GUI_Init();
void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char *user_input);
uint32_t GUI_DrawChar(uint32_t x, uint32_t y, char c);
uint32_t GUI_DrawString(uint32_t x, uint32_t y, char *str);
void GUI_DrawRectangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t pix_val);

#endif