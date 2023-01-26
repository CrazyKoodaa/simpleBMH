/*
 * i2c.c
 *
 *  Created on: 19 Jan 2023
 *      Author: Meder, Benjamin
 */

#include "i2c.h"

i2cStart *currentI2cDevice = NULL;
i2cStart TrainerTemperature01;
i2cStart PreasureDevice01;

uint8_t iDevice = 0;

typedef enum
{
	info,
	warning,
	error
} logLevel;

void goToFileI2C(void)
{
	//TrainerTemperature01.id = 99;
	//osMessageQueueNew(myQueue1LeftHandle, &temp, 0U);

	/* Initiating I2C Stuff */
//	uint16_t temp = 72;


	// Init Temperature Modul on the I"C BUS TRAINER
	I2CInit(&hi2c1, &TrainerTemperature01, TEMPERATURE01_I2C_ADDRESS, 0);
	I2CInit(&hi2c1, &PreasureDevice01, PRESSURE01_I2C_ADDRESS, 1);

	/* Infinite loop */
	for(;;)
	{
		switch (iDevice)
		{
		case 0:
			i2c_ReadTemperatur(&TrainerTemperature01);
			if (osMessageQueuePut(myQueue1LeftHandle, &TrainerTemperature01.result, 0U, 0U) != osOK)	osMessageQueueReset(myQueue1LeftHandle);

			myDebug("Queue Left Put:", TrainerTemperature01.result, 0);
		    myDebug((uint8_t*)"Queue Items Count ->    PUT    -> ", osMessageQueueGetCount(myQueue1LeftHandle), info);
			break;
		case 1:
			i2c_ReadPressure(&PreasureDevice01);
			if (osMessageQueuePut(myQueue1MiddleHandle, &PreasureDevice01.result, 0U, 0U) != osOK)	osMessageQueueReset(myQueue1MiddleHandle);
			myDebug("Queue Middle Put:", PreasureDevice01.result, 0);
			break;
		default:
			currentI2cDevice = NULL;
		}

		if (++iDevice > 1)
			iDevice = 0;

		osDelay(10);
	}
}

uint8_t I2CInit(I2C_HandleTypeDef *i2cHandle, i2cStart *i2cDevice, uint8_t i2cAddress, uint8_t id)
{
	uint8_t status = 0;

	/* Store interface parameters in struct */
	i2cDevice->id				= id;
	i2cDevice->i2cHandle 		= i2cHandle;
	i2cDevice->address			= i2cAddress;

	/* Clear DMA flags */
	i2cDevice->readingTemp = 0;

	switch (id)
	{
	case 0:
		/* Configure INIT Temperature Chip  */
		status += i2c_WriteTempRegister(i2cDevice, TEMPERATURE01_ACC_CONF, TEMPERATURE01_ACC_CONF_CONTINUOUS);

		/* Configure INIT Temperature Settings */
		status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TH, TEMPERATURE01_ACC_TH_UPPER, TEMPERATURE01_ACC_TH_LOWER);
		status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TL, TEMPERATURE01_ACC_TL_UPPER, TEMPERATURE01_ACC_TL_LOWER);
		status += i2c_WriteTempRegister2(i2cDevice, TEMPERATURE01_ACC_TL, TEMPERATURE01_ACC_TL_UPPER, TEMPERATURE01_ACC_TL_LOWER);
		status += i2c_WriteTempCmd(i2cDevice, TEMPERATURE01_CMD_START_CONVERT);
		break;
	case 1:
		status += i2c_WriteTempCmd(i2cDevice, PRESSURE01_CMD_START);
		break;

	default:
		break;
	}


	return status;
}

uint8_t i2c_ReadTemperatur(i2cStart *i2cDevice)
{
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{
		//status = (HAL_I2C_Mem_Read_DMA(i2cDevice->i2cHandle, i2cDevice->address, TEMPERATURE01_CMD_READ_TEMP, TEMPERATURE01_CMD_READ_TEMP_TX_SIZE, i2cDevice->rxBuf, TEMPERATURE01_CMD_READ_TEMP_RX_SIZE ) != HAL_OK);
		status = HAL_I2C_Mem_Read(i2cDevice->i2cHandle, i2cDevice->address, TEMPERATURE01_CMD_READ_TEMP, TEMPERATURE01_CMD_READ_TEMP_TX_SIZE, i2cDevice->rxBuf, TEMPERATURE01_CMD_READ_TEMP_RX_SIZE, 1000 );
		osSemaphoreRelease(myBinarySemI2CHandle);
		i2c_ReadTemperatur_Complete(i2cDevice);
	}
	return status;

}

uint8_t i2c_ReadPressure(i2cStart *i2cDevice)
{
	uint8_t status;
	if( osSemaphoreAcquire( myBinarySemI2CHandle, 0xffff ) == osOK )
	{
		status = HAL_I2C_Mem_Read(i2cDevice->i2cHandle, i2cDevice->address, 0x78, 0x01,  i2cDevice->rxBuf, 2, 1000);
		osSemaphoreRelease(myBinarySemI2CHandle);
		i2c_ReadPreasure_Complete (i2cDevice);
	}
	return status;

}

void i2c_ReadTemperatur_Complete(i2cStart *i2cDevice) // removed here for future Development with DMA or IT
{

//	i2cDevice->readingTemp = 0;
	i2cDevice->result = i2cDevice->rxBuf[0];// + (structTemperature->rxBuf[1] & 0x80) == 1 ? 0.5 : 0;
	//DMA_I2C_POINTER = NULL;

}

void i2c_ReadPreasure_Complete (i2cStart *i2cDevice)  // removed here for future Development with DMA or IT
{
	i2cDevice->tempResult = ((i2cDevice->rxBuf[0]) << 8 | i2cDevice->rxBuf[1]) & 0x7FFF;
	i2cDevice->result = i2cDevice->tempResult * (2.5) / 0x7FFF;
}


//void i2cStartAllocateMemory(i2cStart *i2cDevice)
//{
////	i2cStart *result = malloc(sizeof result);
//
//	i2cDevice = (i2cStart*)malloc(sizeof(i2cStart));
//
////	return *result;
//}

//uint8_t getInformation(i2cStart *i2cDevice)
//{
//	uint8_t status = 0;
//
//	// checking Trainer Board with I2C and Temperature DS1621
//
//	uint16_t results = currentI2cDevice->result;
//	if (osMessageQueuePut(myQueue1LeftHandle, &results, 0U, 200U) != osOK)
//	{
//		osMessageQueueReset(myQueue1LeftHandle);
//	}
//
//	return status;
//}

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
	osDelay(30);
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
	osDelay(30);
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
	osDelay(30);
	return status;

}

