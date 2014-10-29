#ifndef __exti_H
#define __exti_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
void EXTI_Configuration(void);
float rpm_calculation(int16_t count);

#endif
