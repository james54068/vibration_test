

#include <stdlib.h>
#include "dma.h"
#include "global.h"
#include "config.h"



void DMA1_Channel3_Configuration(void)
{

  
}


void DMA1_Channel7_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    DMA_InitTypeDef  DMA_InitStructure;
 
    DMA_DeInit(DMA1_Channel7); //reset DMA1 channe1 to default values;
 
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&(I2C1->DR); //=0x40005410 : address of data reading register of I2C1
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)I2C1_Rx_Buffer; //variable to store data
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //channel will be used for peripheral to memory transfer
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal; //setting normal mode (non circular)
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; //medium priority
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  //Location assigned to peripheral register will be source
    DMA_InitStructure.DMA_BufferSize = 14;  //number of data to be transfered
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //automatic memory increment disable for peripheral
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //automatic memory increment enable for memory
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //source peripheral data size = 8bit
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; //destination memory data size = 8bit
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);
    DMA_ITConfig(DMA1_Channel7, DMA_IT_TC, ENABLE);
 
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn; //I2C1 connect to channel 7 of DMA1
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x05;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x05;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}

void DMA1_Channel4_Configuration(void)
{
 	DMA_InitTypeDef DMA_InitStructure;
  	/*Enable DMA1 clock*/
  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  	/*Configure DMA1 Channel4*/
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
  	//Enable DMA1 channel4
  	DMA_Cmd(DMA1_Channel4, ENABLE);
}

void DMA1_Channel7_IRQHandler(void)
{
  int i=0;
  if (DMA_GetFlagStatus(DMA1_FLAG_TC7))
  {
    /* Clear transmission complete flag */
    DMA_ClearFlag(DMA1_FLAG_TC7);
 
    I2C_DMACmd(MPU6050_I2C, DISABLE);
    /* Send I2C1 STOP Condition */
    I2C_GenerateSTOP(MPU6050_I2C, ENABLE);
    /* Disable DMA channel*/
    DMA_Cmd(DMA1_Channel7, DISABLE);

    //Read Accel data from byte 0 to byte 2
    for(i=0; i<3; i++)
    mpu9150_buf.buff[i]=((s16)((u16)I2C1_Rx_Buffer[2*i] << 8) + I2C1_Rx_Buffer[2*i+1]);
    //Skip byte 3 of temperature data
    //Read Gyro data from byte 4 to byte 6
    for(i=4; i<7; i++)
    mpu9150_buf.buff[i-1]=((s16)((u16)I2C1_Rx_Buffer[2*i] << 8) + I2C1_Rx_Buffer[2*i+1]);
  }
}

