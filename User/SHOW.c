#include "SHOW.h"
#include "stdio.h"
uint8_t oled_buffer[16];

void SHOW(uint8_t Range, float pitch, float roll, float yaw)
{
    OLED_ShowString(0,2,(uint8_t *)"Pitch:",16);
    OLED_ShowString(0,4,(uint8_t *)" Roll:",16);
    OLED_ShowString(0,6,(uint8_t *)"  Yaw:",16);
    OLED_ShowString(0,0,(uint8_t *)"Range:",16);
    sprintf((char *)oled_buffer, "%6.1f", pitch);
    OLED_ShowString(7*8,2,oled_buffer,16);
    sprintf((char *)oled_buffer, "%6.1f", roll);
    OLED_ShowString(7*8,4,oled_buffer,16);
    sprintf((char *)oled_buffer, "%6.1f", yaw);
    OLED_ShowString(7*8,6,oled_buffer,16);
    sprintf((char *)oled_buffer, "%6d", Range);
    OLED_ShowString(7*8,0,oled_buffer,16);}
