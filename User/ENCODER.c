#include "ENCODER.h"
#include "USOUND.h"
#include "ti/devices/msp/m0p/mspm0g350x.h"

int encoder_cnt1=0;
int encoder_cnt2=0;
volatile long long pre_encoder_cnt1=0,pre_encoder_cnt2=0;
uint8_t direction=0;
volatile uint32_t gpio_flag;
volatile uint32_t gpiob_flag;



void encoder_init(void)
{
    NVIC_ClearPendingIRQ(MOTOR_INT_IRQN);//
    NVIC_EnableIRQ(MOTOR_INT_IRQN);
}

int get_encoder_cnt1(void)
{
    return encoder_cnt1;
}
int get_encoder_cnt2(void)
{
    return encoder_cnt2;
}
uint8_t get_direction(void)
{
    return direction;
}
void encoder_Rst(void)
{
    pre_encoder_cnt1=0;
    pre_encoder_cnt2=0;
}
void encoder_update(void)
{
    encoder_cnt1=pre_encoder_cnt1;
    encoder_cnt2=pre_encoder_cnt2;
}

int usound_flag;
uint32_t cnt;
uint32_t dist;

void GROUP1_IRQHandler(void)
{
    

    // gpiob_flag = DL_GPIO_getEnabledInterruptStatus(USOUND_PORT,USOUND_Echo_PIN);
    // if((gpiob_flag&USOUND_Echo_PIN) == USOUND_Echo_PIN)
    // {
    //     if(usound_flag == 0)
    //     {
    //         DL_TimerG_setTimerCount(TIMER_USOUND_INST, 0);//计数置0
    //         DL_TimerG_startCounter(TIMER_USOUND_INST);//开始计数
    //         usound_flag = 1;
    //     }   
    //     else
    //     {
    //         DL_TimerG_stopCounter(TIMER_USOUND_INST);//停止计数
    //         usound_flag = 0;
    //         cnt = DL_TimerG_getTimerCount(TIMER_USOUND_INST);
    //         DL_TimerG_setTimerCount(TIMER_USOUND_INST, 0);
    //         Range = cnt*0.017;
    //     }
    //  }
    //  DL_GPIO_clearInterruptStatus(USOUND_PORT,USOUND_Echo_PIN);



    gpio_flag=DL_GPIO_getEnabledInterruptStatus(MOTOR_PORT,MOTOR_E2B_PIN|MOTOR_E2A_PIN|MOTOR_E1A_PIN|MOTOR_E1B_PIN);

    if((gpio_flag&MOTOR_E1A_PIN)==MOTOR_E1A_PIN)//A相上升沿
    {
        if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_E1B_PIN))
        {
            pre_encoder_cnt1--;
        }
        else
        {
            pre_encoder_cnt1++;
        }
    }
    else if((gpio_flag&MOTOR_E1B_PIN)==MOTOR_E1B_PIN)//B相上升沿
    {
        if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_E1A_PIN))
        {
            pre_encoder_cnt1++;
        }
        else
        {
            pre_encoder_cnt1--;
        }
    }
    else if((gpio_flag&MOTOR_E2A_PIN)==MOTOR_E2A_PIN)//A2相上升沿
    {
        if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_E2B_PIN))
        {
            pre_encoder_cnt2++;
        }
        else
        {
            pre_encoder_cnt2--;
        }
    }
    else if((gpio_flag&MOTOR_E2B_PIN)==MOTOR_E2B_PIN)//B2相上升沿
    {
        if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_E2A_PIN))
        {
            pre_encoder_cnt2--;
        }
        else
        {
            pre_encoder_cnt2++;
        }
    }

    DL_GPIO_clearInterruptStatus(MOTOR_PORT,MOTOR_E2B_PIN|MOTOR_E2A_PIN|MOTOR_E1A_PIN|MOTOR_E1B_PIN);
}