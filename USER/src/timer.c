
#include "config.h"


void TIMER_Configuration(void)
{
  
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    /*TIMER4 */	
    TIM_TimeBaseStructure.TIM_Period =(uint16_t)(10000-1);			  			//period
  	TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t)(72-1);  					//high voltage portion(between 0-period)	
  	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM4, ENABLE);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);        				
	
	/*72MHz/((999+1)*(72))=100Hz*/	

						   																																																						
}



void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) 
	{	
		mpu_9150_data();
		printf("%f %f %f %f %f %f\r\n",acc.x,acc.y,acc.z,gyr.x,gyr.y,gyr.z);		  			

		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

/*100hz*/
void TIM3_IRQHandler(void)
{	
	if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET) 
	{	/*
		if(initial_flag == 1){		  				
			mpu_9150_data();
			printf("%f %f %f %f %f %f %f %f %f\r\n",acc.x,acc.y,acc.z,gyr.x,gyr.y,gyr.z);
			TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
		}
		*/
	}
}





