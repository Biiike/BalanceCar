#include "User\FINDLINE.h"
#include "BUZ.h"
#include "ENCODER.h"
#include "USOUND.h"
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
int buz_flag = 0;
bool quan_flag=0;
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
        error+=800;
    if(get_middle1_status()==1)
       error+=600;
    if(get_middle2_status()==1)
        error-=600;
    if(get_right_status()==1)
        error-=800;
    if(state==0)
    {
        error =err0;
        err0 = error;
    }
    if(state ==111||state == 1110||state == 1010||state == 101)
    {
        error = -2000;
        turn_flag=1;
    }
    if(turn_flag&&(state == 1001||state == 1011||state == 1101))
    {
        turn_flag=0;
        quan_flag=1;
    }
    if(quan_flag&&(state == 111||state == 1110||state == 1010||state == 101)){
        error=0;
        quan_flag=0;
    }
    if (state == 1111) {
        velocity_calcu = 0;
        VKp = 340,VKi = 340/200;
        line_flag = 0;
        LED_ON(3);
        BUZ_ON();
        buz_flag = 1;
        
    }
}