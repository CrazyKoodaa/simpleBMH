/*
 * i2c.c
 *
 *  Created on: 19 Jan 2023
 *      Author: Meder, Benjamin
 */

#include "i2c.h"

i2cStart *currentI2cDevice = NULL;
i2cStart TrainerTemperature01;



void goToFileI2C(void)
{

	/* Initiating I2C Stuff */
	TrainerTemperature01.id = 99;
	currentI2cDevice = &TrainerTemperature01;

	temperature_Init(&hi2c1, currentI2cDevice, TEMPERATURE01_I2C_ADDRESS, 0);

	/* Infinite loop */
	for(;;)
	{
		getInformation(currentI2cDevice);
		osDelay(1000);
	}
}

uint8_t temperature_Init(I2C_HandleTypeDef *i2cHandle, i2cStart *i2cDevice, uint8_t i2cAddress, uint8_t id)
{
	/* Allocate Memory */
//	i2cStartAllocateMemory(&i2cDevice);
//    if (NULL != *i2cDevice)
//        free(*i2cDevice);
	uint8_t status = 0;
    //i2cStartAllocateMemory(i2cDevice);


	/* Store interface parameters in struct */
	i2cDevice->id				= id;
	i2cDevice->i2cHandle 		= i2cHandle;
	i2cDevice->address			= i2cAddress;


	/* Clear DMA flags */
	i2cDevice->readingTemp = 0;

	/* Configure Temperature Chip  */
			status += i2c_WriteTempRegister(i2cDevice, TEMPERATURE01_ACC_CONF, TEMPERATURE01_ACC_CONF_CONTINUOUS);
			osDelay(30);

			/* Configure Temperature Settings */
			status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TH, TEMPERATURE01_ACC_TH_UPPER, TEMPERATURE01_ACC_TH_LOWER);
			osDelay(30);

			status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TL, TEMPERATURE01_ACC_TL_UPPER, TEMPERATURE01_ACC_TL_LOWER);
			osDelay(30);

			status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TL, TEMPERATURE01_ACC_TL_UPPER, TEMPERATURE01_ACC_TL_LOWER);
			osDelay(30);

			status += i2c_WriteTempCmd(i2cDevice, TEMPERATURE01_CMD_START_CONVERT);
			osDelay(30);


	return status;
}

void i2cStartAllocateMemory(i2cStart *i2cDevice)
{
//	i2cStart *result = malloc(sizeof result);

	i2cDevice = (i2cStart*)malloc(sizeof(i2cStart));

//	return *result;
}

uint8_t getInformation(i2cStart *i2cDevice)
{
	uint8_t status = 0;

	// checking Trainer Board with I2C and Temperature DS1621
	i2c_ReadTemperaturDMA(i2cDevice);

	return status;
}

/*
 *
 * LOW-LEVEL REGISTER FUNCTIONS
 *
 */
uint8_t i2c_WriteTempRegister(i2cStart *i2cDevice, uint8_t regAddr, uint8_t data0)
{

	uint8_t txBuffer[1] = { data0 };
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{
		currentI2cDevice = i2cDevice;
		currentI2cDevice->irq = 0;
//		status = (HAL_I2C_Master_Transmit_DMA(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, 1) == HAL_OK);
		status = (HAL_I2C_Master_Transmit(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, 1, 1000) == HAL_OK);
		currentI2cDevice->irq = 1;
		while(currentI2cDevice->irq == 0);
		currentI2cDevice = NULL;
		osSemaphoreRelease(myBinarySemI2CHandle);
		//while (osSemaphoreRelease(myBinarySemI2CHandle) != osOK);
	}
	return status;
}

uint8_t i2c_WriteTempRegister2(i2cStart *i2cDevice, uint8_t regAddr, uint8_t data0, uint8_t data1)
{

	uint8_t txBuffer[2] = { data0, data1 };
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{
		currentI2cDevice = i2cDevice;
		currentI2cDevice->irq = 0;
//		status = (HAL_I2C_Master_Transmit_DMA(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, 2) == HAL_OK);
		status = (HAL_I2C_Master_Transmit(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, 2, 1000) == HAL_OK);
		currentI2cDevice->irq = 1;
		while(currentI2cDevice->irq == 0);
		osSemaphoreRelease(myBinarySemI2CHandle);
		currentI2cDevice = NULL;
		//while (osSemaphoreRelease(myBinarySemI2CHandle) != osOK);
	}
	return status;
}

uint8_t i2c_WriteTempCmd(i2cStart *i2cDevice, uint8_t cmd)
{
	uint8_t txBuffer[1] = { cmd };
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{
		currentI2cDevice = i2cDevice;
		currentI2cDevice->irq = 0;
//		status = (HAL_I2C_Master_Transmit_DMA(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, sizeof(txBuffer)) == HAL_OK);
		status = (HAL_I2C_Master_Transmit(i2cDevice->i2cHandle, i2cDevice->address, txBuffer, sizeof(txBuffer), 1000) == HAL_OK);
		currentI2cDevice->irq = 1;
		while(currentI2cDevice->irq == 0);
		osSemaphoreRelease(myBinarySemI2CHandle);
		//while (osSemaphoreRelease(myBinarySemI2CHandle) != osOK);
	}
	return status;

}

/* DMA */
uint8_t i2c_ReadTemperaturDMA(i2cStart *i2cDevice)
{

//	uint8_t txBuf[] = { TEMPERATURE01_CMD_READ_TEMP };
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{

		currentI2cDevice = i2cDevice;
		currentI2cDevice->irq = 0;
		//status = (HAL_I2C_Mem_Read_DMA(i2cDevice->i2cHandle, i2cDevice->address, TEMPERATURE01_CMD_READ_TEMP, TEMPERATURE01_CMD_READ_TEMP_TX_SIZE, i2cDevice->rxBuf, TEMPERATURE01_CMD_READ_TEMP_RX_SIZE ) != HAL_OK);
		status = HAL_I2C_Mem_Read(i2cDevice->i2cHandle, i2cDevice->address, TEMPERATURE01_CMD_READ_TEMP, TEMPERATURE01_CMD_READ_TEMP_TX_SIZE, i2cDevice->rxBuf, TEMPERATURE01_CMD_READ_TEMP_RX_SIZE, 1000 );
		currentI2cDevice->irq = 1;
		while(currentI2cDevice->irq == 0);
		osSemaphoreRelease(myBinarySemI2CHandle);
		i2c_ReadTemperaturDMA_Complete(i2cDevice);
		//if currentI2cDevice->readingTemp = 1;
		//while (osSemaphoreRelease(myBinarySemI2CHandle) != osOK);
	}
	return status;

}

void i2c_ReadTemperaturDMA_Complete(i2cStart *i2cDevice)
{

//	i2cDevice->readingTemp = 0;
	i2cDevice->result = i2cDevice->rxBuf[0];// + (structTemperature->rxBuf[1] & 0x80) == 1 ? 0.5 : 0;
	//DMA_I2C_POINTER = NULL;

}


