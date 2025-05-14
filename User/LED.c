#include "LED.h"
#include "ti/driverlib/dl_gpio.h"

//1是蓝色 2是绿色 3是红色
void LED_ON(uint8_t color){

    switch(color){
        case 1 :
            DL_GPIO_clearPins(LED_LED1_PORT, LED_LED1_PIN);
        break;
        case 2:
            DL_GPIO_clearPins(LED_LED2_PORT, LED_LED2_PIN);
        break;
        case 3:
            DL_GPIO_clearPins(LED_LED3_PORT, LED_LED3_PIN);
        break;    
        }
}

void LED_OFF(uint8_t color){

    switch(color){
        case 1 :
            DL_GPIO_setPins(LED_LED1_PORT, LED_LED1_PIN);
        break;
        case 2:
            DL_GPIO_setPins(LED_LED2_PORT, LED_LED2_PIN);
        break;
        case 3:
            DL_GPIO_setPins(LED_LED3_PORT, LED_LED3_PIN);
        break;    
        }
}