#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "ti_msp_dl_config.h"
//编码器方向
enum{
    FORWARD,
    REVERSAL
};
void encoder_init(void);
int get_encoder_cnt1(void);
int get_encoder_cnt2(void);
uint8_t get_direction(void);
void encoder_Rst(void);
void encoder_update(void);

#endif