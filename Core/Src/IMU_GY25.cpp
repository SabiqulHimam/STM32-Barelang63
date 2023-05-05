/*
 * IMU_GY25.cpp
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */


#include "IMU_GY25.h"
#include "main.h"


//IMU_GY25::IMU_GY25(UART_HandleTypeDef *huart, DMA_HandleTypeDef *tx, DMA_HandleTypeDef *rx):huart_GY(huart), tx_gy(tx), rx_gy(rx){
//	KalibrasiImu();
//	RX_Interrupt_Start();
//
//}

IMU_GY25::IMU_GY25(UART_HandleTypeDef *huart, DMA_HandleTypeDef *rx):huart_GY(huart), rx_gy(rx){
	KalibrasiImu();
	RX_Interrupt_Start();

	IMU_def = huart_GY->Instance;
}

void IMU_GY25::KalibrasiImu(){
	//Kalibrasi A5 dan 54
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 2, 1, 10);
	HAL_Delay(100);

	//Kalibrasi A5 dan 55
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 1, 1, 10);
	HAL_Delay(100);

	//Kalibrasi A5 dan 52 (Convert to ASCII)
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 3, 1, 10);
	HAL_Delay(100);
}

void IMU_GY25::kalibrasiHeading(){
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 1, 1, 10);
}

void IMU_GY25::reqBinary(){
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 3, 1, 10);
}

void IMU_GY25::queryMode(){
	HAL_UART_Transmit(huart_GY, kalibrasi, 1, 10);
	HAL_UART_Transmit(huart_GY, kalibrasi + 5, 1, 10);
}


void IMU_GY25::RX_Interrupt_Start(){
	HAL_UARTEx_ReceiveToIdle_DMA(huart_GY, IMU_RX_Buff, IMU_RX_Buff_Size);
	__HAL_DMA_DISABLE_IT(rx_gy, DMA_IT_HT);
	__HAL_DMA_DISABLE_IT(rx_gy, DMA_IT_TC);
}

uint16_t IMU_GY25::processingIMU(){
	rawImu = -(IMU_RX_Buff[1] << 8 | IMU_RX_Buff[2]);
	imu = rawImu;
	if(imu < 0) imu += 36000;
	return imu;
}
