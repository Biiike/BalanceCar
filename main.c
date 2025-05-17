#include "DELAY.h"
#include "KEY.h"
#include "LED.h"
#include "ti_msp_dl_config.h"
#include "BUZ.h"
#include "SHOW.h" 
#include <stdbool.h>
#include "OPENMV.h"
#include "USOUND.h"
#include "bsp_mpu6050.h"
#include "MOTOR.h"
#include "oled.h"
#include "ENCODER.h"
#include "CONTROL.h"
#include "FINDLINE.h"
bool need_clear_display;
float pitch, roll, yaw;//欧拉角
short acc[3];//加速度
int32_t state;
float measure=0;//角度测量值
int32_t state;
int velocity_measure=0;//速度测量值
int PWM;
int PWM_left;
int PWM_right;
float zhongzhi = -8;
//*****PID设置*****//
float angle_calcu;//希望小车平衡时的角度(pitch角)
float velocity_calcu=1;//希望小车前进速度(这里填的应该是编码器数值，如果填20那就是oled显示20编码器为20时的小车速度)

float Kp = 280*0.6,Ki = 1,Kd =2400*0.6;//直立环

float VKp = 320 ,VKi = 320/200;//速度环

float TKp=0, TKi=0, TKd=0;

// float Kp = 45*0.6,Ki = 0,Kd =350*0.6 ;//直立环
// float VKp = 53 ,VKi = 53/200;//速度环

//这两组都还行
// float Kp = 40*0.7,Ki = 0,Kd =400*0.7 ;//直立环
// float VKp = 45 ,VKi = 45/200;//速度环
//****************//

int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    encoder_init();//编码器初始化
    USOUND_Init();//开启超声波读取中断和定时中断
    MPU6050_Init();//mpu初始化
    mpu_dmp_init();//dmp初始化
    //OPENMV_Init();//开启OPENMV串口中断
    MPU6050_IRQINIT();//读取中断初始化 必须放在所有初始化的最后

    while (1) 
    {
        Line_Following();
        if(caiji_flag)//5ms读一次欧拉角
        {
            if(mpu_dmp_get_data(&pitch, &roll, &yaw) == 0)
            {
                measure = pitch;   //roll测量值
                angle_calcu = zhongzhi;
            }
            encoder_update();
            cnt[0] = get_encoder_cnt1();
            cnt[1] = get_encoder_cnt2();
            encoder_Rst();
            velocity_measure = (cnt[0] + cnt[1] )/2; //速度测量值
            PWM = vertical_PID_value(measure, angle_calcu) + velocity_PID_value(velocity_measure,velocity_calcu);
            PWM_left  =PWM-error;
            PWM_right =PWM+error;

            int dead_pwm = (PWM>0)?150:(PWM<0)?-150:0;
            set_motor_pwm(PWM_left+dead_pwm,PWM_right+dead_pwm);
             
        }
        if(need_clear_display) //菜单页面辅助函数
        {
            OLED_Clear();
            need_clear_display = false;
        }
        
        // switch(Page)//oled菜单页面
        // {
        // case 0:
        //     SHOW_Firstpage(Range, pitch, roll, yaw, sys_state);
        // break;
        // case 1:
        //     SHOW_Secondpage(acc);
        // break; 
        // case 2:
        //     SHOW_Thirdpage(cnt[0], cnt[1]);
        // break;
        // default:break;
        // }
            
    //     if(packet_ready)
    //    {
    //         __disable_irq();//
    //         memcpy(packet, rx_buff, BUFF_SIZE);
    //         packet_ready = false;
    //         __enable_irq();
    //         receive_task(packet);
    //    }
    }
    
}