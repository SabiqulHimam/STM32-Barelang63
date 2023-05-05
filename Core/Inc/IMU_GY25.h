/*
 * IMU_GY25.h
 *
 *  Created on: Feb 22, 2023
 *      Author: abiq
 */

#ifndef INC_IMU_GY25_H_
#define INC_IMU_GY25_H_

#include "stm32f4xx_hal.h"


class IMU_GY25{
private:

	DMA_HandleTypeDef *tx_gy;
	DMA_HandleTypeDef *rx_gy;
	USART_TypeDef *IMU_def;
	int imu;
	// Kalibrasi A5, 55, 54, 52
	uint8_t kalibrasi[8] = {165,85,84,82,0x53, 0x51};

	size_t IMU_RX_Buff_Size = 16;

	int16_t rawImu;

public:
	UART_HandleTypeDef *huart_GY;
	uint8_t IMU_RX_Buff[16];
//	IMU_GY25(UART_HandleTypeDef *huart, DMA_HandleTypeDef *rx, USART_TypeDef);
	IMU_GY25(UART_HandleTypeDef *huart, DMA_HandleTypeDef *rx);

	void KalibrasiImu();

	void kalibrasiHeading();

	void reqBinary();

	void queryMode();

	void RX_Interrupt_Start();

	uint16_t processingIMU();

	USART_TypeDef* UART_IMU(){
//		return IMU_def;
		return huart_GY->Instance;
	}


};



#endif /* INC_IMU_GY25_H_ */
