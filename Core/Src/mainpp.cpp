/*
 * mainpp.cpp
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#include "main.h"
#include "mainpp.h"
#include "DataStruct.h"
#include "usbd_cdc_if.h"
#include "string.h"
#include "IMU_GY25.h"
#include "motor.h"
#include "Encoder.h"

// Declaring Variable
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef gy_huart;
extern DMA_HandleTypeDef gy_hdma;

PC Command;
STM32 Send;

IMU_GY25 *IMU;
MotorClass *Motor1;
MotorClass *Motor2;
MotorClass *Motor3;
MotorClass *Motor4;

Encoder *Encoder1;
Encoder *Encoder2;
Encoder *Encoder3;
Encoder *Encoder4;

#define TX_Buff_Size 32
uint8_t TX_Buff[TX_Buff_Size];


unsigned long tick = 0;
unsigned long imuTick = 0;
unsigned long rxTick = 0;

bool heading, requestBin;
int16_t hehe = 200;

// Void
void init(){
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	IMU = new IMU_GY25(&gy_huart, &gy_hdma);

	Motor1 = new MotorClass(M1_Port, M1_EnbA, M1_EnbB, htim1.Instance->CCR1);
	Motor2 = new MotorClass(M2_Port, M2_EnbA, M2_EnbB, htim1.Instance->CCR2);
	Motor3 = new MotorClass(M3_Port, M3_EnbA, M3_EnbB, htim1.Instance->CCR3);
	Motor4 = new MotorClass(M4_PortA, M4_PortB, M4_EnbA, M4_EnbB, htim1.Instance->CCR4);

//	Motor1 = new MotorClass(En1A_GPIO_Port, En1A_Pin, En1B_Pin, 1);
//	Motor2 = new MotorClass(En2A_GPIO_Port, En2A_Pin, En2B_Pin, 2);
//	Motor3 = new MotorClass(En3A_GPIO_Port, En3A_Pin, En3B_Pin, 3);

	Encoder1 = new Encoder(Enc1A_GPIO_Port, Enc1B_GPIO_Port, Enc1A_Pin, Enc1B_Pin);
	Encoder2 = new Encoder(Enc2A_GPIO_Port, Enc2B_GPIO_Port, Enc2A_Pin, Enc2B_Pin);
	Encoder3 = new Encoder(Enc3A_GPIO_Port, Enc3B_GPIO_Port, Enc3A_Pin, Enc3B_Pin);
	Encoder4 = new Encoder(Enc4A_GPIO_Port, Enc4B_GPIO_Port, Enc4A_Pin, Enc4B_Pin);
//	Motor1 = new MotorClass(En1A_GPIO_Port, En1A_Pin, En1B_Pin, 4);

//	IMU->KalibrasiImu();
//
//	IMU_RX_Interrupt_Start();
}

void run(int m1, int m2, int m3, int m4){
	Motor1->Motor(m1);
	Motor2->Motor(m2);
	Motor3->Motor(m3);
	Motor4->Motor(m4);
}

void loop(){
	if(HAL_GetTick() - tick >= 10){
		tick = HAL_GetTick();
		SendDatatoPC();
		recallImu();
//		run(0,0,0,0);
		motorStopifLost();
	}
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
	if(huart->Instance == IMU->UART_IMU()){//Serial Imu-Gy25 to STM32
//		rawImu = -(IMU_RX_Buff[1] << 8 | IMU_RX_Buff[2]);
//
		Send.Imu = IMU->processingIMU();

		IMU->RX_Interrupt_Start();
//
//		IMU_RX_Interrupt_Start();
//
		imuTick = HAL_GetTick();
	}

}


void receiveData(uint8_t* buf, uint32_t len){
	memcpy((uint8_t*)&Command, buf, sizeof(Command));
	Motor4->Motor(-Command.motorSpeed[2]);
	Motor2->Motor(-Command.motorSpeed[0]);
	Motor1->Motor(-Command.motorSpeed[1]);
	rxTick = HAL_GetTick();
}


void SendDatatoPC(){
	TakeEncoder();
	memcpy(TX_Buff, (uint8_t*)&Send, sizeof(Send));
	CDC_Transmit_FS(TX_Buff, sizeof(Send));
}


void TakeEncoder(){
	Send.belakang = Encoder1->GetCounter();
	Encoder1->ResetCounter();
	Send.kanan = Encoder2->GetCounter();
	Encoder2->ResetCounter();
	Send.kiri = Encoder4->GetCounter();
	Encoder4->ResetCounter();
}

void recallImu(){
	const int dTick = HAL_GetTick() - imuTick;
	if(dTick > 400){
		imuTick = HAL_GetTick();
		IMU->reqBinary();
		IMU->RX_Interrupt_Start();
	}
}

void motorStopifLost(){
	if(since(rxTick) > 300){
		Motor4->Motor(0);
		Motor2->Motor(0);
		Motor3->Motor(0);
	}
}

int since(unsigned long last){
	return HAL_GetTick() - last;
}

//void IMU_RX_Interrupt_Start(){
//	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, IMU_RX_Buff, IMU_RX_Buff_Size);
//	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
//	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_TC);
//}
