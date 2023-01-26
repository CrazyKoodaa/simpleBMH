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
void myDebug(uint8_t * message, uint16_t number, logLevel status)
{
	uint8_t aTxBuffer[250];

	if (osSemaphoreAcquire(myBinarySemUARTHandle, 1000) == osOK)
	{

		HAL_Delay(500);
		uint8_t length = 0;
		switch (status)
		{
		case 0:
			sprintf((char*)aTxBuffer, "INFO: **** %s %d ****\r\n ", message, number);

			break;
		case 1:
			sprintf((char*)aTxBuffer, "WARNING: **************** %s %d ****\r\n ", message, number);
			break;
		case 2:
			sprintf((char*)aTxBuffer, "ERROR: ********************************* %s %d ****\r\n ", message, number);
			break;
		default:
			sprintf((char*)aTxBuffer, "INFO: **** %s %d ****\r\n ", message, number);
			break;
		}
		for (int i = 0; i < sizeof(aTxBuffer); i++)
		{
			if (aTxBuffer[i] == '\0')
			{
				length = i - 1;
				break;
			}

		}
		if(HAL_UART_Transmit(&huart3, (uint8_t*)aTxBuffer, length, 1000) != HAL_OK) Error_Handler();
	}

	osSemaphoreRelease(myBinarySemUARTHandle);


//	char * tempText;

}


char *itoa(int number, char *arr, int base)
{
    int i = 0, r, negative = 0;

    if (number == 0)
    {
        arr[i] = '0';
        arr[i + 1] = '\0';
        return arr;
    }

    if (number < 0 && base == 10)
    {
        number *= -1;
        negative = 1;
    }

    while (number != 0)
    {
        r = number % base;
        arr[i] = (r > 9) ? (r - 10) + 'a' : r + '0';
        i++;
        number /= base;
    }

    if (negative)
    {
        arr[i] = '-';
        i++;
    }

    strrev(arr, 0, i - 1);

    arr[i] = '\0';

    return arr;
}

void strrev(char *arr, int start, int end)
{
    char temp;

    if (start >= end)
        return;

    temp = *(arr + start);
    *(arr + start) = *(arr + end);
    *(arr + end) = temp;

    start++;
    end--;
    strrev(arr, start, end);
}




void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if (hi2c->Instance == I2C1 )
	{

		currentI2cDevice->irq = 1;
		osSemaphoreRelease(myBinarySemI2CHandle);
//		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//		xSemaphoreGiveFromISR(I2C_Mutex, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
//		portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
//		if (structTemperature.readingTemp)
			//TTemp_ReadTemperaturDMA_Complete(&structTemperature);
	}
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if (hi2c->Instance == I2C1 )
	{
		currentI2cDevice->irq = 1;
		osSemaphoreRelease(myBinarySemI2CHandle);
//		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//		xSemaphoreGiveFromISR(I2C_Mutex, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
//		portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
//		if (structTemperature.readingTemp)
			//i2c_ReadTemperaturDMA_Complete(&structTemperature);

	}
}

/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle.
  * @note   This example shows a simple way to report end of DMA Tx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
//	/* Set transmission flag: transfer complete*/
//	UartReady = SET;
	UartReady = RESET;
	osSemaphoreRelease(myBinarySemUARTHandle);
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//	xSemaphoreGiveFromISR(UART_Sem, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
//	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
	/* Turn LED1 on: Transfer in transmission process is correct */
	//  BSP_LED_On(LED1);
}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	/* Set transmission flag: transfer complete*/
	UartReady = SET;
	osSemaphoreRelease(myBinarySemUARTHandle);
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//	xSemaphoreGiveFromISR(UART_Sem, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
//	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
	/* Turn LED3 on: Transfer in reception process is correct */
	//  BSP_LED_On(LED3);

}

/**
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *UartHandle)
{
	/* Turn LED4 on: Transfer error in reception/transmission process */
	//  BSP_LED_On(LED4);	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//	xSemaphoreGiveFromISR(UART_Mutex, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
//	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
	osSemaphoreRelease(myBinarySemUARTHandle);
}


