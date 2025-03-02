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
  typedef enum
  {
    CW,
    CCW
  } MotorDir;

  typedef struct
  {
    float accel_x;
    float accel_y;
    float accel_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
    float Temperature;
  } ICM42688_Data_t;

  typedef struct
  {
    int WifiSignalStrength;
    float Voltage;
    float Temperature;
    ICM42688_Data_t IMUData;
    struct
    {
      float Speed;
      MotorDir Direction; // CW 或 CCW
      float Amps;
    } Motor[2];
  } SensorData_t;

  typedef enum
  {
    CMD_MOVE,
    CMD_SPIN,
    CMD_MOTOR,
    CMD_UNKNOWN
  } CommandType;

  typedef struct
  {
    int stop;         // move 命令中的 Stop 参数（是否急停，0表示不急停，1表示急停）
    char sd;          // move 命令中的 S/D 参数（例如用字符 'S' 表示速度模式，'D' 表示距离模式）
    char wasd[16];    // move 命令中的方向参数，可能是组合的 "W", "A", "S", "D"
    int value;        // move 命令中的 Value 参数
    int time;         // move 命令中的 Time 参数（如果为速度模式，运行时间；0表示无限）
  } MoveParams;

  typedef struct
  {
    char lr;          // spin 命令中的 L/R 参数， 'L' 或 'R'
    int angle;        // spin 命令中的角度参数
  } SpinParams;

  typedef struct
  {
    int motorID;      // motor 命令中的 MotorID
    char dir;         // motor 命令中的 Dir 参数，'C'（CW）或 'C'（CCW），可根据需要修改
    int angle;        // motor 命令中的 Angle 参数
  } MotorParams;

  // 使用联合体存储不同类型命令的参数
  typedef union
  {
    MoveParams move;
    SpinParams spin;
    MotorParams motor;
  } CommandParams;

  // 定义最终的命令结构体
  typedef struct
  {
    CommandType type;
    CommandParams params;
  } Command;

  // ICM42688_Data_t imu_data;

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
