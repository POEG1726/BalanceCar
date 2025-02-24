#include "Control.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM6)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        // ICM42688_ReadData();
          // ESP32_Send("ICM42688: Data Read", 20);
    }
}