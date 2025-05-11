#include "User\FINDLINE.h"
#include "stdio.h"
#include "MOTOR.h"
static uint8_t status[STATUS_SIZE];
static uint8_t last_area=Straight,area=Straight;//默认直行
static int current_left = BASE;
static int current_right = BASE;
float a=0.3;
//读取状态
uint8_t get_right_status()
{
    return DL_GPIO_readPins(Line_PORT,Line_Right_PIN);
}

uint8_t get_middle1_status()
{
    return DL_GPIO_readPins(Line_PORT,Line_Middle1_PIN);
}

uint8_t get_middle2_status()
{
    return DL_GPIO_readPins(Line_PORT,Line_Middle2_PIN);
}

uint8_t get_left_status()
{
    return DL_GPIO_readPins(Line_PORT,Line_Left_PIN);
}
//循迹逻辑
void Line_Following()
{
    status[0]=get_right_status();
    status[1]=get_middle1_status();
    status[2]=get_middle2_status();
    status[3]=get_left_status();
    int left_speed=BASE;
    int right_speed=BASE;
    if(status[0]&&!status[1]&&!status[2]&&status[3])//直行
    {
        area = Straight;
    }
    else if(status[0]&&status[1]&&!status[2]&&status[3])//小右转
    {
        area = Turn_right;
        left_speed += SMALL;
        right_speed -= SMALL;
    }
    else if(status[0]&&status[1]&&status[2]&&!status[3])//大右转
    {
        area = Turn_right_big;
        left_speed += BIG;
        right_speed -= BIG;
    }
    else if(status[0]&&!status[1]&&status[2]&&status[3])//小左转
    {
        area = Turn_left;
        left_speed -= SMALL;
        right_speed += SMALL;
    }
    else if(!status[0]&&status[1]&&status[2]&&status[3])//大左转
    {
        area = Turn_left_big;
        left_speed -= BIG;
        right_speed += BIG;
    }
    else if(status[0]&&status[1]&&status[2]&&status[3])//中左右转
    {
        if(last_area == Turn_right)//中右转
        {
            area = Turn_right_middle;
            left_speed += MIDDlE;
            right_speed += MIDDlE;
        }
        else if(last_area == Turn_left)//中左转
        {
            area = Turn_left_middle;
            left_speed -= MIDDlE;
            right_speed += MIDDlE;
        }
    }
    //一阶滤波
    float filtered_left = a * left_speed + (1-a) * current_left;
    float filtered_right = a * right_speed + (1-a) * current_right;
    //误差计算
    int limit_left = (int)filtered_left-current_left;
    int limit_right = (int)filtered_right-current_right;
    //限幅增量
    current_left += (limit_left>TURN_Limit)?TURN_Limit:(limit_left<-TURN_Limit)?-TURN_Limit:limit_left;
    current_right += (limit_right>TURN_Limit)?TURN_Limit:(limit_right<-TURN_Limit)?-TURN_Limit:limit_right;
    
    last_area = area;
    set_motor_pwm(current_left, limit_right);
}
