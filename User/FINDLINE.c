#include "User\FINDLINE.h"
#include "BUZ.h"
#include "DELAY.h"
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
int jin_flag_count;
int jin_flag_count2;
int jin_flag = 0;

int new_round = 0;

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
        {
         error+=800;
  
        }
    if(get_middle1_status()==1)
    {
         error+=500;
    }
      
    if(get_middle2_status()==1)
    {
        error-=500;
    }
        
    if(get_right_status()==1)
        error-=800;

    if(state==0)
    {
        error =err0;
        err0 = error;
    }
    if(jin_flag_count < 4500)
    {
        LED_ON(3);
        if(state ==111||state == 1110||state == 1010||state == 101||state == 1001||state==1101)
        {
            error = -1800;
        }    
    }
    else 
    {
        LED_OFF(3);
    
    }

    if(jin_flag_count2 < 6000)
    {
        LED_ON(1);
        if(turn_flag&&(state ==111||state == 1110||state == 1010||state == 101||state == 1001||state==1101||state==11))
        {
            error = -6000;
            delay_us(900);
            if(turn_flag){
                error =-4000;
                delay_us(700);
                turn_flag=0;
            }
        }    
    }
    else 
    {
        LED_OFF(1);
    
    }
    if(jin_flag_count2>4000){
        turn_flag=1;
    }
    if (state == 1111) {
        velocity_calcu = 0;
        VKp = 300,VKi = 300/200;
        line_flag = 0;
        line_flag2 =0;
        BUZ_ON();
        buz_flag = 1;
        jin_flag = 0;//
        
    }
}