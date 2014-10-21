#ifndef __global_H
#define __global_H

#include "config.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

typedef struct {
	float 		x;
	float 		y;
	float       z;
}sensor_acc;

typedef struct {
	float 		x;
	float 		y;
	float       z;
}sensor_gyro;

/*for imu*/
extern  u8      		correction_flag;
extern  sensor_acc		acc;
extern  sensor_gyro		gyr;


/*initial*/
extern  u8   			initial_flag;



#endif

