#ifndef __DAC_H__
#define __DAC_H__

#include "main.h"

#include "i2c.h"

enum {DAC_VLTS, DAC_AMPS};

#define DAC_VLTS_I2C_ADDR   0x91
#define DAC_AMPS_I2C_ADDR   0x90

#define DAC_CMD_NOOP        0x00
#define DAC_CMD_DVID        0x01
#define DAC_CMD_SYNC        0x02
#define DAC_CMD_CONF        0x03
#define DAC_CMD_GAIN        0x04
#define DAC_CMD_TRIG        0x05
#define DAC_CMD_STAT        0x07
#define DAC_CMD_DATA        0x08

void DAC_Start();
void DAC_SetValue(uint8_t device, uint16_t value);

#endif



