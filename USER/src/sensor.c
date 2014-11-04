#include "config.h"
#include "sensor.h"

int 			i=0;
float 			acc9150_offset[3];
float 			gyro9150_offset[3];
float 			acc6050_offset[3];
float 			gyro6050_offset[3];

volatile int16_t ACC_FIFO[3][256] = {{0}};
volatile int16_t GYR_FIFO[3][256] = {{0}};


#define MagCorrect_time   1000
#define MagCorrect_Ave    10


void initial_AccGyro(int16_t n)
{
	static float acc_buff[3];
	static float gyro_buff[3];
	float 	acc_offset[3];
	float 	gyro_offset[3];

	for(int i=0;i<MagCorrect_time;i++)
	{

	//MPU9150_GetRawAccelGyro(mpu9150_buf.buff,mpu9150_buf.magne);

		acc_offset[0] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[0], ACC_FIFO[0], MagCorrect_Ave);
		acc_offset[1] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[1], ACC_FIFO[1], MagCorrect_Ave);
		acc_offset[2] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[2], ACC_FIFO[2], MagCorrect_Ave);
		gyro_offset[0] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[3], GYR_FIFO[0], MagCorrect_Ave);
		gyro_offset[1] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[4], GYR_FIFO[1], MagCorrect_Ave);
		gyro_offset[2] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[5], GYR_FIFO[2], MagCorrect_Ave);

		acc_offset[0] = (acc_offset[0]/2048.0);//16384//8192
		acc_offset[1] = (acc_offset[1]/2048.0);//16384//8192
		acc_offset[2] = 1 - (acc_offset[2]/2048.0);//16384//8192
		gyro_offset[0] = (gyro_offset[0]/16.4);//16384//8192
		gyro_offset[1] = (gyro_offset[1]/16.4);//16384//8192
		gyro_offset[2] = (gyro_offset[2]/16.4);//16384//8192

		printf("acc_x,%f,acc_y,%f,acc_z,%f,gyr_x,%f,gyr_y,%f,gyr_z,%f\r\n",
			acc_offset[0],acc_offset[1],acc_offset[2],gyro_offset[0],gyro_offset[1],gyro_offset[2]);
		
	}

	switch (n)
	{
		case 1:
			acc9150_offset[0]	= 	acc_offset[0];	
			acc9150_offset[1]	= 	acc_offset[1];
			acc9150_offset[2]	= 	acc_offset[2];
			gyro9150_offset[0]	=	gyro_offset[0];
			gyro9150_offset[1]	=	gyro_offset[1];
			gyro9150_offset[2]	=	gyro_offset[2];
			break;

		case 2:
			acc6050_offset[0]	= 	acc_offset[0];	
			acc6050_offset[1]	= 	acc_offset[1];
			acc6050_offset[2]	= 	acc_offset[2];
			gyro6050_offset[0]	=	gyro_offset[0];
			gyro6050_offset[1]	=	gyro_offset[1];
			gyro6050_offset[2]	=	gyro_offset[2];
			break;

		default:
			printf("IMU does not exsit\r\n");


	}

	printf("acc_x,%f,acc_y,%f,acc_z,%f,gyr_x,%f,gyr_y,%f,gyr_z,%f\r\n",
			acc_offset[0],acc_offset[1],acc_offset[2],gyro_offset[0],gyro_offset[1],gyro_offset[2]);

	printf("GYR,ACC calibration complete\r\n ready to calibrate magnetometer \r\n");

}

void mpu_9150_data()
{
	//uint8_t 	tmp;
	//MPU9150_GetRawAccelGyro(mpu9150_buf.buff,mpu9150_buf.magne);
	//delay(10);
	
	acc9150.x = (mpu9150_buf.buff[0]/2048.0);//16384//8192
	acc9150.y = (mpu9150_buf.buff[1]/2048.0);//16384//8192
	acc9150.z = (mpu9150_buf.buff[2]/2048.0);//16384//8192
	gyr9150.x = (mpu9150_buf.buff[3]/16.4);//16384//8192
	gyr9150.y = (mpu9150_buf.buff[4]/16.4);//16384//8192
	gyr9150.z = (mpu9150_buf.buff[5]/16.4);//16384//8192
		
	acc9150.x -= acc9150_offset[0] ;//16384//8192
	acc9150.y -= acc9150_offset[1] ;//16384//8192
	acc9150.z += acc9150_offset[2] ;//16384//8192
	gyr9150.x -= gyro9150_offset[0] ;//16384//8192
	gyr9150.y -= gyro9150_offset[1] ;//16384//8192
	gyr9150.z -= gyro9150_offset[2] ;//16384//8192
	
		
}


