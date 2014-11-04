
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
	
	/*72MHz/((999+1)*(72))=1000Hz  100*/	

						   																																																						
}

void TIM4_IRQHandler(void)
{
	char buff[10];
	int i=0;
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) 
	{	
		//gpio_toggle( GPIOB, GPIO_Pin_8);
		
		mpu_9150_data();

		sprintf(buff,"%f  ",acc9150.x);
		strcat(string,buff);	
		sprintf(buff,"%f  ",acc9150.y);
		strcat(string,buff);
		sprintf(buff,"%f  ",acc9150.z);
		strcat(string,buff);
		sprintf(buff,"%f  ",acc9150.x);
		strcat(string,buff);
		sprintf(buff,"%f  ",acc9150.y);
		strcat(string,buff);
		sprintf(buff,"%f  ",acc9150.z);
		strcat(string,buff);
		sprintf(buff,"%d  ",rpm);
		strcat(string,buff);
		strcat(string,"\r\n");

		send_string(string);	
		memset(string,0,100);
		//gpio_toggle( GPIOB, GPIO_Pin_8);	  			
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}






