#ifndef _FINDLINE_H_
#define _FINDLINE_H_

#include "ti_msp_dl_config.h"
extern int speed_left;
extern int speed_right;
extern int speed;
extern int32_t state;
extern float error,err0;
void Line_Following();
#endif