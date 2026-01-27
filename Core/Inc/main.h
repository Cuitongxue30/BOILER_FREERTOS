/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define UP_RELAY_Pin GPIO_PIN_3
#define UP_RELAY_GPIO_Port GPIOE
#define DOWN_RELAY_Pin GPIO_PIN_5
#define DOWN_RELAY_GPIO_Port GPIOE
#define LOOP_KEY_Pin GPIO_PIN_13
#define LOOP_KEY_GPIO_Port GPIOC
#define SEBLOW_KEY_Pin GPIO_PIN_9
#define SEBLOW_KEY_GPIO_Port GPIOI
#define OUT_TEMP_ADC_Pin GPIO_PIN_0
#define OUT_TEMP_ADC_GPIO_Port GPIOC
#define IN_TEMP_ADC_Pin GPIO_PIN_1
#define IN_TEMP_ADC_GPIO_Port GPIOC
#define DESLAG_KEY_Pin GPIO_PIN_0
#define DESLAG_KEY_GPIO_Port GPIOA
#define FIRE_TEMP_ADC_Pin GPIO_PIN_1
#define FIRE_TEMP_ADC_GPIO_Port GPIOA
#define CTRL_USART2_TX_Pin GPIO_PIN_2
#define CTRL_USART2_TX_GPIO_Port GPIOA
#define BEEP_Pin GPIO_PIN_4
#define BEEP_GPIO_Port GPIOH
#define CTRL_USART2_RX_Pin GPIO_PIN_3
#define CTRL_USART2_RX_GPIO_Port GPIOA
#define GRATE_TEMP_ADC_Pin GPIO_PIN_5
#define GRATE_TEMP_ADC_GPIO_Port GPIOA
#define SE_PRESS_ADC_Pin GPIO_PIN_6
#define SE_PRESS_ADC_GPIO_Port GPIOA
#define LOOP_RELAY_Pin GPIO_PIN_7
#define LOOP_RELAY_GPIO_Port GPIOA
#define GRATE_PRESS_ADC_Pin GPIO_PIN_4
#define GRATE_PRESS_ADC_GPIO_Port GPIOC
#define FUME_TEMP_ADC_Pin GPIO_PIN_5
#define FUME_TEMP_ADC_GPIO_Port GPIOC
#define SEBLOW_RELAY_Pin GPIO_PIN_0
#define SEBLOW_RELAY_GPIO_Port GPIOB
#define BLOW_SPEED_ADC_Pin GPIO_PIN_1
#define BLOW_SPEED_ADC_GPIO_Port GPIOB
#define BLOW_USART3_TX_Pin GPIO_PIN_10
#define BLOW_USART3_TX_GPIO_Port GPIOB
#define BLOW_USART3_RX_Pin GPIO_PIN_11
#define BLOW_USART3_RX_GPIO_Port GPIOB
#define FIRE_KEY_Pin GPIO_PIN_8
#define FIRE_KEY_GPIO_Port GPIOH
#define GRATE_KEY_Pin GPIO_PIN_12
#define GRATE_KEY_GPIO_Port GPIOB
#define MODE_KEY_Pin GPIO_PIN_13
#define MODE_KEY_GPIO_Port GPIOD
#define BUMP_KEY_Pin GPIO_PIN_3
#define BUMP_KEY_GPIO_Port GPIOG
#define DTU_USART6_TX_Pin GPIO_PIN_6
#define DTU_USART6_TX_GPIO_Port GPIOC
#define DTU_USART6_RX_Pin GPIO_PIN_7
#define DTU_USART6_RX_GPIO_Port GPIOC
#define TJC_USART1_TX_Pin GPIO_PIN_9
#define TJC_USART1_TX_GPIO_Port GPIOA
#define TJC_USART1_RX_Pin GPIO_PIN_10
#define TJC_USART1_RX_GPIO_Port GPIOA
#define CTRL_KEY_Pin GPIO_PIN_14
#define CTRL_KEY_GPIO_Port GPIOH
#define DOWN_KEY_Pin GPIO_PIN_0
#define DOWN_KEY_GPIO_Port GPIOI
#define INDUCE_UART4_TX_Pin GPIO_PIN_10
#define INDUCE_UART4_TX_GPIO_Port GPIOC
#define INDUCE_UART4_RX_Pin GPIO_PIN_11
#define INDUCE_UART4_RX_GPIO_Port GPIOC
#define SEBLOW_UART5_TX_Pin GPIO_PIN_12
#define SEBLOW_UART5_TX_GPIO_Port GPIOC
#define SEBLOW_UART5_RX_Pin GPIO_PIN_2
#define SEBLOW_UART5_RX_GPIO_Port GPIOD
#define BLOW_RELAY_Pin GPIO_PIN_3
#define BLOW_RELAY_GPIO_Port GPIOD
#define INDUCE_KEY_Pin GPIO_PIN_4
#define INDUCE_KEY_GPIO_Port GPIOD
#define GRATE_RELAY_Pin GPIO_PIN_5
#define GRATE_RELAY_GPIO_Port GPIOD
#define FIRE_RELAY_Pin GPIO_PIN_9
#define FIRE_RELAY_GPIO_Port GPIOG
#define CTRL_RELAY_Pin GPIO_PIN_11
#define CTRL_RELAY_GPIO_Port GPIOG
#define BLOW_KEY_Pin GPIO_PIN_12
#define BLOW_KEY_GPIO_Port GPIOG
#define UP_KEY_Pin GPIO_PIN_6
#define UP_KEY_GPIO_Port GPIOB
#define AT24CXX_SCL_Pin GPIO_PIN_8
#define AT24CXX_SCL_GPIO_Port GPIOB
#define AT24CXX_SDA_Pin GPIO_PIN_9
#define AT24CXX_SDA_GPIO_Port GPIOB
#define INDUCE_REALY_Pin GPIO_PIN_4
#define INDUCE_REALY_GPIO_Port GPIOI
#define BUMP_RELAY_Pin GPIO_PIN_5
#define BUMP_RELAY_GPIO_Port GPIOI
#define DESALG_RELAY_Pin GPIO_PIN_7
#define DESALG_RELAY_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
