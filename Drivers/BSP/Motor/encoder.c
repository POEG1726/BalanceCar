#include "encoder.h"
#include "tim.h"

#define M1_ENC_TIM_HANDLER (htim1)
#define M2_ENC_TIM_HANDLER (htim8)

/**
 * @brief  Initializes the encoders for both motors.
 */
void Encoder_Init()
{
    HAL_TIM_Base_Start(&M1_ENC_TIM_HANDLER);
    HAL_TIM_Base_Start(&M2_ENC_TIM_HANDLER);
    HAL_TIM_Encoder_Start(&M1_ENC_TIM_HANDLER, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&M2_ENC_TIM_HANDLER, TIM_CHANNEL_ALL);
}

/**
 * @brief  Reads the encoder value for the specified motor.
 * @param  MotorID: ID of the motor (0 or 1).
 * @param  EncoderValue: Pointer to store the encoder value.
 */
void Read_Encoder(uint8_t MotorID, int32_t* EncoderValue)
{
    switch (MotorID)
    {
    case 0:
        *EncoderValue = (int32_t)__HAL_TIM_GET_COUNTER(&M1_ENC_TIM_HANDLER);
        break;
    case 1:
        *EncoderValue = (int32_t)__HAL_TIM_GET_COUNTER(&M2_ENC_TIM_HANDLER);
        break;
    }
}