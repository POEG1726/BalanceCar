/*
    esp32.h
    Created on Feb 09, 2025 
    Author: @POEG1726
*/

#ifndef _ESP32_H_
#define _ESP32_H_

#include "main.h"
#include "usart.h"

void ESP32_Send(uint8_t* data, uint16_t len);
void ESP32_Receive(uint8_t* data, uint16_t len);

#endif // _ESP32_H_
