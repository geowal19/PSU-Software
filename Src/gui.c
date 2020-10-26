#include "gui.h"

#include "font.h"

const uint8_t *font_chars[] = {char_0, char_1, char_2, char_3, char_4, char_5, char_6, char_7, char_8, char_9, char_dp};
const uint32_t font_char_widths[] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 27};
void GUI_Init()
{
    //SDRAM_Write(0, (uint32_t *)background, 800 * 480);
}

void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char *user_input)
{
    char str[10];
    uint32_t offset = 0;

    // Draw the output voltage
    sprintf(str, "%f", output_voltage);
    offset = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        GUI_DrawChar(GUI_OUTPUT_VLTS_LOC_X, GUI_OUTPUT_VLTS_LOC_Y + offset, str[i]);
        offset += GUI_CHAR_SPACING + font_char_widths[str[i] - GUI_ASCII_OFFSET];
    }

    // Draw the output current
    sprintf(str, "%f", output_current);
    offset = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        GUI_DrawChar(GUI_OUTPUT_AMPS_LOC_X, GUI_OUTPUT_AMPS_LOC_Y + offset, str[i]);
        offset += GUI_CHAR_SPACING + font_char_widths[str[i] - GUI_ASCII_OFFSET];
    }

    // Draw the read voltage
    sprintf(str, "%f", read_voltage);
    offset = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        GUI_DrawChar(GUI_READ_VLTS_LOC_X, GUI_READ_VLTS_LOC_Y + offset, str[i]);
        offset += GUI_CHAR_SPACING + font_char_widths[str[i] - GUI_ASCII_OFFSET];
    }

    // Draw the read current
    sprintf(str, "%f", read_current);
    offset = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        GUI_DrawChar(GUI_READ_AMPS_LOC_X, GUI_READ_AMPS_LOC_Y + offset, str[i]);
        offset += GUI_CHAR_SPACING + font_char_widths[str[i] - GUI_ASCII_OFFSET];
    }

    // Draw the output voltage
    offset = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        GUI_DrawChar(GUI_USER_INPUT_LOC_X, GUI_USER_INPUT_LOC_Y + offset, user_input[i]);
        offset += GUI_CHAR_SPACING + font_char_widths[user_input[i] - GUI_ASCII_OFFSET];
    }
}

void GUI_DrawChar(uint32_t x, uint32_t y, char c)
{
    uint32_t disp_mem_loc = (y * 800) + x;
    uint32_t width = font_char_widths[c - GUI_ASCII_OFFSET];

    for (uint32_t i = 0; i < FONT_CHAR_HEIGHT; i++)
    {
        SDRAM_Write(disp_mem_loc + (i * 800), (uint32_t *)(font_chars[c - GUI_ASCII_OFFSET]) + (i * width), width);
    }
}
