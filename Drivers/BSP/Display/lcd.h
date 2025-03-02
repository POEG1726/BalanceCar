/*
    lcd.h
    Created on Feb 10, 2025
    Author: @POEG1726
*/

#ifndef _LCD_H_
#define _LCD_H_

#include "main.h"

#define SPI_LCD
// #define I2C_LCD

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40
#define BRRED 			 0XFC07
#define GRAY  			 0X8430
#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458
#define BG_COLOR         BLACK

void LCD_Init(void);
void LCD_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor);
void LCD_ShowString(uint8_t x, uint8_t y, const char* str, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor);
void LCD_ShowInt(uint8_t x, uint8_t y, int num, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor, uint8_t showSign);
void LCD_ShowFloat(uint8_t x, uint8_t y, float num, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor, uint8_t showSign);
void LCD_Area_Clear(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t bgColor);
void LCD_Clear(uint16_t bgColor);


#endif // _LCD_H_