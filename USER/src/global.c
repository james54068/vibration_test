#include "global.h"
#include <stdlib.h>
#include <string.h>
#include "config.h"


u8      		correction_flag = 0;
sensor_acc		acc9150;
sensor_gyro		gyr9150;


/*initial*/
u8   			initial_flag = 0;
/*rpm*/
bool  			exti_flag = FALSE;
int16_t 		systic_count = 0;
int16_t 		exti_count = 0;
int16_t			rpm = 0;

/*DMA*/
/*usart*/
char   			string[100];
/*i2c*/
u8 				I2C1_Rx_Buffer[14];
imu_buffer   	mpu9150_buf;





















