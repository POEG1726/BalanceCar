#include "control.h"
#include "icm42688p.h"
#include "esp32.h"

static uint8_t int_counter = 0;
extern ICM42688_Data_t imu_data;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM6)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        // ICM42688_ReadData();
          // ESP32_Send("ICM42688: Data Read", 20);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin==ICM_INT_Pin)
    {
        ICM42688_ReadData(&imu_data);
        int_counter++;
        if (int_counter >= 100)
        {
            ESP32_Send((uint8_t*)&imu_data, sizeof(imu_data));
            int_counter = 0;
        }
    }
}