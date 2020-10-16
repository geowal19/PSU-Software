#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

#define CMD_PREAMBLE            "psu"
#define CMD_SET_VOLTS_STR       "set_voltage"

enum {CMD_NOP, CMD_SET_VOLTS};

// A container for commands
struct CMDContainerTag;
typedef struct CMDContainerTag
{
    uint8_t cmd;
    char params[7][32];
} CMDContainer;

CMDContainer CMD_Parser(char * str);

#endif