#ifndef _SHOW_H_
#define _SHOW_H_
#include "USOUND.h"
#include "ti_msp_dl_config.h"
#include "bsp_mpu6050.h"
#include "inv_mpu.h"
#include "oled.h"
void SHOW_Firstpage(uint8_t Range, float pitch, float roll ,float yaw,bool sys_state);
void SHOW_Secondpage(short acc[3]);
void SHOW_Thirdpage(int get_encoder_cnt1 ,  int get_encoder_cnt2);
#endif