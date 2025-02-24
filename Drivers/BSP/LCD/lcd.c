#include "lcd.h"
#include "spi.h"

#define LCD_SPI_HANDLER (hspi1)

#define LCD_CS(x)      do{ x ? HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);}while(0)
#define LCD_RES(x)      do{ x ? HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_RESET);}while(0)

