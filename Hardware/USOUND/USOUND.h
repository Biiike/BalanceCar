#ifndef _USOUND_H_
#define _USOUND_H_


#include "ti_msp_dl_config.h"
#include "LED.h"

uint32_t USOUND();
void USOUND_Init(void);
extern bool sys_state;//系统运行状态
extern uint16_t Range;//超声波数据

#endif

