/*
 * i2c.h
 *
 *  Created on: 19 Jan 2023
 *      Author: Meder, Benjamin
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

/* Private define ------------------------------------------------------------*/
// Values for the I2C Trainer -> Temperature DS1621 Adr. 5
// #define TTEMP_I2C_ADDRESS				0x4D // 7bit Version
#define TEMPERATURE01_I2C_ADDRESS				0x9A // 8bit Version anď last bit is getting set through macro
#define TEMPERATURE01_ACC_CONF					0xAC
#define TEMPERATURE01_ACC_CONF_CONTINUOUS		0x02
#define TEMPERATURE01_ACC_TH					0xA1	// max. high Temperature
#define TEMPERATURE01_ACC_TH_UPPER				0x28   	// +40°C
#define TEMPERATURE01_ACC_TH_LOWER				0x28   	// +40°C
#define TEMPERATURE01_ACC_TL					0xA2	// min. lowest Temperature
#define TEMPERATURE01_ACC_TL_UPPER				0x0A	// +10°C
#define TEMPERATURE01_ACC_TL_LOWER				0x00	// +10°C

#define TEMPERATURE01_CMD_START_CONVERT			0xEE
#define TEMPERATURE01_CMD_READ_TEMP				0xAA
#define TEMPERATURE01_CMD_READ_TEMP_TX_SIZE		0x01
#define TEMPERATURE01_CMD_READ_TEMP_RX_SIZE		0x02
#define TEMPERATURE01_CMD_STOP_CONVERT			0x22

#define TEMPERATURE01_CMD_READ_COUNTER			0xA8
#define TEMPERATURE01_CMD_READ_SLOPE			0xA9
/* Private includes ----------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal_i2c.h"
#include "cmsis_os2.h"
#include "stdlib.h"
#include "stdint.h"

/* Private variables ---------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	/* I2C */
	uint8_t id;
	I2C_HandleTypeDef *i2cHandle;
	uint8_t address;

	/* different Buffers */
	uint8_t tempRxBuffer[2];
	uint8_t rxBuf[2];

	uint8_t tempTxBuffer_0[1];
	uint8_t tempTxBuffer_1[1];
	uint8_t tempTxBuffer_2[1];
	uint8_t tempTxBuffer_3[1];

	uint8_t irq;
	uint8_t readingTemp;

	/* result */
	uint16_t result;

} i2cStart;

/* Private variables ---------------------------------------------------------*/
extern osSemaphoreId_t myBinarySemI2CHandle;
extern I2C_HandleTypeDef hi2c1;


extern i2cStart *currentI2cDevice;
extern i2cStart TrainerTemperature01;



/* Private function prototypes -----------------------------------------------*/
void goToFileI2C(void);

/* INITIALISATION */
uint8_t temperature_Init(I2C_HandleTypeDef *i2cHandle, i2cStart *i2cDevice, uint8_t i2cAddress, uint8_t id);
void i2cStartAllocateMemory(i2cStart *i2cDevice);

uint8_t getInformation(i2cStart *i2cDevice);

/* LOW-LEVEL REGISTER FUNCTIONS */
uint8_t i2c_WriteTempRegister(i2cStart *i2cDevice, uint8_t regAddr, uint8_t data0);
uint8_t i2c_WriteTempRegister2(i2cStart *i2cDevice, uint8_t regAddr, uint8_t data0, uint8_t data1);
uint8_t i2c_WriteTempCmd(i2cStart *i2cDevice, uint8_t cmd);

/* DMA */
uint8_t i2c_ReadTemperaturDMA(i2cStart *i2cDevice);
void i2c_ReadTemperaturDMA_Complete(i2cStart *i2cDevice);

#endif /* INC_I2C_H_ */
