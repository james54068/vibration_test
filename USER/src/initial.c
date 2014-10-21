
#include <stdlib.h>
#include "initial.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"




void Initial_MCU(void)
{	
	RCC_Configuration();	// Enable Clock
	GPIO_Configuration();	// Define Indicator LED
 	
	MPU6050_I2C_Init();
	MPU6050_Initialize();
	
	USART_Config( USART1, 115200) ;  //for display on computer
	
    EXTI_Configuration();
	NVIC_Configuration();


}


