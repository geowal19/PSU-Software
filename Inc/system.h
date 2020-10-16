#ifndef __SYS_H__
#define __SYS_H__

#include "main.h"

// The system variable
struct SysVarTag;
typedef struct SysVarTag
{
    double output_voltage;
    double output_current;
    double read_voltage;
    double read_current;
} SysVar;

#define SYS_BTN_POLL_TIME_MS        10
#define SYS_ANA_POLL_TIME_MS        100

void System();
void SYS_Start();
void SYS_Loop();

#endif