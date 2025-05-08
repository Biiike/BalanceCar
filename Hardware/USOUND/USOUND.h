#ifndef _USOUND_H_
#define _USOUND_H_



#include "ti_msp_dl_config.h"
uint32_t USOUND();


#endif

/*
 NVIC_EnableIRQ(TIMER_Ultrasonic_INST_INT_IRQN);
 记得初始化中断函数，不然会卡死程序
*/