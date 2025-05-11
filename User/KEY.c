#include "KEY.h"

uint8_t temp;
uint8_t KEY_VAL(void)
{
    temp = 0;
    if(DL_GPIO_readPins(KEY_KEY_1_PORT, KEY_KEY_1_PIN) == 0) temp = 1;

    if(DL_GPIO_readPins(KEY_KEY_2_PORT, KEY_KEY_2_PIN) == 0) temp = 2;

    if(DL_GPIO_readPins(KEY_KEY_3_PORT, KEY_KEY_3_PIN) == 0) temp = 3;

    return temp;

}