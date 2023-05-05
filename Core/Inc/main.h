/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define En4A_Pin GPIO_PIN_2
#define En4A_GPIO_Port GPIOE
#define En4B_Pin GPIO_PIN_3
#define En4B_GPIO_Port GPIOE
#define Dir4_Pin GPIO_PIN_4
#define Dir4_GPIO_Port GPIOE
#define Mode4_Pin GPIO_PIN_5
#define Mode4_GPIO_Port GPIOE
#define Enc1A_Pin GPIO_PIN_1
#define Enc1A_GPIO_Port GPIOC
#define Enc1A_EXTI_IRQn EXTI1_IRQn
#define Enc1B_Pin GPIO_PIN_2
#define Enc1B_GPIO_Port GPIOC
#define En3A_Pin GPIO_PIN_4
#define En3A_GPIO_Port GPIOA
#define En3B_Pin GPIO_PIN_5
#define En3B_GPIO_Port GPIOA
#define Dir3_Pin GPIO_PIN_6
#define Dir3_GPIO_Port GPIOA
#define Mode3_Pin GPIO_PIN_7
#define Mode3_GPIO_Port GPIOA
#define Enable4B_Pin GPIO_PIN_5
#define Enable4B_GPIO_Port GPIOC
#define bat_Pin GPIO_PIN_1
#define bat_GPIO_Port GPIOB
#define Dir1_Pin GPIO_PIN_14
#define Dir1_GPIO_Port GPIOB
#define Mode1_Pin GPIO_PIN_15
#define Mode1_GPIO_Port GPIOB
#define En2A_Pin GPIO_PIN_8
#define En2A_GPIO_Port GPIOD
#define En2B_Pin GPIO_PIN_9
#define En2B_GPIO_Port GPIOD
#define Dir2_Pin GPIO_PIN_10
#define Dir2_GPIO_Port GPIOD
#define Mode2_Pin GPIO_PIN_11
#define Mode2_GPIO_Port GPIOD
#define Enc3A_Pin GPIO_PIN_7
#define Enc3A_GPIO_Port GPIOC
#define Enc3A_EXTI_IRQn EXTI9_5_IRQn
#define Enc3B_Pin GPIO_PIN_8
#define Enc3B_GPIO_Port GPIOC
#define Enc4B_Pin GPIO_PIN_12
#define Enc4B_GPIO_Port GPIOC
#define Enc4A_Pin GPIO_PIN_3
#define Enc4A_GPIO_Port GPIOD
#define Enc4A_EXTI_IRQn EXTI3_IRQn
#define Enc2A_Pin GPIO_PIN_4
#define Enc2A_GPIO_Port GPIOB
#define Enc2A_EXTI_IRQn EXTI4_IRQn
#define Enc2B_Pin GPIO_PIN_5
#define Enc2B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
