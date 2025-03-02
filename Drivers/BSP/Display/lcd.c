#include "lcd.h"
#include "spi.h"
#include "st7735.h"
#include "font.h"
#include <stdio.h>

#define LCD_TIMEOUT 100
#define LCD_SPI_HANDLER (hspi2)
#define LCD_CS(x)   do{ x ? HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);}while(0)
#define LCD_DC(x)  do{ x ? HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);}while(0)
#define LCD_RES(x)  do{ x ? HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_RESET);}while(0)
#define LCD_BLK(x)  do{ x ? HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET);}while(0)

static int32_t s_LCD_WriteReg(uint8_t reg, uint8_t * pdata, uint32_t length);
static int32_t s_LCD_ReadReg(uint8_t reg, uint8_t * pdata);
static int32_t s_LCD_Send(uint8_t * pdata, uint32_t length);
static int32_t s_LCD_Recv(uint8_t * pdata, uint32_t length);
static int32_t s_LCD_GetTick(void);
static int32_t s_LCD_Init(void);

ST7735_IO_t LCD_IO = {
    s_LCD_Init,
    NULL,
    NULL,
    s_LCD_WriteReg,
    s_LCD_ReadReg,
    s_LCD_Send,
    s_LCD_Recv,
    s_LCD_GetTick
};

ST7735_Object_t LCD_Obj;
uint32_t LCD_id;

static int32_t s_LCD_WriteReg(uint8_t reg, uint8_t * pdata, uint32_t length)
{
    LCD_CS(0);
    LCD_DC(0);
    HAL_SPI_Transmit(&LCD_SPI_HANDLER, &reg, 1, LCD_TIMEOUT);

    if (length > 0)
    {
        LCD_DC(1);
        HAL_SPI_Transmit(&LCD_SPI_HANDLER, pdata, length, LCD_TIMEOUT);
    }
    LCD_CS(1);
    return ST7735_OK;
}

static int32_t s_LCD_ReadReg(uint8_t reg, uint8_t* pdata)
{
    // HAL_SPI_Receive
    return ST7735_OK;
}

static int32_t s_LCD_Send(uint8_t* pdata, uint32_t length)
{
    LCD_CS(0);
    LCD_DC(1);
    HAL_SPI_Transmit(&LCD_SPI_HANDLER, pdata, length, LCD_TIMEOUT);
    LCD_CS(1);
    return ST7735_OK;
}

static int32_t s_LCD_Recv(uint8_t* pdata, uint32_t length)
{
    LCD_CS(0);
    HAL_SPI_Receive(&LCD_SPI_HANDLER, pdata, length, LCD_TIMEOUT);
    LCD_CS(1);
    return ST7735_OK;
}

static int32_t s_LCD_GetTick()
{
    return HAL_GetTick();
}

static int32_t s_LCD_Init(void)
{
    LCD_RES(0);
    HAL_Delay(20);
    LCD_RES(1);
    HAL_Delay(20);
    LCD_BLK(1);
    return ST7735_OK;
}

void LCD_Init()
{
    ST7735_RegisterBusIO(&LCD_Obj, &LCD_IO);
    ST7735_Init(&LCD_Obj, ST7735_FORMAT_RBG565, ST7735_ORIENTATION_LANDSCAPE);
}

void LCD_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor)
{
    if (x >= ST7735_WIDTH || y >= ST7735_HEIGHT) return;

    uint8_t char_width, char_height;
    if (size == 12)
    {
        char_width = 6;
        char_height = 12;
    }
    else if (size == 16)
    {
        char_width = 8;
        char_height = 16;
    }

    uint8_t eff_width = (x + char_width > ST7735_WIDTH) ? (ST7735_WIDTH - x) : char_width;
    uint8_t eff_height = (y + char_height > ST7735_HEIGHT) ? (ST7735_HEIGHT - y) : char_height;

    if (chr < ' ' || chr > '~') return;
    uint8_t index = chr - ' ';

    if (mode == 0) // 非叠加模式：构建完整缓冲区（背景和字体）
    {
        uint16_t buffer[eff_height * eff_width];
        for (uint8_t i = 0; i < eff_height; i++)
        {
            uint8_t rowData;
            if (size == 12)
                rowData = font_12[index][i];
            else
                rowData = font_16[index][i];
            for (uint8_t j = 0; j < eff_width; j++)
            {
                if ((rowData << j) & 0x80)
                    buffer[i * eff_width + j] = color;
                else
                    buffer[i * eff_width + j] = bgColor;
            }
        }
        ST7735_FillRGBRect(&LCD_Obj, x, y, (uint8_t*)buffer, eff_width, eff_height);
    }
    else
    {
        for (uint8_t i = 0; i < eff_height; i++)
        {
            uint8_t rowData;
            if (size == 12)
                rowData = font_12[index][i];
            else
                rowData = font_16[index][i];
            for (uint8_t j = 0; j < eff_width; j++)
            {
                if ((rowData << j) & 0x80)
                {
                    ST7735_SetPixel(&LCD_Obj, x + j, y + i, color);
                }
            }
        }
    }
}

void LCD_ShowString(uint8_t x, uint8_t y, const char* str, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor)
{
    while (*str)
    {
        LCD_ShowChar(x, y, *str, size, mode, color, bgColor);
        if (size == 12)
            x += 6;  // 6×12 字符宽度
        else
            x += 8;  // 8×16 字符宽度
        str++;
    }
}

void LCD_ShowInt(uint8_t x, uint8_t y, int num, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor, uint8_t showSign)
{
    char buf[16];
    if (showSign)
    {
        if (num >= 0)
            sprintf(buf, "+%d", num);
        else
            sprintf(buf, "%d", num);
    }
    else
    {
        sprintf(buf, "%d", num);
    }
    LCD_ShowString(x, y, buf, size, mode, color, bgColor);
}

void LCD_ShowFloat(uint8_t x, uint8_t y, float num, uint8_t size, uint8_t mode, uint16_t color, uint16_t bgColor, uint8_t showSign)
{
    char buf[16];
    if (showSign)
    {
        if (num >= 0) sprintf(buf, "+%.2f", num);
        else sprintf(buf, "%.2f", num);
    }
    else sprintf(buf, "%.2f", num);
    LCD_ShowString(x, y, buf, size, mode, color, bgColor);
}

void LCD_Area_Clear(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t bgColor)
{
    ST7735_FillRect(&LCD_Obj, x, y, width, height, bgColor);
}

void LCD_Clear(uint16_t bgColor)
{
    ST7735_FillRect(&LCD_Obj, 0, 0, ST7735_WIDTH, ST7735_HEIGHT, bgColor);
}