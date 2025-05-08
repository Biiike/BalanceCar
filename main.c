#include "DELAY.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti/driverlib/m0p/sysctl/dl_sysctl_mspm0g1x0x_g3x0x.h"
#include "ti_msp_dl_config.h"
#include "KEY.h"
#include "BUZ.h"
#include "SHOW.h" 
#include <stdbool.h>
#include "LED.h"


uint16_t Range=0;
float pitch, roll, yaw;
bool sys_state = 0;


int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    MPU6050_Init();//mpu初始化
    mpu_dmp_init();//dmp初始化
    
    NVIC_ClearPendingIRQ(TIMER_USOUND_INST_INT_IRQN);//超声波开启中断
    NVIC_EnableIRQ(TIMER_USOUND_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);//MPU开启中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(TIMER_1_INST_INT_IRQN);//超声波读取中断
    NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);

    while (1) 
    {
        delay_ms(50);
       SHOW(Range, pitch, roll, yaw,sys_state);//菜单显示函数
    }
}



void TIMER_0_INST_IRQHandler(void)//MPU 14ms  推荐吧pid和pwm放在这里面一起输出 中断低于13ms oled 刷新率会很低
{
    mpu_dmp_get_data(&pitch, &roll, &yaw);//欧拉角函数
}

void TIMER_1_INST_IRQHandler(void)//100ms中断
{
    if(KEY_VAL() == 1)//用来测按键的
        LED_ON(1);
        
    if(KEY_VAL() == 2)
        LED_OFF(1);
        
    sys_state ^= 1;//系统运行标志，右上角会有"!"闪烁

    //Range = USOUND(); //超声波调用函数，因为容易卡死所以注释了
}
