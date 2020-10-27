#include "gui.h"

#include "font.h"
#include "display.h"
#include "background.h"

const uint8_t *font_chars[] = {char_0, char_1, char_2, char_3, char_4, char_5, char_6, char_7, char_8, char_9, char_dp, char_on, char_off};
const uint32_t font_char_widths[] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 27, 190, 190};
void GUI_Init()
{
    //memcpy((uint8_t *)DISPLAY_GetBuffer(), (uint8_t *)background, 800 * 480);

    memcpy((uint8_t *)DISP_BUFFER, (uint8_t *)background, 800 * 480);
    //memset(DISP_BUFFER, 80, 800 * 480);
}

void GUI_UpdateDisplay(double output_voltage, double output_current, double read_voltage, double read_current, bool output_en, char *user_input)
{
    char str[10] = {0};

    /*

        Set voltage

    */

    sprintf(str, "%.3f", output_voltage);
    // Make sure it's only 5 chars
    str[5] = 0;
    // Draw the string
    GUI_DrawString(GUI_OUTPUT_VLTS_LOC_X, GUI_OUTPUT_VLTS_LOC_Y, str);

    /*

        Set current

    */

    sprintf(str, "%.3f", output_current);
    // Make sure it's only 5 chars
    str[5] = 0;
    // Draw the string
    GUI_DrawString(GUI_OUTPUT_AMPS_LOC_X, GUI_OUTPUT_AMPS_LOC_Y, str);

    /*

        Read voltage

    */

    sprintf(str, "%.3f", read_voltage);
    // Make sure it's only 5 chars
    str[5] = 0;
    // Draw the string
    GUI_DrawString(GUI_READ_VLTS_LOC_X, GUI_READ_VLTS_LOC_Y, str);

    /*

        Read current

    */

    sprintf(str, "%.3f", read_current);
    // Make sure it's only 5 chars
    str[5] = 0;
    // Draw the string
    GUI_DrawString(GUI_READ_AMPS_LOC_X, GUI_READ_AMPS_LOC_Y, str);

    /*

        USER INPUT

    */

    // Check the length
    if (strlen(user_input) > GUI_USER_INPUT_MAX_LEN)
    {
        user_input[GUI_USER_INPUT_MAX_LEN] = 0;
    }

    if (strlen(user_input))
    {
        // Draw the user input string
        GUI_DrawString(GUI_USER_INPUT_LOC_X, GUI_USER_INPUT_LOC_Y, user_input);
    }

    else
    {
        // Draw blanking first
        GUI_DrawRectangle(GUI_USER_INPUT_LOC_X, GUI_USER_INPUT_LOC_Y, GUI_USER_INPUT_LOC_X + (GUI_USER_INPUT_MAX_LEN * font_char_widths[0]), GUI_USER_INPUT_LOC_Y + GUI_ASCII_HEIGHT, 0);
    }

    /*

        OUTPUT STATE

    */

    // Check the length
    if (output_en)
    {
        // Draw the user input string
        GUI_DrawChar(GUI_OUTPUT_STATE_LOC_X, GUI_OUTPUT_STATE_LOC_Y, 'n');
    }

    else
    {
        // Draw the user input string
        GUI_DrawChar(GUI_OUTPUT_STATE_LOC_X, GUI_OUTPUT_STATE_LOC_Y, 'f');
    }
}

uint32_t GUI_DrawChar(uint32_t x, uint32_t y, char c)
{
    uint8_t *ptr = NULL;
    uint32_t width = 0;

    if (c == '.')
    {
        ptr = (uint8_t *)font_chars[10];
        width = font_char_widths[10];
    }

    else if (c == 'n')
    {
        ptr = (uint8_t *)font_chars[11];
        width = font_char_widths[11];
    }

    else if (c == 'f')
    {
        ptr = (uint8_t *)font_chars[12];
        width = font_char_widths[12];
    }

    else
    {
        // Character is out of range
        if ((c - GUI_ASCII_OFFSET) > 10)
        {
            return 0;
        }

        ptr = (uint8_t *)font_chars[c - GUI_ASCII_OFFSET];
        width = font_char_widths[c - GUI_ASCII_OFFSET];
    }

    for (uint32_t i = 0; i < GUI_ASCII_HEIGHT; i++)
    {
        uint8_t *disp_ptr = (uint8_t *)(DISP_BUFFER + ((i + y) * GUI_SCREEN_WIDTH) + x);
        memcpy((uint8_t *)disp_ptr, &ptr[width * i], width);
    }

    return width;
}

uint32_t GUI_DrawString(uint32_t x, uint32_t y, char *str)
{
    uint32_t x_ptr = x;

    for (uint8_t i = 0; i < strlen(str); i++)
    {
        x_ptr += GUI_ASCII_SPACING + GUI_DrawChar(x_ptr, y, str[i]);
    }

    return x_ptr;
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
