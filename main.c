#include "DELAY.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti/driverlib/m0p/sysctl/dl_sysctl_mspm0g1x0x_g3x0x.h"
#include "ti_msp_dl_config.h"
#include "BUZ.h"
#include "SHOW.h" 
#include <stdbool.h>
#include "OPENMV.h"
#include "USOUND.h"
#include "bsp_mpu6050.h"

float pitch_buf = 1,roll_buf = 1,yaw_buf = 1;
int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    MPU6050_Init();//mpu初始化
    MPU6050_IRQINIT();//读取中断初始化
    mpu_dmp_init();//dmp初始化
    USOUND_Init();//开启超声波读取中断和定时中断
    //OPENMV_Init();//开启OPENMV串口中断

    while (1) 
    {
        delay_ms(50);
       SHOW(Range, pitch, roll, yaw,sys_state);//菜单显示函数

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