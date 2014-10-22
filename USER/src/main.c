
#include "config.h"

	
 int main(void)
{
	/*Initial STM32*/
	Initial_MCU();
	initial_AccGyro();
	TIMER_Configuration();
 	SysTick_cfg();
	//DELAY_ms(5000);
	//initial_flag = 1;
	while(1)
	{	
   	gpio_toggle( GPIOB, GPIO_Pin_9);
 	sys_Delay(1);	
	}
}






