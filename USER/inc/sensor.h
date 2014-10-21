#ifndef __sensor_H
#define __sensor_H
#include <math.h>
#include "bool.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
typedef struct {
	int16_t 	buff[6];
	int16_t 	magne[3];
	float       magn_correct[3];
}imu_buffer;

void 	initial_AccGyro();
void 	mpu_9150_data();

#endif