#include "config.h"

int 			i=0;
float 			acc_offset[3];
float 			gyro_offset[3];

imu_buffer   	mpu9150_buf;


volatile int16_t ACC_FIFO[3][256] = {{0}};
volatile int16_t GYR_FIFO[3][256] = {{0}};


#define MagCorrect_time   100
#define MagCorrect_Ave    10


void initial_AccGyro()
{
	static float acc_buff[3];
	static float gyro_buff[3];

	for(int i=0;i<MagCorrect_time;i++)
	{

	MPU6050_GetRawAccelGyro(mpu9150_buf.buff,mpu9150_buf.magne);
	//delay(10);

		acc_offset[0] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[0], ACC_FIFO[0], MagCorrect_Ave);
		acc_offset[1] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[1], ACC_FIFO[1], MagCorrect_Ave);
		acc_offset[2] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[2], ACC_FIFO[2], MagCorrect_Ave);
		gyro_offset[0] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[3], GYR_FIFO[0], MagCorrect_Ave);
		gyro_offset[1] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[4], GYR_FIFO[1], MagCorrect_Ave);
		gyro_offset[2] = (s16)MoveAve_WMA((s16)mpu9150_buf.buff[5], GYR_FIFO[2], MagCorrect_Ave);

		acc_offset[0] = (acc_offset[0]/8192.0);//16384//8192
		acc_offset[1] = (acc_offset[1]/8192.0);//16384//8192
		acc_offset[2] = 1 - (acc_offset[2]/8192.0);//16384//8192
		gyro_offset[0] = (gyro_offset[0]/16.4);//16384//8192
		gyro_offset[1] = (gyro_offset[1]/16.4);//16384//8192
		gyro_offset[2] = (gyro_offset[2]/16.4);//16384//8192

		printf("acc_x,%f,acc_y,%f,acc_z,%f,gyr_x,%f,gyr_y,%f,gyr_z,%f\r\n",
			acc_offset[0],acc_offset[1],acc_offset[2],gyro_offset[0],gyro_offset[1],gyro_offset[2]);
	
	//delay(10);
	}

	printf("acc_x,%f,acc_y,%f,acc_z,%f,gyr_x,%f,gyr_y,%f,gyr_z,%f\r\n",
			acc_offset[0],acc_offset[1],acc_offset[2],gyro_offset[0],gyro_offset[1],gyro_offset[2]);

	printf("GYR,ACC calibration complete\r\n ready to calibrate magnetometer \r\n");

}

void mpu_9150_data()
{
	uint8_t 	tmp;
	MPU6050_GetRawAccelGyro(mpu9150_buf.buff,mpu9150_buf.magne);
	//delay(10);
	acc9150.x = (mpu9150_buf.buff[0]/8192.0);//16384//8192
	acc9150.y = (mpu9150_buf.buff[1]/8192.0);//16384//8192
	acc9150.z = (mpu9150_buf.buff[2]/8192.0);//16384//8192
	gyr9150.x = (mpu9150_buf.buff[3]/16.4);//16384//8192
	gyr9150.y = (mpu9150_buf.buff[4]/16.4);//16384//8192
	gyr9150.z = (mpu9150_buf.buff[5]/16.4);//16384//8192
		
	acc9150.x -= acc_offset[0] ;//16384//8192
	acc9150.y -= acc_offset[1] ;//16384//8192
	acc9150.z += acc_offset[2] ;//16384//8192
	gyr9150.x -= gyro_offset[0] ;//16384//8192
	gyr9150.y -= gyro_offset[1] ;//16384//8192
	gyr9150.z -= gyro_offset[2] ;//16384//8192
		
}
