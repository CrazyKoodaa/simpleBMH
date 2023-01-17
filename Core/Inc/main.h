/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define voltageMonitor24V_Pin GPIO_PIN_14
#define voltageMonitor24V_GPIO_Port GPIOG
#define tankPressureSensor_Pin GPIO_PIN_4
#define tankPressureSensor_GPIO_Port GPIOB
#define buttonOff_Pin GPIO_PIN_15
#define buttonOff_GPIO_Port GPIOA
#define voltageMonitor12V_Pin GPIO_PIN_13
#define voltageMonitor12V_GPIO_Port GPIOG
#define MCU_ACTIVE_Pin GPIO_PIN_12
#define MCU_ACTIVE_GPIO_Port GPIOG
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOD
#define FCEntry_Pin GPIO_PIN_3
#define FCEntry_GPIO_Port GPIOD
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOK
#define DCDCEnable_Pin GPIO_PIN_9
#define DCDCEnable_GPIO_Port GPIOG
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOD
#define tankGasSensor_Pin GPIO_PIN_8
#define tankGasSensor_GPIO_Port GPIOA
#define tankValve_Pin GPIO_PIN_6
#define tankValve_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOG
#define buttonOn_Pin GPIO_PIN_13
#define buttonOn_GPIO_Port GPIOB
#define lightIndicator_Pin GPIO_PIN_12
#define lightIndicator_GPIO_Port GPIOB
#define uSDDetect_Pin GPIO_PIN_2
#define uSDDetect_GPIO_Port GPIOG
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOA
#define VSYNC_FREQ_Pin GPIO_PIN_2
#define VSYNC_FREQ_GPIO_Port GPIOA
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOA
#define FSChortCircuit_Pin GPIO_PIN_6
#define FSChortCircuit_GPIO_Port GPIOH
#define FCExit_Pin GPIO_PIN_14
#define FCExit_GPIO_Port GPIOB
#define FCOutput_Pin GPIO_PIN_15
#define FCOutput_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
