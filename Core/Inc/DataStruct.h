/*
 * DataStruct.h
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#ifndef INC_DATASTRUCT_H_
#define INC_DATASTRUCT_H_

struct PC{
	int16_t motorSpeed[3] = {0,0,0};
};

struct STM32{
	uint16_t Imu;
	int16_t belakang, kanan, kiri;
	int8_t battery = 0;
	char key[6] = "STM32";
};




#endif /* INC_DATASTRUCT_H_ */
