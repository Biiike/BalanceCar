#include "USOUND.h"
#include "KEY.h"

uint8_t overflowFlag;
bool sys_state = 0;
uint16_t Range=0;

//按键的读取也放在超声波的读取中断里了
void USOUND_Init()
{
    NVIC_ClearPendingIRQ(TIMER_USOUND_INST_INT_IRQN);//超声波计时中断开启
    NVIC_EnableIRQ(TIMER_USOUND_INST_INT_IRQN);

    NVIC_ClearPendingIRQ(TIMER_1_INST_INT_IRQN);//超声波读取中断开启
    NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);

}

uint32_t USOUND(void)
{
    uint32_t cnt, dist;
    DL_GPIO_setPins(USOUND_PORT, USOUND_Trig_PIN);
    delay_cycles(CPUCLK_FREQ/50000);
    DL_GPIO_clearPins(USOUND_PORT, USOUND_Trig_PIN);

    while(!DL_GPIO_readPins(USOUND_PORT, USOUND_Echo_PIN));
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

void TIMER_Ultrasonic_INST_IRQHandler(void)//超声波的计时中断
{
     overflowFlag = 1;
}

void TIMER_1_INST_IRQHandler(void)//超声波的读取中断 100ms
{
    if(KEY_VAL() == 1)//用来测按键的
        LED_ON(1);
        
    if(KEY_VAL() == 2)
        LED_OFF(1);
        
    sys_state ^= 1;//系统运行标志，右上角会有"!"闪烁
    //Range = USOUND(); //超声波调用函数，因为容易卡死所以注释了
}