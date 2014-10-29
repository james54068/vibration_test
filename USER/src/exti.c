#include <stdlib.h>
#include "config.h"

void EXTI_Configuration(void)
{
  	EXTI_InitTypeDef EXTI_InitStructure;        						//EXTI初始化

	EXTI_ClearITPendingBit(EXTI_Line2);							    	//清除中斷標誌
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;				 			//路線選擇

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					//事件選擇
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling ;		//触發模式
	
 	EXTI_InitStructure.EXTI_LineCmd = ENABLE;							//啟動中斷
 	EXTI_Init(&EXTI_InitStructure);										//初始化
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

