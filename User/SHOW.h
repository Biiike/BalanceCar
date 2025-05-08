#ifndef _SHOW_H_
#define _SHOW_H_
#include "USOUND.h"
#include "ti_msp_dl_config.h"
#include "bsp_mpu6050.h"
#include "inv_mpu.h"
#include "oled.h"
void SHOW(uint8_t Range, float pitch, float roll ,float yaw,bool sys_state);

#endif