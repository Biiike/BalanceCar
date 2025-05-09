#include "OPENMV.h"




void receive_task(uint8_t* str)
{
    uint8_t color_mode=str[1];

     DL_GPIO_clearPins(LED_LED1_PORT, LED_LED1_PIN);
     DL_GPIO_clearPins(LED_LED2_PORT, LED_LED2_PIN);
     DL_GPIO_clearPins(LED_LED3_PORT, LED_LED3_PIN);

     switch(color_mode)
     {
        case 1:DL_GPIO_setPins(LED_LED2_PORT,LED_LED2_PIN);break;
        case 2:DL_GPIO_setPins(LED_LED1_PORT,LED_LED1_PIN);break;
        case 3:DL_GPIO_setPins(LED_LED3_PORT,LED_LED3_PIN);break;
        default:break;
     }
}