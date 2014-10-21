#ifndef __USART_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
int _write (int fd, char *ptr, int len);
void send_byte(uint8_t b);
void send_string(uint8_t *str);
void delay(uint32_t delay_count);

#endif