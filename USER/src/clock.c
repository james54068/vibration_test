//*********************************************************
// Function: Configure the System Clock at 72MHz
// Input:  N/A
// Output: N/A
// Remark: Crystal = 8MHz
//*********************************************************
#include <stdlib.h>
#include "clock.h"
#include "config.h"
static __IO uint32_t TimingDelay;

ErrorStatus HSEStartUpStatus;

void RCC_Configuration(void)
{
	/* RCC system reset(for debug purpose) */
	RCC_DeInit();
	
	/* Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);
	
	/* Wait till HSE is ready */
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStartUpStatus == SUCCESS)
	{
		/* Enable Prefetch Buffer */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		/* Flash 2 wait state */
		FLASH_SetLatency(FLASH_Latency_2);
		
		/* HCLK = SYSCLK */
		RCC_HCLKConfig(RCC_SYSCLK_Div1); 
		
		/* PCLK2 = HCLK */
		RCC_PCLK2Config(RCC_HCLK_Div1); 
		
		/* PCLK1 = HCLK/2 */
		RCC_PCLK1Config(RCC_HCLK_Div2);
		
		/* PLLCLK = 8MHz * 9 = 72 MHz */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
		
		/* Enable PLL */ 
		RCC_PLLCmd(ENABLE);
		
		/* Wait till PLL is ready */
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
			;
		
		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/* Wait till PLL is used as system clock source */
		while(RCC_GetSYSCLKSource() != 0x08)
			;

	}

	/* APB2 clock enable */
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA |
							RCC_APB2Periph_GPIOB |
							RCC_APB2Periph_GPIOC |
							RCC_APB2Periph_AFIO  |
							RCC_APB2Periph_ADC1	 
							, ENABLE);

	/* APB1 clock enable */
	RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2 | 
							RCC_APB1Periph_TIM3 |
							RCC_APB1Periph_TIM4 				
							, ENABLE);
	
}


 void SysTick_cfg(void)
{
	printf("%d\r\n",SystemCoreClock);
  if (SysTick_Config(SystemCoreClock/1000))
  { 
    /* Capture error */ 
    while (1);
  }
}

 void SysTick_Handler(void)
{    
   exti_count ++;

   if (TimingDelay != 0x00)
 	{ 
    	TimingDelay--;
  	}
}

void sys_Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);

}

