
#include <stdlib.h>
#include "initial.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"




void Initial_MCU(void)
{	
	
	RCC_Configuration();	// Enable Clock
	GPIO_Configuration();	// Define Indicator LED
	/*usart*/
	DMA1_Channel4_Configuration();
	/*i2c*/
	DMA1_Channel7_Configuration();
 	
	MPU6050_I2C_Init();
	MPU6050_Initialize();

	USART_Config(USART1, 921600) ;  //for display on computer
	
	
	SysTick_cfg();

	NVIC_Configuration();


}


