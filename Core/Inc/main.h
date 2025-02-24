/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_0
#define LED3_GPIO_Port GPIOA
#define ICM_INT_Pin GPIO_PIN_1
#define ICM_INT_GPIO_Port GPIOA
#define ICM_INT_EXTI_IRQn EXTI1_IRQn
#define ADC_Pin GPIO_PIN_2
#define ADC_GPIO_Port GPIOA
#define M2_IN1_Pin GPIO_PIN_3
#define M2_IN1_GPIO_Port GPIOA
#define M2_IN2_Pin GPIO_PIN_4
#define M2_IN2_GPIO_Port GPIOA
#define M1_IN1_Pin GPIO_PIN_6
#define M1_IN1_GPIO_Port GPIOA
#define M1_IN2_Pin GPIO_PIN_7
#define M1_IN2_GPIO_Port GPIOA
#define LCD_BLK_Pin GPIO_PIN_11
#define LCD_BLK_GPIO_Port GPIOB
#define LCD_RES_Pin GPIO_PIN_12
#define LCD_RES_GPIO_Port GPIOB
#define M2_ENA_Pin GPIO_PIN_6
#define M2_ENA_GPIO_Port GPIOC
#define M2_ENB_Pin GPIO_PIN_7
#define M2_ENB_GPIO_Port GPIOC
#define M1_ENA_Pin GPIO_PIN_8
#define M1_ENA_GPIO_Port GPIOA
#define M1_ENB_Pin GPIO_PIN_9
#define M1_ENB_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_10
#define LCD_DC_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_11
#define LCD_CS_GPIO_Port GPIOA
#define INA_INT_Pin GPIO_PIN_12
#define INA_INT_GPIO_Port GPIOA
#define INA_INT_EXTI_IRQn EXTI15_10_IRQn
#define Key3_Pin GPIO_PIN_5
#define Key3_GPIO_Port GPIOB
#define Key2_Pin GPIO_PIN_6
#define Key2_GPIO_Port GPIOB
#define Key1_Pin GPIO_PIN_7
#define Key1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
