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

    // Get the command type
    if(!strcmp(command, CMD_SET_VLTS_STR)) cmd.cmd = CMD_SET_VLTS;
    if(!strcmp(command, CMD_SET_AMPS_STR)) cmd.cmd = CMD_SET_AMPS;


    // All done
    return cmd;
}
