/*
 * motor.cpp
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */
#include "motor.h"

extern TIM_HandleTypeDef htim1;

MotorClass::MotorClass(GPIO_TypeDef *a, GPIO_TypeDef *b, uint16_t a2, uint16_t b2, __IO uint32_t &pwm){
	enA = a;
	enB = b;

	enA_pin = a2;
	enB_pin = b2;

	motorPwm = &pwm;
}

MotorClass::MotorClass(GPIO_TypeDef *a, uint16_t a2, uint16_t b2, __IO uint32_t &pwm){
	enA = a;
	enB = a;

	enA_pin = a2;
	enB_pin = b2;

	motorPwm = &pwm;
}


void MotorClass::Motor(int pwm){
	if(pwm == 0){
//		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
		HAL_GPIO_WritePin(enA, enA_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(enB, enB_pin, GPIO_PIN_RESET);
		*motorPwm = pwm;
		return ;
	}

	else if(pwm > 0){
		HAL_GPIO_WritePin(enA, enA_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(enB, enB_pin, GPIO_PIN_SET);
	}

	else{
		HAL_GPIO_WritePin(enA, enA_pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(enB, enB_pin, GPIO_PIN_RESET);
		pwm = -pwm;
	}

	pwm += 25;

	if(pwm > 225) pwm = 225;

	*motorPwm = pwm;
}
