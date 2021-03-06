#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

#define CMD_PREAMBLE "psu"
#define CMD_SET_VLTS_STR "set_voltage"
#define CMD_SET_AMPS_STR "set_current"
#define CMD_GET_VLTS_STR "get_voltage"
#define CMD_GET_AMPS_STR "get_current"
#define CMD_GET_OUT_STATE_STR "get_output_state"
#define CMD_SET_OUT_STATE_STR "set_output_state"
#define CMD_SET_BRIGHTNESS_STR "set_brightness"
#define CMD_SET_STREAM_STR "set_stream_mode"

enum
{
    CMD_NOP,
    CMD_SET_VLTS,
    CMD_SET_AMPS,
    CMD_GET_VLTS,
    CMD_GET_AMPS,
    CMD_GET_OUT_STATE,
    CMD_SET_OUT_STATE,
    CMD_SET_BRIGHTNESS,
    CMD_SET_STREAM
};

// A container for commands
struct CMDContainerTag;
typedef struct CMDContainerTag
{
    uint8_t cmd;
    char params[7][32];
    uint8_t n_params;
} CMDContainer;

CMDContainer CMD_Parser(char *str);

#endif