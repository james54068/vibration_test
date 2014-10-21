#ifndef __USART_H
#define __USART_H

#include "bool.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void USART_Config(USART_TypeDef* , uint32_t );
void USART_SendData_u8(USART_TypeDef*   , u8) ;
bool findGPGGA();


#endif
