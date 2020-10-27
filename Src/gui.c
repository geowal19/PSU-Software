#include "gui.h"

#include "font.h"
#include "display.h"
#include "background.h"

const uint8_t *font_chars[] = {char_0, char_1, char_2, char_3, char_4, char_5, char_6, char_7, char_8, char_9, char_dp};
const uint32_t font_char_widths[] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 27};
void GUI_Init()
{
    //memcpy((uint8_t *)DISPLAY_GetBuffer(), (uint8_t *)background, 800 * 480);

    memcpy((uint8_t *)DISP_BUFFER, (uint8_t *)background, 800 * 480);
    //memset(DISP_BUFFER, 80, 800 * 480);
}

void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char *user_input)
{
}

void GUI_DrawChar(uint32_t x, uint32_t y, char c)
{
    uint8_t *ptr = NULL;
    uint32_t width = 0;

    if (c == '.')
    {
        ptr = (uint8_t *)font_chars[10];
        width = font_char_widths[10];
    }

    else
    {
        // Character is out of range
        if ((c - GUI_ASCII_OFFSET) > 10)
        {
            return;
        }

        ptr = (uint8_t *)font_chars[c - GUI_ASCII_OFFSET];
        width = font_char_widths[c - GUI_ASCII_OFFSET];
    }

    for (uint32_t i = 0; i < GUI_ASCII_HEIGHT; i++)
    {
        uint8_t *disp_ptr = (uint8_t *)(DISP_BUFFER + ((i + y) * GUI_SCREEN_WIDTH) + x);
        memcpy((uint8_t *)disp_ptr, &ptr[width * i], width);
    }
}

void GUI_DrawRectangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t pix_val)
{
    uint32_t width = x1 - x0;
    uint32_t height = y1 - y0;

    // Are we in range?
    if (width > (GUI_SCREEN_WIDTH - x0))
        return;
    if (height > (GUI_SCREEN_HEIGHT - y0))
        return;

    for (uint32_t i = y0; i < y1; i++)
    {
        uint8_t *ptr = (uint8_t *)(DISP_BUFFER + (i * GUI_SCREEN_WIDTH) + x0);

        memset((uint8_t *)ptr, pix_val, width);
    }
}
