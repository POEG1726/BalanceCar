#include "icm42688p.h"
#include "i2c.h"
#include "esp32.h"

#define ICM42688_ADDR  0xD0
#define ICM42688_I2CHandle (hi2c3)
#define REG_BANK_SEL  0x76
#define ICM42688_TIMEOUT 500

/* User Register Bank0 */
#define REG_DEVICE_CONFIG 0x11
#define REG_TEMP_DATA_1 0x1d
#define REG_TEMP_DATA_0 0x1e
#define REG_ACCEL_DATA_X1  0x1f
#define REG_ACCEL_DATA_X0  0x20
#define REG_ACCEL_DATA_Y1  0x21
#define REG_ACCEL_DATA_Y0  0x22
#define REG_ACCEL_DATA_Z1  0x23
#define REG_ACCEL_DATA_Z0  0x24
#define REG_GYRO_DATA_X1  0x25
#define REG_GYRO_DATA_X0  0x26
#define REG_GYRO_DATA_Y1  0x27
#define REG_GYRO_DATA_Y0  0x28
#define REG_GYRO_DATA_Z1  0x29
#define REG_GYRO_DATA_Z0  0x2A
#define REG_INTF_CONFIG1  0x4D
#define REG_PWR_MGMT0  0x4E
#define REG_GYRO_CONFIG0  0x4F
#define REG_ACCEL_CONFIG0  0x50
#define REG_WHO_AM_I  0x75

static float icm42688_acc_inv = 1, icm42688_gyro_inv = 1;

static void ICM42688_WriteReg(uint8_t reg, uint8_t val)
{
    HAL_I2C_Mem_Write(&ICM42688_I2CHandle, ICM42688_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &val, 1, ICM42688_TIMEOUT);
}

static void ICM42688_ReadReg(uint8_t reg, uint8_t* val)
{
    HAL_I2C_Mem_Read(&ICM42688_I2CHandle, ICM42688_ADDR, reg, I2C_MEMADD_SIZE_8BIT, val, 1, ICM42688_TIMEOUT);
}

static void ICM42688_ReadMultiReg(uint8_t reg, uint8_t* val, uint16_t len)
{
    HAL_I2C_Mem_Read(&ICM42688_I2CHandle, ICM42688_ADDR, reg, I2C_MEMADD_SIZE_8BIT, val, len, ICM42688_TIMEOUT);
}

static void ICM42688_RegBankSelect(uint8_t RegBank)
{
    switch (RegBank)
    {
    case 0:
        ICM42688_WriteReg(REG_BANK_SEL, 0x0);
    case 1:
        ICM42688_WriteReg(REG_BANK_SEL, 0x1);
    case 2:
        ICM42688_WriteReg(REG_BANK_SEL, 0x2);
    case 4:
        ICM42688_WriteReg(REG_BANK_SEL, 0x4);
    default:
        break;
    }
}

void ICM42688_Init(enum icm42688_afs afs, enum icm42688_aodr aodr, enum icm42688_gfs gfs, enum icm42688_godr godr)
{
    uint8_t DeviceID = 0x00;
    ICM42688_RegBankSelect(0);
    ICM42688_ReadReg(REG_WHO_AM_I, &DeviceID);
    if (DeviceID != 0x47)
    {
        ESP32_Send("ICM42688: Device ID Error", 25);
        return;
    }
    ICM42688_WriteReg(REG_DEVICE_CONFIG, 0x01); //software reset
    HAL_Delay(10);
    ICM42688_WriteReg(REG_PWR_MGMT0, 0x00); //power on
    HAL_Delay(1);

    // Set Accelerometer
    ICM42688_WriteReg(REG_ACCEL_CONFIG0, (afs << 5) | (aodr + 1));
    // Set Gyroscope
    ICM42688_WriteReg(REG_GYRO_CONFIG0, (gfs << 5) | (godr + 1));
    ICM42688_ReadReg(REG_PWR_MGMT0, 0x0f); // Set Gyro and Accel to Low Noise Mode
    HAL_Delay(1);

    switch (afs)
    {
    case ICM42688_AFS_2G:
        icm42688_acc_inv = 2000 / 32768.0f;             // Accel scale:±2g
        break;
    case ICM42688_AFS_4G:
        icm42688_acc_inv = 4000 / 32768.0f;             // Accel scale:±4g
        break;
    case ICM42688_AFS_8G:
        icm42688_acc_inv = 8000 / 32768.0f;             // Accel scale:±8g
        break;
    case ICM42688_AFS_16G:
        icm42688_acc_inv = 16000 / 32768.0f;            // Accel scale:±16g
        break;
    default:
        icm42688_acc_inv = 1;                           // No conversion
        break;
    }
    switch (gfs)
    {
    case ICM42688_GFS_15_625DPS:
        icm42688_gyro_inv = 15.625f / 32768.0f;         // Gyro scale:±15.625dps
        break;
    case ICM42688_GFS_31_25DPS:
        icm42688_gyro_inv = 31.25f / 32768.0f;          // Gyro scale:±31.25dps
        break;
    case ICM42688_GFS_62_5DPS:
        icm42688_gyro_inv = 62.5f / 32768.0f;           // Gyro scale:±62.5dps
        break;
    case ICM42688_GFS_125DPS:
        icm42688_gyro_inv = 125.0f / 32768.0f;          // Gyro scale:±125dps
        break;
    case ICM42688_GFS_250DPS:
        icm42688_gyro_inv = 250.0f / 32768.0f;          // Gyro scale:±250dps
        break;
    case ICM42688_GFS_500DPS:
        icm42688_gyro_inv = 500.0f / 32768.0f;          // Gyro scale:±500dps
        break;
    case ICM42688_GFS_1000DPS:
        icm42688_gyro_inv = 1000.0f / 32768.0f;         // Gyro scale:±1000dps
        break;
    case ICM42688_GFS_2000DPS:
        icm42688_gyro_inv = 2000.0f / 32768.0f;         // Gyro scale:±2000dps
        break;
    default:
        icm42688_gyro_inv = 1;                          // No conversion
        break;
    }
}

void ICM42688_ReadData(ICM42688_Data_t* Data)
{
    uint8_t DataBuffer[6] = { 0 }, TempBuffer[2] = { 0 };
    ICM42688_RegBankSelect(0);
    // Read Temperature     Temp = (TEMP_DATA / 132.48) + 25
    ICM42688_ReadMultiReg(REG_TEMP_DATA_1, TempBuffer, 2);
    Data->Temperature = ((DataBuffer[0] << 8) | DataBuffer[1]) / 132.48 + 25;

    // Read Accel Data
    ICM42688_ReadMultiReg(REG_ACCEL_DATA_X1, DataBuffer[0], 6);
    Data->accel_x = (DataBuffer[0] << 8) | DataBuffer[1];
    Data->accel_y = (DataBuffer[2] << 8) | DataBuffer[3];
    Data->accel_z = (DataBuffer[4] << 8) | DataBuffer[5];

    // Read Gyro Data
    ICM42688_ReadMultiReg(REG_GYRO_DATA_X1, DataBuffer[0], 6);
    Data->gyro_x = (DataBuffer[0] << 8) | DataBuffer[1];
    Data->gyro_y = (DataBuffer[2] << 8) | DataBuffer[3];
    Data->gyro_z = (DataBuffer[4] << 8) | DataBuffer[5];
}