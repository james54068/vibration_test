#ifndef __clock_H
#define __clock_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
void RCC_Configuration(void);
void SysTick_cfg(void);
void sys_Delay(__IO uint32_t nTime);

#endif
