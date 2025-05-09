#ifndef _OPENMV_H_
#define _OPENMV_H_
//帧头、帧尾
#define HEADER_BYTE 0xAA
#define FOOTER_BYTE 0x55

#define BUFF_SIZE 5

#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "string.h"
void receive_task(uint8_t* str);
#endif

