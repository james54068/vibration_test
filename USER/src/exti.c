#include <stdlib.h>
#include "config.h"

void EXTI_Configuration(void)
{
  	EXTI_InitTypeDef EXTI_InitStructure;        						//EXTI��l��

	EXTI_ClearITPendingBit(EXTI_Line2);							    	//�M�����_�лx
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;				 			//���u���

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					//�ƥ���
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling ;		//�D�o�Ҧ�
	
 	EXTI_InitStructure.EXTI_LineCmd = ENABLE;							//�Ұʤ��_
 	EXTI_Init(&EXTI_InitStructure);										//��l��
	EXTI_GenerateSWInterrupt(EXTI_Line2);
}


void EXTI2_IRQHandler(void)
{
   	if(EXTI_GetITStatus(EXTI_Line2) != RESET)
  	{
  		rpm = rpm_calculation(exti_count);

  		if (rpm>10000)
  			rpm = 10000;
  		else if (rpm < 1000)
  			rpm = 1000;
  		
  		exti_count = 0;
  			
	EXTI_ClearITPendingBit(EXTI_Line2); 
  	} 
}

float rpm_calculation(int16_t count)
{
	float second = count * 0.001;
 	return 60.0/second;

}

