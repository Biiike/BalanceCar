#ifndef _FINDLINE_H_
#define _FINDLINE_H_

#include "ti_msp_dl_config.h"
#define STATUS_SIZE 4
#define TURN_Limit  30 //转向增长限制
#define BASE        300
#define SMALL       150
#define MIDDlE      200
#define BIG         250
void Line_Following();

enum{
    Straight=0,
    Turn_right,
    Turn_right_middle,
    Turn_right_big,
    Turn_left,
    Turn_left_middle,
    Turn_left_big
};

#endif