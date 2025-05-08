#include "DELAY.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti/driverlib/m0p/sysctl/dl_sysctl_mspm0g1x0x_g3x0x.h"
#include "ti_msp_dl_config.h"
#include "BUZ.h"
#include "SHOW.h" 


uint8_t Range=110;
float pitch=0;
float roll=0;
float yaw=0;



int main(void)
{

    SYSCFG_DL_init();
    delay_ms(200);
    OLED_Init();//oled初始化
    MPU6050_Init();//mpu初始化
    mpu_dmp_init();//dmp初始化
    NVIC_EnableIRQ(TIMER_USOUND_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_ClearPendingIRQ(TIMER_1_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);

    while (1) 
    {
        delay_ms(20);
       SHOW(Range, pitch, roll, yaw);
       if((DL_GPIO_readPins(KEY_KEY_1_PORT, KEY_KEY_1_PIN ) == 0) 
        && (DL_GPIO_readPins(KEY_KEY_2_PORT, KEY_KEY_2_PIN ) == 0) 
        && (DL_GPIO_readPins(KEY_KEY_3_PORT, KEY_KEY_3_PIN )== 0))
        {
            DL_GPIO_setPins(LED_LED3_PORT, LED_LED3_PIN); 
        }
        else
        {
            DL_GPIO_clearPins(LED_LED3_PORT, LED_LED3_PIN); 
        }
    }
}



void TIMER_0_INST_IRQHandler(void)//MPU 20ms
{
    mpu_dmp_get_data(&pitch, &roll, &yaw);

}

void TIMER_1_INST_IRQHandler(void)//100ms中断
{
    DL_GPIO_togglePins(BUZ_PORT, BUZ_Buz_PIN);
    DL_GPIO_togglePins(LED_LED1_PORT, LED_LED1_PIN);
    DL_GPIO_togglePins(LED_LED2_PORT, LED_LED2_PIN);
    Range = USOUND();
}
