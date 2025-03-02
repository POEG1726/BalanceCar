#include "oled.h"
#include <math.h>
#include "i2c.h"
#include "font.h"

#define OLED_ADDR 0x78
#define OLED_I2CTimeout 100
#define OLED_I2CHANDLER (hi2c3)

uint8_t OLED_RAM[4][128];

void OLED_SendData(uint8_t* data, uint8_t dataLen)
{
    HAL_I2C_Mem_Write(&OLED_I2CHANDLER, OLED_ADDR, 0x40, I2C_MEMADD_SIZE_8BIT, data, dataLen, OLED_I2CTimeout);
}

void OLED_SendCommand(uint8_t cmd)
{
    HAL_I2C_Mem_Write(&OLED_I2CHANDLER, OLED_ADDR, 0x00, I2C_MEMADD_SIZE_8BIT, &cmd, 1, OLED_I2CTimeout);
}

void OLED_Init(void)
{
    HAL_Delay(200);
    OLED_SendCommand(0xAE); /*display off*/
    OLED_SendCommand(0x00); /*set lower column address*/
    OLED_SendCommand(0x10); /*set higher column address*/
    OLED_SendCommand(0x00); /*set display start line*/
    OLED_SendCommand(0xB0); /*set page address*/
    OLED_SendCommand(0x81); /*contract control*/
    OLED_SendCommand(0xff); /*128*/
    OLED_SendCommand(0xA1); /*set segment remap*/
    OLED_SendCommand(0xA6); /*normal / reverse*/
    OLED_SendCommand(0xA8); /*multiplex ratio*/
    OLED_SendCommand(0x3F); /*duty = 1/32*/
    OLED_SendCommand(0xC8); /*Com scan direction*/
    OLED_SendCommand(0xD3); /*set display offset*/
    OLED_SendCommand(0x00);
    OLED_SendCommand(0xD5); /*set osc division*/
    OLED_SendCommand(0x80);
    OLED_SendCommand(0xD9); /*set pre-charge period*/
    OLED_SendCommand(0x1f);
    OLED_SendCommand(0xDA); /*set COM pins*/
    OLED_SendCommand(0x00);
    OLED_SendCommand(0xdb); /*set vcomh*/
    OLED_SendCommand(0x40);
    OLED_SendCommand(0x8d); /*set charge pump enable*/
    OLED_SendCommand(0x14);
    OLED_Clear();
    OLED_SendCommand(0xAF);
}

void OLED_DisPlay_On(void)
{
    OLED_SendCommand(0x8D);
    OLED_SendCommand(0x14);
    OLED_SendCommand(0xAF);
}

void OLED_DisPlay_Off(void)
{
    OLED_SendCommand(0x8D);
    OLED_SendCommand(0x10);
    OLED_SendCommand(0xAE);
}

void OLED_SetCursor(uint8_t XValue, uint8_t Page)
{
    OLED_SendCommand(0xB0 | Page);
    OLED_SendCommand(0x10 | (XValue & 0xF0 >> 4));
    OLED_SendCommand(0x00 | (XValue & 0x0F));
}

void OLED_Clear(void)
{
    for (uint8_t i = 0; i < 4;i++)
    {
        for (uint8_t j = 0;j < 128;j++)
            OLED_RAM[i][j] = 0x00;
    }
}

void OLED_ClearArea(uint8_t XValue, uint8_t YValue, uint8_t Width, uint8_t Height)
{
    for (uint8_t i = YValue; i < YValue + Height; i++)
        for (uint8_t j = XValue; j < XValue + Width; j++)
            OLED_RAM[i / 8][j] &= ~(0x01 << (i % 8));
}

void OLED_Refresh(void)
{
    for (uint8_t i = 0; i < 4;i++)
    {
        OLED_SetCursor(0, i);
        OLED_SendData(OLED_RAM[i], 128);
    }
}

void OLED_RefreshArea(uint8_t XValue, uint8_t YValue, uint8_t Width, uint8_t Height)
{
    uint8_t Page, Page1;
    Page = YValue / 8;
    Page1 = (YValue + Height - 1) / 8 + 1;
    for (uint8_t i = Page; i < Page1; i++)
    {
        OLED_SetCursor(XValue, i);
        OLED_SendData(&OLED_RAM[i][XValue], Width);
    }
}

void OLED_Reverse(void)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t j = 0; j < 128; j++)
        {
            OLED_RAM[i][j] ^= 0xFF;
        }
    }
}

void OLED_ReverseArea(uint8_t XValue, uint8_t YValue, uint8_t Width, uint8_t Height)
{
    for (uint8_t i = YValue; i < YValue + Height; i++)
    {
        for (uint8_t j = XValue; j < XValue + Width; j++)
        {
            OLED_RAM[i / 4][j] ^= 0x01 << (i % 4);
            // if (j >= 0 && j <= 127 && i >= 0 && i <= 63)
            // {
            //     OLED_RAM[i / 8][j] ^= 0x01 << (i % 8);
            // }
        }
    }
}

void OLED_ShowChar(uint8_t XValue, uint8_t YValue, char data)
{
    OLED_ShowImage(XValue, YValue, 6, 8, font_12[data - ' ']);
}

void OLED_ShowString(uint8_t XValue, uint8_t YValue, char* str)
{
    for (uint8_t i = 0; str[i] != '\0'; i++)
    {
        OLED_ShowChar(XValue + i * 6, YValue, str[i]);
    }
}

uint32_t OLED_Pow(uint8_t X, uint8_t Y)
{
    uint32_t Result = 1;
    while (Y--)
    {
        Result *= X;
    }
    return Result;
}

uint8_t OLED_GetIntLen(uint32_t Number)
{
    return (int)log10(Number) + 1;
}

void OLED_ShowNum(uint8_t X, uint8_t Y, uint32_t Number)
{
    uint8_t Length = OLED_GetIntLen(Number);
    for (uint8_t i = 0; i < Length; i++)
        OLED_ShowChar(X + i * 6, Y, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
}

void OLED_ShowFloat(uint8_t X, uint8_t Y, float Number, uint8_t IntLength, uint8_t FraLength, uint8_t ShowSign)
{
    uint32_t PowNum, IntNum, FraNum;

    if (Number >= 0)
        if (ShowSign == 1) OLED_ShowChar(X, Y, '+');else {}
    else
    {
        if (ShowSign == 1) OLED_ShowChar(X, Y, '-');
        Number = -Number;
    }

    IntNum = Number;
    Number -= IntNum;
    PowNum = OLED_Pow(10, FraLength);
    FraNum = round(Number * PowNum);
    IntNum += FraNum / PowNum;

    if (ShowSign == 0)
    {
        OLED_ShowNum(X, Y, IntNum);
        OLED_ShowChar(X + (IntLength) * 6, Y, '.');
        OLED_ShowNum(X + (IntLength + 1) * 6, Y, FraNum);
    }
    else
    {
        OLED_ShowNum(X + 6, Y, IntNum);
        OLED_ShowChar(X + (IntLength + 1) * 6, Y, '.');
        OLED_ShowNum(X + (IntLength + 2) * 6, Y, FraNum);
    }
}

void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t* Image)
{
    uint8_t Page, Shift;
    OLED_ClearArea(X, Y, Width, Height);
    for (uint8_t i = 0; i < (Height - 1) / 8 + 1; i++)
        for (uint8_t j = 0; j < Width; j++)
            if (X + j >= 0 && X + j <= 127)
            {
                Page = Y / 8;
                Shift = Y % 8;
                if (Page + i >= 0 && Page + i <= 3)
                    OLED_RAM[Page + i][X + j] |= Image[i * Width + j] << (Shift);

                if (Page + i + 1 >= 0 && Page + i + 1 <= 3)
                    OLED_RAM[Page + i + 1][X + j] |= Image[i * Width + j] >> (8 - Shift);
            }
}