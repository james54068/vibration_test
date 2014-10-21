#ifndef __gpio_H
#define __gpio_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
void GPIO_Configuration(void);

#define LED1_Port		GPIOA
#define LED1_CLK		RCC_APB2Periph_GPIOA
#define LED1_Pin		GPIO_Pin_0
#define LED1_ON();		GPIO_ResetBits( LED1_Port, LED1_Pin );  
#define LED1_OFF();		GPIO_SetBits( LED1_Port, LED1_Pin );
/*LED2 Pin Definition*/
#define LED2_Port		GPIOA
#define LED2_CLK		RCC_APB2Periph_GPIOA
#define LED2_Pin		GPIO_Pin_1
#define LED2_ON();		GPIO_ResetBits( LED2_Port, LED2_Pin );  
#define LED2_OFF();		GPIO_SetBits( LED2_Port, LED2_Pin );
#endif


