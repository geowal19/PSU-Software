#ifndef __BTN_H__
#define __BTN_H__

#include "main.h"

#include "gpio.h"

#define BTN_N_BUTTONS   16

#define BTN_0_BIT       0x00000001
#define BTN_1_BIT       0x00000002
#define BTN_2_BIT       0x00000004
#define BTN_3_BIT       0x00000008
#define BTN_4_BIT       0x00000010
#define BTN_5_BIT       0x00000020
#define BTN_6_BIT       0x00000040
#define BTN_7_BIT       0x00000080
#define BTN_8_BIT       0x00000100
#define BTN_9_BIT       0x00000200
#define BTN_CLR_BIT     0x00000400
#define BTN_DP_BIT      0x00000800
#define BTN_V_BIT       0x00001000
#define BTN_A_BIT       0x00002000
#define BTN_SHIFT_BIT   0x00004000
#define BTN_ONOFF_BIT   0x00008000

enum {BTN_0, BTN_1, BTN_2, BTN_3, BTN_4, BTN_5, BTN_6, BTN_7, BTN_8, BTN_9, BTN_CLR, BTN_DP, BTN_V, BTN_A, BTN_SHIFT, BTN_ONOFF};

void BTN_Poll();
bool BTN_ReadButton(uint8_t button);
void BTN_CallBack(uint32_t button_flags);

#endif