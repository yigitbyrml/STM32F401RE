/*
 * USART.c
 *
 *  Created on: 9 Ağu 2023
 *      Author: yigit
 */

#ifndef SRC_USART_C_
#define SRC_USART_C_

#include "USART.h"

void USART_Init(USART_HandlerTypedef *USART_Handle){

	uint32_t periphClock = 0;
	uint32_t mantissaPart = 0;
	uint32_t fractionPart = 0;
	uint32_t USART_DIV_Value = 0;
	uint32_t temp1 = 0;

	uint32_t temp = USART_Handle->Instance->CR1;
	temp |= (USART_Handle->Init.OverSampling) | (USART_Handle->Init.WordLength) | (USART_Handle->Init.Mode) | \
			(USART_Handle->Init.Parity);
	USART_Handle->Instance->CR1 = temp;

	temp = USART_Handle->Instance->CR2;
	temp &= ~(0x3U << USART_CR2_STOP);
	temp |= (USART_Handle->Init.StopBits);
	USART_Handle->Instance->CR2=temp;

	temp=USART_Handle->Instance->CR3;
	temp |= (USART_Handle->Init.HardWareFlowControl);
	USART_Handle->Instance->CR3=temp;

	if(USART_Handle->Instance == USART1 || USART_Handle->Instance == USART6){
		periphClock = RCC_GetPClock2();
	}
	else{
		periphClock = RCC_GetPClock1();
	}

	if(USART_Handle->Init.OverSampling == USART_OVERSAMPLE_8){

		USART_DIV_Value = __USART_OVERSAMPLING_8(periphClock,USART_Handle->Init.BaudRate);
		mantissaPart = (USART_DIV_Value /100U);
		fractionPart = (USART_DIV_Value) - (mantissaPart * 100U);

		fractionPart = ((((fractionPart * 8U) + 50U) / 100U) & (0x07U));
	}
	else{

		USART_DIV_Value = __USART_OVERSAMPLING_16(periphClock,USART_Handle->Init.BaudRate);
		mantissaPart = (USART_DIV_Value /100U);
		fractionPart = (USART_DIV_Value) - (mantissaPart * 100U);

		fractionPart = ((((fractionPart * 16U) + 50U) / 100U) & (0x07U));
	}

	temp1 |= (mantissaPart << 4U);
	temp1 |= (fractionPart << 0U);

	USART_Handle->Instance->BRR = temp1;
}

void USART_TransmitData(USART_HandlerTypedef *USART_Handle, uint8_t *pData, uint16_t sizeofData){

	uint16_t *data16Bits;

	if((USART_Handle->Init.WordLength == USART_WORDLENGTH_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE)){
		data16Bits = (uint16_t *)pData;
	}
	else{
		data16Bits = NULL;
	}

	while(sizeofData > 0){

		while( !(USART_GetFlagStatus(USART_Handle, USART_TxE_FLAG)) );

		if(data16Bits == NULL){
			USART_Handle->Instance->DR = (uint8_t)(*pData & 0xFFU);
			pData++;
			sizeofData--;

		}
		else{
			USART_Handle->Instance->DR = (uint16_t)(*data16Bits & (0x01FFU));
			data16Bits++;
			sizeofData -= 2;
		}
	}

	while(!(USART_GetFlagStatus(USART_Handle, USART_TC_FLAG)));
}

void USART_ReceiveData(USART_HandlerTypedef *USART_Handle, uint8_t *pBuffer, uint16_t sizeofData){

	uint16_t *p16BitsBuffer;
	uint8_t *p8BitsBuffer;

	if((USART_Handle->Init.WordLength == USART_WORDLENGTH_9BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE)){

		p16BitsBuffer = (uint16_t *)pBuffer;
		p8BitsBuffer = NULL;
	}
	else{

		p8BitsBuffer = (uint8_t *)pBuffer;
		p16BitsBuffer = NULL;
	}

	while(sizeofData > 0){

		while(!(USART_GetFlagStatus(USART_Handle, USART_RxNE_FLAG)));

		if(p8BitsBuffer == NULL){
			*p16BitsBuffer = (uint16_t)(USART_Handle->Instance->DR & 0x1FFU);
			p16BitsBuffer++;
			sizeofData -= 2;
		}
		else{

			if((USART_Handle->Init.WordLength == USART_WORDLENGTH_9BITS) && (USART_Handle->Init.Parity != USART_PARITY_NONE)){
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
				p8BitsBuffer++;
				sizeofData--;
			}
			else if((USART_Handle->Init.WordLength == USART_WORDLENGTH_8BITS) && (USART_Handle->Init.Parity == USART_PARITY_NONE)){
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
				p8BitsBuffer++;
				sizeofData--;
			}
			else{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x007FU);
				p8BitsBuffer++;
				sizeofData--;
			}
		}
	}
}

void USART_PeriphState(USART_HandlerTypedef *USART_Handle, FunctionalState USARTstate){

	if(USARTstate == ENABLE){

		USART_Handle->Instance->CR1 |= (0x1U << USART_CR1_UE);
	}
	else{

		USART_Handle->Instance->CR1 &= ~(0x1U << USART_CR1_UE);
	}
}

USART_FlagStatus USART_GetFlagStatus(USART_HandlerTypedef *USART_Handle, uint16_t flagName){

	return(USART_Handle->Instance->SR & flagName) ? USART_FLAG_SET : USART_FLAG_RESET;
}



















#endif /* SRC_USART_C_ */
