#include "ina226.h"
#include "i2c.h"

#define ina226_I2C_HANDLER (hi2c3)
#define ina226_ADDR 0x80 //0x40 << 1
#define ina226_Timeout 100

#define REG_CONFIG 0x00
#define REG_SHUNT_VOLTAGE 0x01
#define REG_BUS_VOLTAGE 0x02   
#define REG_POWER 0x03   
#define REG_CURRENT 0x04   
#define REG_CALIBRATION 0x05   
#define REG_MASK 0x06   
#define REG_ALERT 0x07
#define REG_MANUFACTURE_ID 0xFE

#define INA226_MAX_CURRENT 4.0f
#define INA226_CURRENT_LSB (INA226_MAX_CURRENT / 32768.0f)
#define INA226_SHUNT_RESISTANCE 0.001f

/**
 * @brief  Writes data to a specified INA226 register.
 * @param  reg: Register address.
 * @param  data: Data to be written.
 */
static void INA226_WriteReg(uint8_t reg, uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = (data >> 8) & 0xFF;
    buffer[1] = data & 0xFF;

    HAL_I2C_Mem_Write(&ina226_I2C_HANDLER, ina226_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buffer, 2, ina226_Timeout);
}

/**
 * @brief  Reads data from a specified INA226 register.
 * @param  reg: Register address.
 * @param  data: Pointer to store the read data.
 */
static void INA226_ReadReg(uint8_t reg, uint16_t* data)
{
    uint8_t buffer[2];

    HAL_I2C_Mem_Read(&ina226_I2C_HANDLER, ina226_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buffer, 2, ina226_Timeout);
    *data= (buffer[0] << 8) | buffer[1];
}

/**
 * @brief  Checks if the INA226 device is connected and functioning.
 * @retval 1 if the device is functioning, 0 otherwise.
 */
uint8_t INA226_Check()
{
    uint16_t ManufactureID = 0x00;
    INA226_ReadReg(REG_MANUFACTURE_ID, &ManufactureID);
    if (ManufactureID != 0x5449)
    {
        // ESP32_Send("INA226: Device ID Error", 25);
        return 0;
    }
    return 1;
}

/**
 * @brief  Initializes the INA226 device with default configuration.
 */
void INA226_Init()
{
    uint16_t config = 0x4527;
    INA226_WriteReg(REG_CONFIG, config); //Collect 16 samples to average, 1.1ms conversion time, shunt and bus voltage continuous conversion

    uint16_t calibration = (uint16_t)(0.00512f / (INA226_CURRENT_LSB * INA226_SHUNT_RESISTANCE));
    INA226_WriteReg(REG_CALIBRATION, calibration);
}

/**
 * @brief  Gets the bus voltage from the INA226 device.
 * @param  voltage: Pointer to store the bus voltage.
 */
void INA226_GetBusVoltage(uint16_t* voltage)
{
    INA226_ReadReg(REG_BUS_VOLTAGE, voltage);
}

/**
 * @brief  Gets the current from the INA226 device.
 * @param  current: Pointer to store the current.
 */
void INA226_GetCurrent(uint16_t* current)
{
    INA226_ReadReg(REG_CURRENT, current);
}

/**
 * @brief  Gets the power from the INA226 device.
 * @param  power: Pointer to store the power.
 */
void INA226_GetPower(uint16_t* power)
{
    INA226_ReadReg(REG_POWER, power);
}