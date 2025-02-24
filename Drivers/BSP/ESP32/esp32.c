#include "esp32.h"
#define ESP32_UARTHandle (&huart3)
#define ESP32_UART_TIMEOUT 500

void ESP32_Receive(uint8_t* data, uint16_t len)
{
    HAL_UART_Receive(ESP32_UARTHandle, data, len, ESP32_UART_TIMEOUT);
}

void ESP32_Send(uint8_t* data, uint16_t len)
{
    HAL_UART_Transmit(ESP32_UARTHandle, data, len, ESP32_UART_TIMEOUT);
}
