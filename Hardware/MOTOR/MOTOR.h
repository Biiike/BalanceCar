#ifndef __Motor_H
#define	__Motor_H

#include "ti_msp_dl_config.h"

void set_motor_pwm(int Compare1,int Compare2);
void ABS_pwm(int *Compare);
void pwm_limit(int *a,int max_value);
void set_motor1_pwm(int Compare);
void set_motor2_pwm(int Compare);

#endif