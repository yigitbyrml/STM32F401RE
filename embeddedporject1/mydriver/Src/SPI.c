/*
 * SPI.c
 *
 *  Created on: 27 Tem 2023
 *      Author: yigit
 */

#ifndef SRC_SPI_C_
#define SRC_SPI_C_

#include "SPI.h"

static void SPI_CloseISR_TX(SPI_HandlerTypedef *SPI_Handle){
	SPI_Handle->Instance->CR2 &= ~(0x1U << SPI_CR2_TXEIE);
	SPI_Handle->pDataAddr = NULL;
	SPI_Handle->TxDataSize=0;
	SPI_Handle->busStateTx = SPI_BUS_FREE;

}

static void SPI_CloseISR_RX(SPI_HandlerTypedef *SPI_Handle){
	SPI_Handle->Instance->CR2 &= ~(0x1U << SPI_CR2_RXNEIE);
	SPI_Handle->pRxDataAddr = NULL;
	SPI_Handle->RxDataSize=0;
	SPI_Handle->busStateRx = SPI_BUS_FREE;
}

static void SPI_TransmitHelper_16Bits(SPI_HandlerTypedef *SPI_Handle){

	SPI_Handle->Instance->DR = *((uint16_t *)(SPI_Handle->pDataAddr));
	SPI_Handle->pDataAddr += sizeof(uint16_t);
	SPI_Handle->TxDataSize -= 2;

	if(SPI_Handle->TxDataSize == 0){
		SPI_CloseISR_TX(SPI_Handle);
	}

}

static void SPI_TransmitHelper_8Bits(SPI_HandlerTypedef *SPI_Handle){

	SPI_Handle->Instance->DR = *((uint8_t *)(SPI_Handle->pDataAddr));
	SPI_Handle->pDataAddr += sizeof(uint8_t);
	SPI_Handle->TxDataSize --;

	if(SPI_Handle->TxDataSize == 0){
		SPI_CloseISR_TX(SPI_Handle);
	}

}

static void SPI_ReceiveHelper_16Bits(SPI_HandlerTypedef *SPI_Handle){

	*((uint16_t*)SPI_Handle->pRxDataAddr) = ( uint16_t)SPI_Handle->Instance->DR;
	SPI_Handle->pRxDataAddr += sizeof(uint16_t);
	SPI_Handle->RxDataSize-=2;

	if(SPI_Handle->RxDataSize == 0){
		SPI_CloseISR_RX(SPI_Handle);
	}

}

static void SPI_ReceiveHelper_8Bits(SPI_HandlerTypedef *SPI_Handle){

	*((uint8_t*)SPI_Handle->pRxDataAddr) = *((volatile uint8_t*)(&SPI_Handle->Instance->DR));
	SPI_Handle->pRxDataAddr += sizeof(uint8_t);
	SPI_Handle->RxDataSize--;

	if(SPI_Handle->RxDataSize == 0){
		SPI_CloseISR_RX(SPI_Handle);
	}

}

void SPI_Init(SPI_HandlerTypedef *SPI_Handle){
	uint32_t temp=0;
	temp = SPI_Handle->Instance->CR1;
	temp |= (SPI_Handle->Init.BaudRate) | (SPI_Handle->Init.Cpha) | (SPI_Handle->Init.Cpol) | (SPI_Handle->Init.DFF_Format)\
			| (SPI_Handle->Init.Mode) | (SPI_Handle->Init.Frame_Format) | (SPI_Handle->Init.BusConfig) | (SPI_Handle->Init.SSM_Cmd);
	SPI_Handle->Instance->CR1=temp;
}

void SPI_PeriphState(SPI_HandlerTypedef *SPI_Handle,FunctionalState SPIstate){
	if(SPIstate == ENABLE){
		SPI_Handle->Instance->CR1 |= (0x1 << SPI_CR1_SPE);
	}
	else{
		SPI_Handle->Instance->CR1 &= ~(0x1 << SPI_CR1_SPE);
	}
}

void SPI_TransmitData(SPI_HandlerTypedef *SPI_Handle,uint8_t *pData, uint16_t sizeofData){
	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS){
		while(sizeofData > 0){
			if((SPI_Handle->Instance->SR >> 1U) & 0x1U){ //SPI_GetFlagStatus(SPI_Handle, SPI_TxE_FLAG)
				SPI_Handle->Instance->DR = *((uint16_t*)pData);
				pData += sizeof(uint16_t);
				sizeofData -= 2;
			}
		}
	}
	else{
		while(sizeofData > 0){
			if((SPI_Handle->Instance->SR >> 1U) & 0x1U){
				SPI_Handle->Instance->DR = *pData;
				pData += sizeof(uint8_t);
				sizeofData--;
			}
		}

	}
	while(SPI_GetFlagStatus(SPI_Handle,SPI_BUSY_FLAG));
}

SPI_FlagStatus SPI_GetFlagStatus(SPI_HandlerTypedef *SPI_Handle, uint16_t SPI_Flag){

	return(SPI_Handle->Instance->SR & SPI_Flag) ? SPI_FLAG_SET : SPI_FLAG_RESET;
}

void SPI_ReceiveData(SPI_HandlerTypedef *SPI_Handle,uint8_t *pBuffer, uint16_t sizeofData){
	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS){
		while(sizeofData > 0){
			if(SPI_GetFlagStatus(SPI_Handle, SPI_RxNE_FLAG)){
				*((uint16_t *)(pBuffer)) = (uint16_t)SPI_Handle->Instance->DR;
				pBuffer += sizeof(uint16_t);
				sizeofData -= 2;
			}
		}
	}
	else{
		while(sizeofData > 0){
			if(SPI_GetFlagStatus(SPI_Handle, SPI_RxNE_FLAG)){
				*(pBuffer) = *((volatile uint8_t*)&SPI_Handle->Instance->DR);
				pBuffer += sizeof(uint8_t);
				sizeofData --;
			}
		}
	}
}

void SPI_TransmitData_Interrupt(SPI_HandlerTypedef *SPI_Handle,uint8_t *pData, uint16_t sizeofData){
	SPI_BusStatus busState=SPI_Handle->busStateTx;

	if(busState != SPI_BUS_BUSY_TX){
		SPI_Handle->pDataAddr=(uint8_t *)pData;
		SPI_Handle->TxDataSize=(uint16_t)sizeofData;

		SPI_Handle->busStateTx=SPI_BUS_BUSY_TX;

		if(SPI_Handle->Instance->CR1 & (0x1 << SPI_CR1_DFF)){
			SPI_Handle->TxISRFunction = SPI_TransmitHelper_16Bits;
		}
		else{
			SPI_Handle->TxISRFunction = SPI_TransmitHelper_8Bits;
		}

		SPI_Handle->Instance->CR2 |= (0x1U << SPI_CR2_TXEIE);
	}

}

void SPI_ReceiveData_Interrupt(SPI_HandlerTypedef *SPI_Handle,uint8_t *pBuffer, uint16_t sizeofData){
	SPI_BusStatus busState=SPI_Handle->busStateRx;

	if(busState != SPI_BUS_BUSY_RX){
		SPI_Handle->pRxDataAddr = (uint8_t*)(pBuffer);
		SPI_Handle->RxDataSize = (uint16_t)sizeofData;

		SPI_Handle->busStateRx = SPI_BUS_BUSY_RX;

		if(SPI_Handle->Instance->CR1 & (0x1 << SPI_CR1_DFF)){
			SPI_Handle->RxISRFunction = SPI_ReceiveHelper_16Bits;
		}
		else{
			SPI_Handle->RxISRFunction = SPI_ReceiveHelper_8Bits;
		}

		SPI_Handle->Instance->CR2 |= (0x1U << SPI_CR2_RXNEIE);
	}
}

void SPI_InterruptHandler(SPI_HandlerTypedef *SPI_Handle){
	uint8_t interruptSource=0;
	uint8_t interruptFlag=0;

	interruptSource = SPI_Handle->Instance->CR2 & (0x1U << SPI_CR2_TXEIE);
	interruptFlag = SPI_Handle->Instance->SR & (0x1U << SPI_SR_TxE);

	if((interruptSource != 0) && (interruptFlag != 0)){
		SPI_Handle->TxISRFunction(SPI_Handle);
	}

	interruptSource = SPI_Handle->Instance->CR2 & (0x1U << SPI_CR2_RXNEIE);
	interruptFlag = SPI_Handle->Instance->SR & (0x1U << SPI_SR_RxNE);

	if((interruptSource != 0) && (interruptFlag != 0)){
		SPI_Handle->RxISRFunction(SPI_Handle);
	}
}

#endif /* SRC_SPI_C_ */
