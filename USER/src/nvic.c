

#include <stdlib.h>
#include "nvic.h"


void NVIC_Configuration(void)
{	
     NVIC_InitTypeDef NVIC_InitStructure;																																																																																								
	#ifdef  VECT_TAB_RAM  																																												
		/* Set the Vector Table base location at 0x20000000 */ 																																												
		NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 																																												
	#else  /* VECT_TAB_FLASH  */																																												
		/* Set the Vector Table base location at 0x08000000 */ 																																												
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   																																												
	#endif 	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	/*preemption:2 sub:8*/

	

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;																																												
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;																																												
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;																																												
	NVIC_Init(&NVIC_InitStructure);		
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;																																												
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;																																												
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;																																												
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_InitStructure);	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;        
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                      
  	NVIC_Init(&NVIC_InitStructure);       	
	 
}					 
