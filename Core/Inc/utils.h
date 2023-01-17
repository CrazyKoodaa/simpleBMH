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

double getI2CData(i2cDevice device);
void myDebug(uint8_t * message, logLevel status);


#endif /* INC_UTILS_H_ */
