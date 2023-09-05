/*
 * USART.h
 *
 *  Created on: 9 Ağu 2023
 *      Author: yigit
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f401re.h"

#define USART_MODE_TX                 ((uint32_t)(0x00000008))
#define USART_MODE_RX                 ((uint32_t)(0x00000008))
#define USART_MODE_TX_RX              ((uint32_t)(0x0000000C))

#define USART_WORDLENGTH_8BITS        ((uint32_t)(0x00000000))
#define USART_WORDLENGTH_9BITS        ((uint32_t)(0x00001000))

#define USART_PARITY_NONE             ((uint32_t)(0x00000000))
#define USART_PARITY_EVEN             ((uint32_t)(0x00000400))
#define USART_PARITY_ODD              ((uint32_t)(0x00000600))

#define USART_STOPBITS_1              ((uint32_t)(0x00000000))
#define USART_STOPBITS_HALF           ((uint32_t)(0x00001000))
#define USART_STOPBITS_2              ((uint32_t)(0x00002000))
#define USART_STOPBITS_1_HALF         ((uint32_t)(0x00003000))

#define USART_OVERSAMPLE_16           ((uint32_t)(0x00000000))
#define USART_OVERSAMPLE_8            ((uint32_t)(0x00008000))

#define USART_HW_NONE                 ((uint32_t)(0x00000000))
#define USART_HW_CTS                  ((uint32_t)(0x00000200))
#define USART_HW_RTS                  ((uint32_t)(0x00000100))
#define USART_HW_CTS_RTS              ((uint32_t)(0x00000300))


#define __USART_OVERSAMPLING_8(__PCLOCK__, __BAUDRATE__)         (25U * (uint32_t)(__PCLOCK__)) / (2U * (uint32_t)(__BAUDRATE__))

#define __USART_OVERSAMPLING_16(__PCLOCK__, __BAUDRATE__)        (25U * (uint32_t)(__PCLOCK__)) / (4U * (uint32_t)(__BAUDRATE__))


typedef enum{
	USART_FLAG_RESET=0,
	USART_FLAG_SET
}USART_FlagStatus;

typedef struct{

	uint32_t BaudRate;
	uint32_t OverSampling;
	uint32_t WordLength;
	uint32_t Parity;
	uint32_t StopBits;
	uint32_t HardWareFlowControl;
	uint32_t Mode;

}USART_InitTypedef;

typedef struct{
	USART_Typedef *Instance;
	USART_InitTypedef Init;
}USART_HandlerTypedef;

void USART_Init(USART_HandlerTypedef *USART_Handle);

void USART_TransmitData(USART_HandlerTypedef *USART_Handle, uint8_t *pData, uint16_t sizeofData);

void USART_ReceiveData(USART_HandlerTypedef *USART_Handle, uint8_t *pBuffer, uint16_t sizeofData);

void USART_PeriphState(USART_HandlerTypedef *USART_Handle, FunctionalState USARTstate);

USART_FlagStatus USART_GetFlagStatus(USART_HandlerTypedef *USART_Handle, uint16_t flagName);

#endif /* INC_USART_H_ */
