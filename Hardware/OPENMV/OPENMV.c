#include "OPENMV.h"

uint8_t rx_buff[BUFF_SIZE];
volatile uint8_t rx_index = 0;
volatile bool packet_ready = false;
uint8_t packet[BUFF_SIZE];

void OPENMV_Init()
{
    NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);//超串口中断开启
    NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
}

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

void UART_1_INST_IRQHandler(void)//串口中断服务函数
{
    if(DL_UART_Main_getPendingInterrupt(UART_1_INST)==DL_UART_MAIN_IIDX_RX)
    {
        uint8_t receive=DL_UART_Main_receiveData(UART_1_INST);
        if(rx_index==0)
        {
            if(receive==HEADER_BYTE)
            {
                rx_buff[rx_index++]=receive;
            }
            else if(rx_index<BUFF_SIZE)
            {
                rx_buff[rx_index++]=receive;
                if(rx_index==BUFF_SIZE)
                {
                    if(rx_buff[BUFF_SIZE-1]==FOOTER_BYTE)
                    {
                        packet_ready=true;
                    }
                    rx_index=0;
                }
            }
            else
            {
                rx_index=0;
            }
        }
    }
}