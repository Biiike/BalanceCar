#include "ENCODER.h"

int encoder_cnt1=0;
int encoder_cnt2=0;
volatile long long pre_encoder_cnt1=0,pre_encoder_cnt2=0;
uint8_t direction=0;


void encoder_init(void)
{
    NVIC_ClearPendingIRQ(MOTOR_INT_IRQN);//超串口中断开启
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
void GROUP1_IRQHandler(void)
{
    uint32_t gpio_flag;

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