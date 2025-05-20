#ifndef _FINDLINE_H_
#define _FINDLINE_H_

#include "FINDLINE.h"
#include "ti_msp_dl_config.h"
extern int speed_left;
extern int speed_right;
extern int speed;
extern int32_t state;
extern float error,err0;
extern int jin_flag_count;
extern int jin_flag_count2;
extern int jin_flag;
void Line_Following();
extern int new_round;
#endif