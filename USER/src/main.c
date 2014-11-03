
#include "config.h"

	
 int main(void)
{
	/*Initial STM32*/
	Initial_MCU();
	initial_AccGyro(1);
	TIMER_Configuration();
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);

	//DELAY_ms(5000);
	//initial_flag = 1;
	while(1)
	{	

	//uint8_t tmp;
    //MPU6050_ReadBits(MPU6050_DEFAULT_ADDRESS, MPU6050_RA_CONFIG, 2, 3, &tmp);
    //printf("%x \r\n",tmp); 
   	//gpio_toggle( GPIOB, GPIO_Pin_9);
 	//sys_Delay(1);	
	}
}






