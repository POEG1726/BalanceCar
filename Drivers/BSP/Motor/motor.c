#include "motor.h"
#include "tim.h"

#define M1_IN1_TIM_HANDLER (htim16)
#define M1_IN2_TIM_HANDLER (htim17)
#define M2_IN1_TIM_HANDLER (htim15)
#define M2_IN2_TIM_HANDLER (htim3)
#define M1_IN1_TIM_CHANNEL (TIM_CHANNEL_1)
#define M1_IN2_TIM_CHANNEL (TIM_CHANNEL_1)
#define M2_IN1_TIM_CHANNEL (TIM_CHANNEL_2)
#define M2_IN2_TIM_CHANNEL (TIM_CHANNEL_2)

#define SET_M1_IN1_PWM_DUTY(Duty)  do { __HAL_TIM_SET_COMPARE(&M1_IN1_TIM_HANDLER, M1_IN1_TIM_CHANNEL, (Duty));} while(0)
#define SET_M1_IN2_PWM_DUTY(Duty)  do { __HAL_TIM_SET_COMPARE(&M1_IN2_TIM_HANDLER, M1_IN2_TIM_CHANNEL, (Duty));} while(0)
#define SET_M2_IN1_PWM_DUTY(Duty)  do { __HAL_TIM_SET_COMPARE(&M2_IN1_TIM_HANDLER, M2_IN1_TIM_CHANNEL, (Duty));} while(0)
#define SET_M2_IN2_PWM_DUTY(Duty)  do { __HAL_TIM_SET_COMPARE(&M2_IN2_TIM_HANDLER, M2_IN2_TIM_CHANNEL, (Duty));} while(0)

/**
 * @brief  Enables the motor by starting the base and PWM timers.
 */
void Motor_Enable()
{
    HAL_TIM_Base_Start(&M1_IN1_TIM_HANDLER);
    HAL_TIM_Base_Start(&M1_IN2_TIM_HANDLER);
    HAL_TIM_Base_Start(&M2_IN1_TIM_HANDLER);
    HAL_TIM_Base_Start(&M2_IN2_TIM_HANDLER);

    HAL_TIM_PWM_Start(&M1_IN1_TIM_HANDLER, M1_IN1_TIM_CHANNEL);
    HAL_TIM_PWM_Start(&M1_IN2_TIM_HANDLER, M1_IN2_TIM_CHANNEL);
    HAL_TIM_PWM_Start(&M2_IN1_TIM_HANDLER, M2_IN1_TIM_CHANNEL);
    HAL_TIM_PWM_Start(&M2_IN2_TIM_HANDLER, M2_IN2_TIM_CHANNEL);
}

// Slow Decay Mode
/**
 * @brief  Applies brake to the specified motor.
 * @param  MotorID: ID of the motor to apply brake (1 or 2).
 */
void Motor_Break(uint8_t MotorID)
{
    MotorID -= 1;
    switch (MotorID)
    {
    case 0:
        SET_M1_IN1_PWM_DUTY(100);
        SET_M1_IN2_PWM_DUTY(100);
        break;
    case 1:
        SET_M2_IN1_PWM_DUTY(100);
        SET_M2_IN2_PWM_DUTY(100);
        break;
    }
}

/**
 * @brief  Sets the speed and direction of the specified motor.
 * @param  Speed: Speed of the motor (0-100).
 * @param  Dir: Direction of the motor (Forward_CW or Backward_CCW).
 * @param  MotorID: ID of the motor to set (1 or 2).
 */
void Motor_Set_Velo(uint8_t Speed, Motor_Dir Dir, uint8_t MotorID)
{
    MotorID -= 1;
    switch (MotorID)
    {
    case 0:
        if (Dir == Forward_CW)
        {
            SET_M1_IN2_PWM_DUTY(0);
            SET_M1_IN1_PWM_DUTY(Speed);
        }
        if (Dir == Backward_CCW)
        {
            SET_M1_IN1_PWM_DUTY(0);
            SET_M1_IN2_PWM_DUTY(Speed);
        }
        break;
    case 1:
        if (Dir == Forward_CW)
        {
            SET_M2_IN2_PWM_DUTY(0);
            SET_M2_IN1_PWM_DUTY(Speed);
        }
        if (Dir == Backward_CCW)
        {
            SET_M2_IN1_PWM_DUTY(0);
            SET_M2_IN2_PWM_DUTY(Speed);
        }
        break;
    default:
        // Motor ID Error
        break;
    }
}

void Motor_Set_Pos(uint8_t Angle, Motor_Dir Dir, uint8_t MotorID)
{
    MotorID -= 1;
    switch (MotorID)
    {
    case 0:
        /* code */
        break;
    
    default:
        break;
    }
}