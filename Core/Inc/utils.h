/*
 * utils.h
 *
 *  Created on: Jan 15, 2023
 *      Author: Meder, Benjamin
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "main.h"
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "cmsis_os2.h"
#include "stdio.h"
#include "i2c.h"

#define TRUE								1
#define FALSE								0
#define TXBUFFERSIZE                     	(COUNTOF(aTxBuffer) - 1)



typedef enum
{
	PRESSUREFC,
	CURRENTMOTOR,
	CURRENTBATTERIE,
	CURRENTFC,
	VOLTAGEFC,
	VOLTAGECENTRAL,
} i2cDevice;

typedef enum
{
	info,
	warning,
	error
} logLevel;


extern osSemaphoreId_t myBinarySemUARTHandle;
extern osSemaphoreId_t myBinarySemI2CHandle;
extern UART_HandleTypeDef huart3;
extern i2cStart *currentI2cDevice;


/* Variables for UART */
extern __IO ITStatus UartReady;// = RESET;
extern uint8_t aTxBuffer[250];// = {0};


double getI2CData(i2cDevice device);
void myDebug(uint8_t * message, uint16_t number, logLevel status);
void strrev(char *arr, int start, int end);
char *itoa(int number, char *arr, int base);
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);

#endif /* INC_UTILS_H_ */
