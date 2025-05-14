#ifndef __CONTROL_H_
#define __CONTROL_H_

int vertical_PID_value(float measure,float calcu); //直立环
int velocity_PID_value(int velocity);              //速度环
void I_xianfu(int max);                            //pwm限幅

#endif