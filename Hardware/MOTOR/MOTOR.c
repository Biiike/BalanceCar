#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "MOTOR.h"

void pwm_limit(int Target_PWM,int max_value)
{
    if(Target_PWM>max_value)Target_PWM=max_value;
    if(Target_PWM<-max_value)Target_PWM=-max_value;
}
void set_motor1_pwm(int Compare)
{
    pwm_limit(Compare,999);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_0_INDEX);
}
void set_motor2_pwm(int Compare)
{
    pwm_limit(Compare,999);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_1_INDEX);
}
void set_motor_pwm(int Compare1,int Compare2)
{
    if(Compare1>0)//左
    {//正转
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN);                   
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
    }
    else if(Compare1<0)
    {//反转
        Compare1=-Compare1;
		DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN );                   
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
    }
    else
    {//停车
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN );
    }
    Compare1=-Compare1+999;
    set_motor1_pwm(Compare1);
    if(Compare2>0)//右
    {//正转
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN);                   
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
    }
    else if(Compare2<0)
    {//反转
        Compare2=-Compare2;
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN);                   
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
    }
    else 
    {//停车
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN);
    }
    Compare2=-Compare2+999;
    set_motor2_pwm(Compare2);
}


