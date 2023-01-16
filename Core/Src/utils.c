/*
 * utils.c
 *
 *  Created on: Jan 15, 2023
 *      Author: Meder, Benjamin
 */


//double getI2CData(i2cDevice device);
//
//
//void myDebug(message, status)
//{
//	uint8_t aTxBuffer[250];
//
//	if( xSemaphoreTake( myBinarySemUARTHandle, ( TickType_t ) portMAX_DELAY ) == pdTRUE )
//	{
//
//		HAL_Delay(5000);
//		switch (logStatus)
//		{
//		case 0:
//			sprintf((char*)aTxBuffer, "INFO: **** %s ****\r\n ", message);
//			break;
//		case 1:
//			sprintf((char*)aTxBuffer, "WARNING: **************** %s ****\r\n ", message);
//			break;
//		case 2:
//			sprintf((char*)aTxBuffer, "ERROR: ********************************* %s ****\r\n ", message);
//			break;
//		default:
//			sprintf((char*)aTxBuffer, "INFO: **** %s ****\r\n ", message);
//			break;
//		}
//		if(HAL_UART_Transmit(&huart3, (uint8_t*)aTxBuffer, TXBUFFERSIZE, 1000) != HAL_OK) Error_Handler();
//	}
//
//	xSemaphoreGive(myBinarySemUART);
//
//	char * tempText;
//
//	switch (status){
//	case INFO:
//		break;
//	case WARNING:
//		break;
//	case ERROR:
//		break;
//	}


//}
