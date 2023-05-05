/*
 * Encoder.h
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "stm32f4xx_hal.h"

class Encoder{
private:

	GPIO_TypeDef *encA_port, *encB_port;
	uint16_t encA_pin, encB_pin;

	volatile bool pulseA = false, pulseB = false;
	volatile int counter = 0;

public:
	Encoder(GPIO_TypeDef *GPIOxA, GPIO_TypeDef *GPIOxB, uint16_t pinA, uint16_t pinB);

	void ReadPin();

	void Counting();

	void CountingReverse();

	int GetCounter();

	void ResetCounter();
};



#endif /* INC_ENCODER_H_ */
