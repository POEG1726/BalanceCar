/*
    ina226.h
    Created on Feb 10, 2025
    Author: @POEG1726
*/

#ifndef _INA226_H_
#define _INA226_H_

#include "main.h"

uint8_t INA226_Check(void);
void INA226_Init(void);
void INA226_ReadBusVoltage(float* voltage);
void INA226_ReadCurrent(float* current);
void INA226_ReadPower(float* power);

#endif // _INA226_H_