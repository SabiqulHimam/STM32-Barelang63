/*
 * mainpp.h
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#ifndef INC_MAINPP_H_
#define INC_MAINPP_H_

#include "stm32f4xx_hal.h"

#define gy_huart huart1
#define gy_hdma hdma_usart1_rx

#define M1_Port GPIOB
#define M1_EnbA GPIO_PIN_13
#define M1_EnbB GPIO_PIN_14

#define M2_Port GPIOD
#define M2_EnbA GPIO_PIN_9
#define M2_EnbB GPIO_PIN_10

#define M3_Port GPIOA
#define M3_EnbA GPIO_PIN_5
#define M3_EnbB GPIO_PIN_6

//#define M4_PortA GPIOE
//#define M4_PortB GPIOE
//#define M4_EnbA GPIO_PIN_3
//#define M4_EnbB GPIO_PIN_4

#define M4_PortA GPIOA
#define M4_PortB GPIOC
#define M4_EnbA GPIO_PIN_7
#define M4_EnbB GPIO_PIN_5

void init();

void loop();

void SendDatatoPC();

void TakeEncoder();

void IMU_RX_Interrupt_Start();

void recallImu();

void motorStopifLost();

int since(unsigned long last);

#endif /* INC_MAINPP_H_ */
