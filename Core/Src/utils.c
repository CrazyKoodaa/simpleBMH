/*
 * utils.c
 *
 *  Created on: Jan 15, 2023
 *      Author: Meder, Benjamin
 */

#include "utils.h"

//double getI2CData(i2cDevice device);
//
//
void myDebug(uint8_t * message, logLevel status)
{
	uint8_t aTxBuffer[250];

	if (osSemaphoreAcquire(myBinarySemUARTHandle, 1000) == osOK)
	{

		HAL_Delay(500);
		switch (status)
		{
		case 0:
			sprintf((char*)aTxBuffer, "INFO: **** %s ****\r\n ", message);
			break;
		case 1:
			sprintf((char*)aTxBuffer, "WARNING: **************** %s ****\r\n ", message);
			break;
		case 2:
			sprintf((char*)aTxBuffer, "ERROR: ********************************* %s ****\r\n ", message);
			break;
		default:
			sprintf((char*)aTxBuffer, "INFO: **** %s ****\r\n ", message);
			break;
		}
//		if(HAL_UART_Transmit(&huart3, (uint8_t*)aTxBuffer, TXBUFFERSIZE, 1000) != HAL_OK) Error_Handler();
	}

	osSemaphoreRelease(myBinarySemUARTHandle);


//	char * tempText;

}
