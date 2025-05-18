#include "User\FINDLINE.h"
#include "stdio.h"
#include "MOTOR.h"
#include "CONTROL.h"
#include <stdbool.h>
#include "LED.h"
float a=0.3;
int speed_left;
int speed_right;
int32_t state;
float error,err0;
bool turn_flag=0;
//读取状态
uint8_t get_right_status()
{
    return !DL_GPIO_readPins(Line_PORT,Line_Right_PIN);
}

uint8_t get_middle1_status()
{
    return !DL_GPIO_readPins(Line_PORT,Line_Middle1_PIN);
}

uint8_t get_middle2_status()
{
    return !DL_GPIO_readPins(Line_PORT,Line_Middle2_PIN);
}

uint8_t get_left_status()
{
    return !DL_GPIO_readPins(Line_PORT,Line_Left_PIN);
}

void Line_Following()
{
    state=0;
    if(get_left_status()==1)
        state+=1000;
    if(get_middle1_status()==1)
        state+=100;
    if(get_middle2_status()==1)
        state+=10;
    if(get_right_status()==1)
        state+=1;

    error=0;
    if(get_left_status()==1)
        error+=700;
    if(get_middle1_status()==1)
       error+=500;
    if(get_middle2_status()==1)
        error-=500;
    if(get_right_status()==1)
        error-=700;
    if(state==0)
    {
        error =err0;
        err0 = error;
    }
    if(state ==111)
    {
        error = -2000;
    }
}