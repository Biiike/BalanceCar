#include "ti_msp_dl_config.h"
//#include "OLED.h"
#include "stdio.h"
//#include "Servo.h"
#include "MOTOR.h"

void Motorleft(int Compare)//Compare��ֵ1600
{
    if(Compare > (1600*0.8))
        return;

	if(Compare>0)
	{//���� ��ת
	    DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN);                   
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
        DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_0_INDEX);
	}
	if(Compare<0)
	{//���� ��ת
		DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN );                   
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
        DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_0_INDEX);
	}
}
void Motorright(int Compare)
{
	if(Compare>0)
	{///�ҵ�� ��ת
		DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN   );                   
        DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
        DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_1_INDEX);
	}
	if(Compare<0)
		{//�ҵ�� ��ת
		DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN   );                   
        DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
        DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_1_INDEX);}
}

void GO_Ahead(int Compare)
{
	
if(Compare>0)
{//���� ��ת
	DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN   );                   
    DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_0_INDEX);
	//�ҵ�� ��ת
	DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN   );                   
    DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_1_INDEX);
  
}

if(Compare<0)
{//����  ��ת
	DL_GPIO_clearPins(MOTOR_PORT, MOTOR_AIN2_L_P_PIN   );                   
    DL_GPIO_setPins(MOTOR_PORT, MOTOR_AIN1_L_N_PIN);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_0_INDEX);
	//�ҵ�� ��ת
	DL_GPIO_clearPins(MOTOR_PORT, MOTOR_BIN2_R_P_PIN   );                   
    DL_GPIO_setPins(MOTOR_PORT, MOTOR_BIN1_R_N_PIN);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST,Compare, DL_TIMER_CC_1_INDEX);
}

}


