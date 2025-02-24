/*
    motor.h
    Created on Feb 10, 2025
    Author: @POEG1726
*/

#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "main.h"

typedef enum
{
    Forward_CW,
    Backward_CCW
} Motor_Dir;

void Motor_Enable(void);
void Motor_Break(uint8_t MotorID);
void Motor_Set_Velo(uint8_t Speed, Motor_Dir Dir, uint8_t MotorID);

#endif // _MOTOR_H_