#include "DELAY.h"
#include "KEY.h"
#include "LED.h"
#include "ti/driverlib/dl_timer.h"
#include "ti/driverlib/dl_timera.h"
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
int cnt_l;
int cnt_r;
bool need_clear_display;
float pitch, roll, yaw;//欧拉角
short acc[3];//加速度
int32_t state;
float measure=0;//角度测量值
int32_t state;
int velocity_measure=0;//速度测量值
int filt_encoder,last_encoder;
int PWM;
int PWM_left;
int PWM_right;
float Turn_out;



//*****PID设置*****//
float zhongzhi = -2.5;//机械中值
float angle_calcu;//希望小车平衡时的角度(pitch角)
//float velocity_calcu=0;//希望小车前进速度(这里填的应该是编码器数值，如果填20那就是oled显示20编码器为20时的小车速度)

float Kp = 230*0.6,Ki = 0,Kd =1500*0.6;//直立环

float VKp = 270,VKi = 270/200;//速度环

float TKp=0, TKi=0, TKd=0;
//****************//

int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    encoder_init();//编码器初始化
    MPU6050_Init();//mpu初始化
    mpu_dmp_init();//dmp初始化
    control_init();
    //OPENMV_Init();//开启OPENMV串口中断
    USOUND_Init();//开启超声波读取中断和定时中断
    MPU6050_IRQINIT();//读取中断初始化 必须放在所有初始化的最后

    while (1) 
    {
        if (line_flag || line_flag2) Line_Following();
        if(caiji_flag)//5ms读一次欧拉角
        {
            if(mpu_dmp_get_data(&pitch, &roll, &yaw, acc) == 0)
            {
                measure = pitch;
                angle_calcu = zhongzhi;
            }
        }
        // if(need_clear_display) //菜单页面辅助函数
        // {
        //     OLED_Clear();
        //     need_clear_display = false;
        // }
        
        // switch(Page)//oled菜单页面
        // {
        //     case 0:
        //         SHOW_Firstpage(Range, pitch, roll, yaw, sys_state);
        //     break;
        //     case 1:
        //         SHOW_Secondpage(acc);
        //     break; 
        //     case 2:
        //         SHOW_Thirdpage(cnt_l, cnt_r);
        //     break;
        //     default:break;
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
void pid_pro()
{
    cnt_l = get_encoder_cnt1();
    cnt_r = get_encoder_cnt2();
    encoder_Rst();
    velocity_measure = (cnt_l + cnt_r )/2; //速度测量值
  
	// filt_encoder = 0.3*velocity_measure + 0.7*last_encoder;
    // last_encoder = filt_encoder;

    PWM = vertical_PID_value(measure, angle_calcu) + velocity_PID_value(velocity_measure,velocity_calcu);
    Turn_out = Turn(acc[2], error);
    PWM_left  =PWM-error;
    PWM_right =PWM+error;

    int dead_pwm = (PWM>0)?100:(PWM<0)?-100:0;
    set_motor_pwm(PWM_left+dead_pwm,PWM_right+dead_pwm);
    
}
//10ms中断一次
void TIMER_2_INST_IRQHandler()
{
    if (line_flag) {
        jin_flag_count ++;
    }

    if(line_flag2){
        jin_flag_count2 ++;
    }    

    static int count=0;
    if(DL_TimerA_getPendingInterrupt(TIMER_2_INST)==DL_TIMER_IIDX_ZERO)
    {
        encoder_update();
        pid_pro();
        if(Range < 20)
        {
            LED_ON(2);
        }
        else {
        LED_OFF(2);
        }
        if(buz_flag == 1)
        {
            count++;
            if(count>=100)
            {
                BUZ_OFF();
                buz_flag = 0;
                count =0;
            }

        }
    }
}