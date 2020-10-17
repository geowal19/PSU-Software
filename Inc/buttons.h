#ifndef __BTN_H__
#define __BTN_H__

#include "main.h"

#include "gpio.h"

#define BTN_N_BUTTONS   16

// Primary button functions
#define BTN_0_FLAG          0x00000001
#define BTN_1_FLAG          0x00000002
#define BTN_2_FLAG          0x00000004
#define BTN_3_FLAG          0x00000008
#define BTN_4_FLAG          0x00000010
#define BTN_5_FLAG          0x00000020
#define BTN_6_FLAG          0x00000040
#define BTN_7_FLAG          0x00000080
#define BTN_8_FLAG          0x00000100
#define BTN_9_FLAG          0x00000200
#define BTN_CLR_FLAG        0x00000400
#define BTN_DP_FLAG         0x00000800
#define BTN_V_FLAG          0x00001000
#define BTN_A_FLAG          0x00002000
#define BTN_SHIFT_FLAG      0x00004000
#define BTN_ONOFF_FLAG      0x00008000

// Secondary functions (using shift)
#define BTN_S_0_FLAG        0x00010000
#define BTN_S_1_FLAG        0x00020000
#define BTN_S_2_FLAG        0x00040000
#define BTN_S_3_FLAG        0x00080000
#define BTN_S_4_FLAG        0x00100000
#define BTN_S_5_FLAG        0x00200000
#define BTN_S_6_FLAG        0x00400000
#define BTN_S_7_FLAG        0x00800000
#define BTN_S_8_FLAG        0x01000000
#define BTN_S_9_FLAG        0x02000000
#define BTN_S_CLR_FLAG      0x04000000
#define BTN_S_DP_FLAG       0x08000000
#define BTN_S_V_FLAG        0x10000000
#define BTN_S_A_FLAG        0x20000000
#define BTN_S_SHIFT_FLAG    0x40000000
#define BTN_S_ONOFF_FLAG    0x80000000

enum {BTN_0, BTN_1, BTN_2, BTN_3, BTN_4, BTN_5, BTN_6, BTN_7, BTN_8, BTN_9, BTN_CLR, BTN_DP, BTN_V, BTN_A, BTN_SHIFT, BTN_ONOFF};

void BTN_Poll();
bool BTN_ReadButton(uint8_t button);
void BTN_CallBack(uint32_t button_flags);

#endif