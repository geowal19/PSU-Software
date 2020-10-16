#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

#define CMD_PREAMBLE            "psu"
#define CMD_SET_VLTS_STR        "set_voltage"
#define CMD_SET_AMPS_STR        "set_current"

enum {CMD_NOP, CMD_SET_VLTS, CMD_SET_AMPS};

// A container for commands
struct CMDContainerTag;
typedef struct CMDContainerTag
{
    uint8_t cmd;
    char params[7][32];
} CMDContainer;

CMDContainer CMD_Parser(char * str);

#endif