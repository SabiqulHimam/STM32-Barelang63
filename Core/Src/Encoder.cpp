/*
 * Encoder.cpp
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#include "Encoder.h"

Encoder::Encoder(GPIO_TypeDef *GPIOxA, GPIO_TypeDef *GPIOxB, uint16_t pinA, uint16_t pinB)
{
	encA_port = GPIOxA;
	encB_port = GPIOxB;

	encA_pin = pinA;
	encB_pin = pinB;
}

void Encoder::ReadPin()
{
	pulseA = HAL_GPIO_ReadPin(encA_port, encA_pin);
	pulseB = HAL_GPIO_ReadPin(encB_port, encB_pin);
}

void Encoder::Counting()
{
	ReadPin();

	if(pulseA != pulseB) counter ++;
	else counter --;
}

void Encoder::CountingReverse()
{
	ReadPin();

	if(pulseA == pulseB) counter ++;
	else counter --;
}

int Encoder::GetCounter()
{
	return counter;
}

void Encoder::ResetCounter()
{
	counter = 0;
}
