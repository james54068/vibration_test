#include <stdlib.h>
#include "exti.h"

void EXTI_Configuration(void)
{
  	EXTI_InitTypeDef EXTI_InitStructure;        						//EXTI��l��

	EXTI_ClearITPendingBit(EXTI_Line2);							    	//�M�����_�лx
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;				 			//���u���

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					//�ƥ���
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling ;		//�D�o�Ҧ�
	
 	EXTI_InitStructure.EXTI_LineCmd = ENABLE;							//�Ұʤ��_
 	EXTI_Init(&EXTI_InitStructure);										//��l��
	EXTI_GenerateSWInterrupt(EXTI_Line2);
}


void EXTI2_IRQHandler(void)
{
   	if(EXTI_GetITStatus(EXTI_Line2) != RESET)
  	{


	EXTI_ClearITPendingBit(EXTI_Line2); 
  	} 
}

