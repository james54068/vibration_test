

#include <stdlib.h>
#include "dma.h"
#include "global.h"
#include "config.h"



void DMA1_Channel3_Configuration(void)
{
  
}


void DMA1_Channel5_Configuration(void)
{
  	//DMA_InitTypeDef DMA_InitStructure;
  	/*Enable DMA1 clock*/
  	//RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  	/*Configure DMA1 Channel1*/
/*  	DMA_DeInit(DMA1_Channel4);
  	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&(I2C2->DR);
  	DMA_InitStructure.DMA_MemoryBaseAddr = (u32);
  	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  	DMA_InitStructure.DMA_BufferSize = 10;
  	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  	DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
  	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  	DMA_Init(DMA1_Channel4, &DMA_InitStructure);  
  	//Enable DMA1 channel1
  	DMA_Cmd(DMA1_Channel4, ENABLE);*/
}

void DMA1_Channel4_Configuration(void)
{
 	DMA_InitTypeDef DMA_InitStructure;
  	/*Enable DMA1 clock*/
  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  	/*Configure DMA1 Channel1*/
  	DMA_DeInit(DMA1_Channel4);
  	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&(USART1->DR);
  	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)string;
  	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  	DMA_InitStructure.DMA_BufferSize = strlen(string);
  	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  	DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
  	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  	DMA_Init(DMA1_Channel4, &DMA_InitStructure);  
  	//Enable DMA1 channel1
  	DMA_Cmd(DMA1_Channel4, ENABLE);
}

