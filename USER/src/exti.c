#include <stdlib.h>
#include "config.h"

void EXTI_Configuration(void)
{
   EXTI_InitTypeDef EXTI_InitStructure;        						//EXTI初始化


/*line2*/
	 EXTI_ClearITPendingBit(EXTI_Line2);							    	//清除中斷標誌
	 EXTI_InitStructure.EXTI_Line = EXTI_Line2;				 			//路線選擇
	 EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					//事件選擇
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling ;		//触發模式	
 	 EXTI_InitStructure.EXTI_LineCmd = ENABLE;							//啟動中斷
 	 EXTI_Init(&EXTI_InitStructure);										//初始化
	 EXTI_GenerateSWInterrupt(EXTI_Line2);


/*line4*/
   EXTI_ClearITPendingBit(EXTI_Line4);                   //清除中斷標誌
   EXTI_InitStructure.EXTI_Line = EXTI_Line4;             //路線選擇
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;          //事件選擇
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;   //触發模式
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;              //啟動中斷
   EXTI_Init(&EXTI_InitStructure);                    //初始化
   EXTI_GenerateSWInterrupt(EXTI_Line4);

}


void EXTI2_IRQHandler(void)
{
   	if(EXTI_GetITStatus(EXTI_Line2) != RESET)
  	{
  		rpm = rpm_calculation(systic_count,exti_count);

  		if (rpm>10000)
  			rpm = 10000;
  		else if (rpm < 1000)
  			rpm = 1000;
  		
  		systic_count = 0;
      exti_count = 0;
      //gpio_toggle( GPIOB, GPIO_Pin_8);
  			
	EXTI_ClearITPendingBit(EXTI_Line2); 
  	} 
}

int16_t rpm_calculation(int16_t systic_count,int16_t exti_count)
{
	float second = systic_count * 0.000001 + exti_count * 0.0001;
 	return 60.0/second;

}

void EXTI4_IRQHandler(void)
{

if (EXTI_GetITStatus(EXTI_Line4) != RESET)     //MPU6050_INT
{
  exti_count++;
  I2C_DMA_Read(MPU6050_DEFAULT_ADDRESS, MPU6050_RA_ACCEL_XOUT_H);
  EXTI_ClearITPendingBit(EXTI_Line4);
  }
}


