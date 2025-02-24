#include "eeprom.h"
#include "i2c.h"

#define EEPROM_I2C_HANDLER (hi2c3)
#define EEPROM_ADDR 0xA0
#define EEPROM_MEM_SIZE 8192 // 64 Kbits
#define EEPROM_PAGE_SIZE 32
#define EEPROM_I2C_TIMEOUT 100

/**
 * @brief  Checks if the EEPROM is functioning correctly.
 * @retval 0 if EEPROM is functioning correctly, 1 otherwise.
 */
uint8_t EEPROM_Check(void)
{
    uint8_t read_data = 0x00;
    uint16_t test_address = 0x0000;

    EEPROM_ReadByte(test_address, &read_data);

    if (read_data != 0xAA)
    {
        EEPROM_WriteByte(test_address, 0xAA);
        HAL_Delay(5);

        EEPROM_ReadByte(test_address, &read_data);
        if (read_data != 0xAA) return 1;
    }

    return 0;
}

/**
 * @brief  Writes a single byte to the EEPROM.
 * @param  addr: The address to write the byte to.
 * @param  byte: The byte to write.
 * @retval None
 */
void EEPROM_WriteByte(uint16_t addr, uint8_t byte)
{
    HAL_I2C_Mem_Write(&EEPROM_I2C_HANDLER, EEPROM_ADDR, addr, I2C_MEMADD_SIZE_16BIT, &byte, 1, EEPROM_I2C_TIMEOUT);
    HAL_Delay(5); // Wait for the write cycle to complete
}

/**
 * @brief  Writes a page of data to the EEPROM.
 * @param  addr: The starting address to write the page to.
 * @param  buffer: Pointer to the data buffer to write.
 * @retval None
 */
void EEPROM_WritePage(uint16_t addr, uint8_t* buffer)
{
    HAL_I2C_Mem_Write(&EEPROM_I2C_HANDLER, EEPROM_ADDR, addr, I2C_MEMADD_SIZE_16BIT, buffer, EEPROM_PAGE_SIZE, EEPROM_I2C_TIMEOUT);
    HAL_Delay(5); // Wait for the write cycle to complete
}

/**
 * @brief  Writes a buffer of data to the EEPROM.
 * @param  addr: The starting address to write the buffer to.
 * @param  buffer: Pointer to the data buffer to write.
 * @param  buffer_size: The size of the data buffer.
 * @retval None
 */
void EEPROM_WriteBuffer(uint16_t addr, uint8_t* buffer, uint16_t buffer_size)
{
    uint16_t remaining = buffer_size;
    uint16_t current_addr = addr;
    uint8_t* current_buffer = buffer;

    while (remaining > 0)
    {
        uint16_t chunk_size = (remaining > EEPROM_PAGE_SIZE) ? EEPROM_PAGE_SIZE : remaining;
        EEPROM_WritePage(current_addr, current_buffer);
        current_addr += chunk_size;
        current_buffer += chunk_size;
        remaining -= chunk_size;
    }
}

/**
 * @brief  Reads a single byte from the EEPROM.
 * @param  addr: The address to read the byte from.
 * @param  byte: Pointer to the variable to store the read byte.
 * @retval None
 */
void EEPROM_ReadByte(uint16_t addr, uint8_t* byte)
{
    HAL_I2C_Mem_Read(&EEPROM_I2C_HANDLER, EEPROM_ADDR, addr, I2C_MEMADD_SIZE_16BIT, byte, 1, EEPROM_I2C_TIMEOUT);
}

/**
 * @brief  Reads a buffer of data from the EEPROM.
 * @param  addr: The starting address to read the buffer from.
 * @param  buffer: Pointer to the data buffer to store the read data.
 * @param  buffer_size: The size of the data buffer.
 * @retval None
 */
void EEPROM_ReadBuffer(uint16_t addr, uint8_t* buffer, uint16_t buffer_size)
{
    HAL_I2C_Mem_Read(&EEPROM_I2C_HANDLER, EEPROM_ADDR, addr, I2C_MEMADD_SIZE_16BIT, buffer, buffer_size, EEPROM_I2C_TIMEOUT);
}
