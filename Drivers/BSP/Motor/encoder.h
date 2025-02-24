/*
    encoder.h
    Created on Feb 12, 2025 
    Author: @POEG1726
*/

#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "main.h"

void Encoder_Init(void);
void Read_Encoder(uint8_t MotorID, int32_t *EncoderValue);

#endif // _ENCODER_H_