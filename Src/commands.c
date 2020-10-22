#include "commands.h"

CMDContainer CMD_Parser(char * str)
{
    CMDContainer cmd = {0};
    cmd.cmd = CMD_NOP;
    char * start = strstr(str, CMD_PREAMBLE);

    // No preamble found
    if(!start)
    {
        return cmd;
    }

    // Increment to a space
    do
    {
        start++;
    } while(start != NULL && *start != ' ');

    // Check for error
    if(!start)
    {
        return cmd;
    }

    // Decode the params and the cmd
    char command[32] = {0};
    sscanf(start, "%s %s %s %s %s %s %s %s", 
        command, cmd.params[0], cmd.params[1], cmd.params[2], 
        cmd.params[3], cmd.params[4], cmd.params[5], cmd.params[6]);

    // Count the number of parameters
    for(uint8_t i = 0; i < 7; i++)
    {
        if(strlen(cmd.params[i]) == 0)
        {
            cmd.n_params = i;
            break;
        }
    }

    // Get the command type
    if(!strcmp(command, CMD_SET_VLTS_STR)) cmd.cmd = CMD_SET_VLTS;
    if(!strcmp(command, CMD_SET_AMPS_STR)) cmd.cmd = CMD_SET_AMPS;
    if(!strcmp(command, CMD_GET_VLTS_STR)) cmd.cmd = CMD_GET_VLTS;
    if(!strcmp(command, CMD_GET_AMPS_STR)) cmd.cmd = CMD_GET_AMPS;
    if(!strcmp(command, CMD_GET_OUT_STATE_STR)) cmd.cmd = CMD_GET_OUT_STATE;
    if(!strcmp(command, CMD_SET_OUT_STATE_STR)) cmd.cmd = CMD_SET_OUT_STATE;
    if(!strcmp(command, CMD_SET_BRIGHTNESS_STR)) cmd.cmd = CMD_SET_BRIGHTNESS;

    // All done
    return cmd;
}
