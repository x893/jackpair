/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MXCONSTANT_H
#define __MXCONSTANT_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define USART_TX_Pin		GPIO_PIN_2
#define USART_TX_GPIO_Port	GPIOA
#define USART_RX_Pin		GPIO_PIN_3
#define USART_RX_GPIO_Port	GPIOA
#define TMS_Pin				GPIO_PIN_13
#define TMS_GPIO_Port		GPIOA
#define TCK_Pin				GPIO_PIN_14
#define TCK_GPIO_Port		GPIOA
/* USER CODE BEGIN Private defines */

#define USART_TX_PIN		GPIOA, GPIO_PIN_2
#define USART_RX_PIN		GPIOA, GPIO_PIN_3

#define FIRST(a,b)			a
#define SECOND(a,b)			b
#define PIN(a)				SECOND(a)
#define PORT(a)				FIRST(a)

#define KEY_0_PIN			GPIOC, GPIO_PIN_7
#define KEY_1_PIN			GPIOB, GPIO_PIN_2
#define KEY_2_PIN			GPIOA, GPIO_PIN_8
#define KEY_3_PIN			GPIOB, GPIO_PIN_15
#define KEY_4_PIN			GPIOB, GPIO_PIN_4
#define KEY_5_PIN			GPIOB, GPIO_PIN_13
#define KEY_6_PIN			GPIOB, GPIO_PIN_3
#define KEY_7_PIN			GPIOC, GPIO_PIN_4

#define KEY_G0_0			GPIOA, GPIO_PIN_9
#define KEY_G0_1			GPIOB, GPIO_PIN_5

#define KEY_G1_0			GPIOA, GPIO_PIN_10
#define KEY_G1_1			GPIOB, GPIO_PIN_10

#define KEY_G2_0			GPIOB, GPIO_PIN_1
#define KEY_G2_1			GPIOB, GPIO_PIN_14

#define TX_LED_PIN			GPIOA, GPIO_PIN_7
#define TX_LED_GND_PIN		GPIOB, GPIO_PIN_6

#define RX_LED_PIN			GPIOB, GPIO_PIN_9
#define RX_LED_GND_PIN		GPIOB, GPIO_PIN_8

#define MIC_PIN				GPIOA, GPIO_PIN_0
#define LINE_IN_PIN			GPIOA, GPIO_PIN_1
#define BAT_PIN				GPIOC, GPIO_PIN_0
#define SPEAKER_PIN			GPIOA, GPIO_PIN_4
#define LINE_OUT_PIN		GPIOA, GPIO_PIN_5

#define BUTTON_PIN			GPIOC, GPIO_PIN_13
#define PSK_PIN				GPIOC, GPIO_PIN_8
#define PSK_GND_PIN			GPIOC, GPIO_PIN_9
#define ANTIVAD_PIN			GPIOC, GPIO_PIN_6
#define PTT_PIN				GPIOA, GPIO_PIN_11
#define PTT_GND_PIN			GPIOA, GPIO_PIN_6

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MXCONSTANT_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
