#ifndef _USOUND_H_
#define _USOUND_H_


#include "USOUND.h"
#include "ti_msp_dl_config.h"
#include "LED.h"

void USOUND();
void USOUND_Init(void);
extern bool sys_state;//系统运行状态
extern uint16_t Range;//超声波数据
extern uint8_t Page;
extern bool need_clear_display;
extern float velocity_calcu;
extern int line_flag;
<<<<<<< HEAD
extern int line_flag2;
=======

>>>>>>> 9f4ea1d7ae52ae9efc406f5c9c5bc89bca9d183d
#endif

