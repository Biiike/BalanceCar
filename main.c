#include "DELAY.h"
#include "ti_msp_dl_config.h"
#include "BUZ.h"
#include "SHOW.h" 
#include <stdbool.h>
#include "OPENMV.h"
#include "USOUND.h"
#include "bsp_mpu6050.h"
#include "MOTOR.h"
#include "oled.h"
uint8_t oled_buffer[16];

int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    MPU6050_Init();//mpu初始化
    mpu_dmp_init();//dmp初始化
    USOUND_Init();//开启超声波读取中断和定时中断
    //OPENMV_Init();//开启OPENMV串口中断
    MPU6050_IRQINIT();//读取中断初始化 必须放在所有初始化的最后

    while (1) 
    {
        if(need_clear_display) {
            OLED_Clear();
            need_clear_display = false;
        }
        
        switch(Page)
        {
        case 0:
            SHOW_Firstpage(Range, pitch, roll, yaw, sys_state);
        break;
        case 1:
            SHOW_Secondpage(acc);//菜单显示函数
        break;     
        }

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