#ifndef __timer_H
#define __timer_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void TIMER_Configuration(void);

void PWMoutputA(u16 i);
void PWMoutputB(u16 j);
void PWMoutputC(u16 m);
void PWMoutputD(u16 n);

#endif
