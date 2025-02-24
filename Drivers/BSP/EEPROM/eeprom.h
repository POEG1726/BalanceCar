/*
    eeprom.h
    Created on Feb 06, 2025
    Author: @POEG1726
*/
// EEPROM used in this file: M24C64

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "main.h"

uint8_t EEPROM_Check(void);
void EEPROM_WriteByte(uint16_t addr, uint8_t byte);
void EEPROM_ReadByte(uint16_t addr, uint8_t* byte);
void EEPROM_WritePage(uint16_t addr, uint8_t* buffer);
void EEPROM_WriteBuffer(uint16_t addr, uint8_t* buffer, uint16_t buffer_size);
void EEPROM_ReadBuffer(uint16_t addr, uint8_t* buffer, uint16_t buffer_size);

#endif // _EEPROM_H_
