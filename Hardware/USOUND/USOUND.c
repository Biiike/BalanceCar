#include "USOUND.h"
#include "BUZ.h"
#include "DELAY.h"
#include "KEY.h"
#include "Hardware\OLED\oled.h"
#include "User\ENCODER.h"
#include "CONTROL.h"
#include "User\FINDLINE.h"
uint8_t overflowFlag;
bool sys_state = 0;
uint16_t Range=0;
uint8_t Page = 0;
bool need_clear_display; 
int Key_Val,Key_Down,Key_Old;
float velocity_calcu = 0;
int line_flag;//巡线打开标志
int line_flag2;

//按键的读取也放在超声波的读取中断里了
void USOUND_Init()
{
    // NVIC_ClearPendingIRQ(TIMER_USOUND_INST_INT_IRQN);//超声波计时中断开启
    // NVIC_EnableIRQ(TIMER_USOUND_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(TIMER_1_INST_INT_IRQN);//超声波读取中断开启
    NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(USOUND_INT_IRQN);
    NVIC_EnableIRQ(USOUND_INT_IRQN);

}



void USOUND(void)
{
    DL_GPIO_setPins(USOUND_PORT, USOUND_Trig_PIN);
    delay_us(12);
    DL_GPIO_clearPins(USOUND_PORT, USOUND_Trig_PIN);

    // while(!DL_GPIO_readPins(USOUND_PORT, USOUND_Echo_PIN));
    // overflowFlag = 0;//溢出标志位
    // DL_TimerG_setTimerCount(TIMER_USOUND_INST, 0);//计数置0
    // DL_TimerG_startCounter(TIMER_USOUND_INST);//开始计数

    // while((DL_GPIO_readPins(USOUND_PORT, USOUND_Echo_PIN)) && (!overflowFlag));//溢出或受到回波跳出
    // DL_TimerG_stopCounter(TIMER_USOUND_INST);//停止计数

    // if(overflowFlag)
    // {
    //     dist = 0;
    // }
    // else 
    // {

    // }
    // return dist;
}

// void TIMER_USOUND_INST_IRQHandler(void)//超声波的计时中断
// {
//     overflowFlag = 1;
// }

void TIMER_1_INST_IRQHandler(void)//超声波的读取中断 10ms
{   Key_Val = KEY_VAL();//
    Key_Down = Key_Val & (Key_Old ^ Key_Val);//
    Key_Old = Key_Val;
    switch (Key_Down) {
        case 1:
            jin_flag_count =9999;
            jin_flag_count2 = 0;
            velocity_calcu = 3;
            line_flag2 = 1;
            Kp = 230*0.6,Ki = 0,Kd =1500*0.6;//直立环
            VKp = 190,VKi = 200/200;//速度环
        break;
        case 2:
            velocity_calcu = 0;
            line_flag = 0;
        break;
        case 3:
            jin_flag_count =0;
            jin_flag_count2 = 9999;
            velocity_calcu = 4;
            line_flag = 1;
            Kp = 230*0.6,Ki = 0,Kd =1500*0.6;//直立环
            VKp = 190,VKi = 200/200;//速度环
        break;

        default:break; 
    }

    static uint16_t cnt1=0;
    if(DL_TimerG_getPendingInterrupt(TIMER_1_INST)==DL_TIMER_IIDX_ZERO)
    {

        sys_state ^= 1;//系统运行标志，右上角会有"!"闪烁
        cnt1++;
        if(cnt1>=10)//100ms
        {
            //USOUND();
            cnt1=0;
        }
    }
}