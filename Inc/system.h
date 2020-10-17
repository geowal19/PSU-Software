#ifndef __SYS_H__
#define __SYS_H__

#include "main.h"

#define SYS_BTN_POLL_TIME_MS        10      // Button poll rate
#define SYS_ANA_POLL_TIME_MS        100     // Analogue output values rate
#define SYS_DSP_POLL_TIME_MS        100     // Display refresh rate

#define SYS_MAX_VOLTAGE             (10.000)
#define SYS_MIN_VOLTAGE             (00.000)
#define SYS_MAX_CURRENT             (1.000)
#define SYS_MIN_CURRENT             (0.000)

#define SYS_USER_INPUT_LEN          10


// The system variable
struct SysVarTag;
typedef struct SysVarTag
{
    double output_voltage;
    double output_current;
    double read_voltage;
    double read_current;
    bool output_en;
    char user_input[SYS_USER_INPUT_LEN];
    uint8_t display_brightness;
} SysVar;

// Core functions
void System();
void SYS_Start();
void SYS_Loop();

// Helper functions
void SYS_CommandExecuter();
void SYS_ButtonHandler(uint32_t button_press);

#endif