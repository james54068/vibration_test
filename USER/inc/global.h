#ifndef __global_H
#define __global_H

#include "config.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

typedef enum {OFF = 0, ON = !RESET} Switch;

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
extern  sensor_acc		acc9150;
extern  sensor_gyro		gyr9150;


/*initial*/
extern  u8   			initial_flag;
/*rpm*/
extern  bool   			exti_flag;
extern  int16_t 		exti_count;
extern  float			rpm;




#endif

