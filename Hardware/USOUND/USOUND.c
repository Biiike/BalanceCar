#include "USOUND.h"



uint8_t overflowFlag;

uint32_t USOUND(void)
{
    uint32_t cnt, dist;
    DL_GPIO_setPins(USOUND_PORT, USOUND_Trig_PIN);
    delay_cycles(CPUCLK_FREQ/50000);
    DL_GPIO_clearPins(USOUND_PORT, USOUND_Trig_PIN);
    while(!DL_GPIO_readPins(USOUND_PORT, USOUND_Echo_PIN)) ;
    overflowFlag = 0;//溢出标志位
    DL_TimerG_setTimerCount(TIMER_USOUND_INST, 0);//计数置0
    DL_TimerG_startCounter(TIMER_USOUND_INST);//开始计数

    while(DL_GPIO_readPins(USOUND_PORT, USOUND_Echo_PIN) && (overflowFlag == 0));//溢出或受到回波跳出
    DL_TimerG_stopCounter(TIMER_USOUND_INST);//停止计数

    if(overflowFlag)
    {
        dist = 0;
    }
    else 
    {
        cnt = DL_TimerG_getTimerCount(TIMER_USOUND_INST);
        dist = cnt*0.017;
    }
    return dist;
}

void TIMER_Ultrasonic_INST_IRQHandler(void)
{
    // switch (DL_TimerG_getPendingInterrupt(TIMER_USOUND_INST)) {
    //     case DL_TIMER_IIDX_LOAD://溢出事件，也叫重装载事件
            overflowFlag = 1;
    //         break;
    //     default:
    //         break;
    // }
}