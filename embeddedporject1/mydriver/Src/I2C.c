/*
 * I2C.c
 *
 *  Created on: 24 Ağu 2023
 *      Author: yigit
 */

#ifndef SRC_I2C_C_
#define SRC_I2C_C_

#include "I2C.h"

static void I2C_GenerateStartCondition(I2C_HandlerTypedef *I2C_Handle){
	I2C_Handle->Instance->CR1 |= (0x1U << I2C_CR1_START);
}

static void I2C_ExecuteAddressPhase(I2C_HandlerTypedef *I2C_Handle,uint8_t SlaveAddr){
	SlaveAddr = (SlaveAddr << 1U);
	SlaveAddr &= ~(1U);
	I2C_Handle->Instance->DR = SlaveAddr;
}

void I2C_ClearADDRFlag(I2C_HandlerTypedef *I2C_Handle){
	uint32_t dummyRead = I2C_Handle->Instance->SR1;
	dummyRead = I2C_Handle->Instance->SR2;
	(void)dummyRead;
}

static void I2C_GenerateStopCondition(I2C_HandlerTypedef *I2C_Handle){
	I2C_Handle->Instance->CR1 |= (0x1U << I2C_CR1_STOP);
}

void I2C_Init(I2C_HandlerTypedef *I2C_Handle){

	uint32_t pClockValue = 0x0U;
	pClockValue = RCC_GetPClock1();

	if(Check_PClock_Value(pClockValue,I2C_Handle->Init.ClockSpeed) != 1U){

		uint32_t temp = 0x0U;
		uint32_t freqValue = 0x0U;

		temp = I2C_Handle->Instance->CR1;
		temp |= (I2C_Handle->Init.ACKState) | (I2C_Handle->Init.ClockStretch);

		I2C_Handle->Instance->CR1 = temp;

		freqValue = I2C_Get_FreqValue(pClockValue);

		temp = I2C_Handle->Instance->CR2;
		temp |= (freqValue << 0U);

		I2C_Handle->Instance->CR2 = temp;

		temp = I2C_Handle->Instance->OAR1;

		temp |= I2C_Handle->Init.AddressingMode;

		if(I2C_Handle->Init.AddressingMode == I2C_ADDRMODE_7){
			temp |= (I2C_Handle->Init.MyOwnAddress << 1U);
		}
		else{
			temp |= (I2C_Handle->Init.MyOwnAddress << 0U);
		}

		I2C_Handle->Instance->OAR1 = temp;

		uint16_t ccr_value = 0;

		temp = I2C_Handle->Instance->CCR;

		if(I2C_Handle->Init.ClockSpeed <= I2C_SPEED_STANDART){

			ccr_value = (RCC_GetPClock1() / ( 2 * I2C_Handle->Init.ClockSpeed));
			temp |= (ccr_value & 0xFFF);
		}
		else{
			temp |= I2C_Handle->Init.DutyCycle;

			if(I2C_Handle->Init.DutyCycle == I2C_DUTY_FM_2){
				ccr_value = (RCC_GetPClock1() / ( 3 * I2C_Handle->Init.ClockSpeed));
			}
			else{
				ccr_value = (RCC_GetPClock1() / ( 25 * I2C_Handle->Init.ClockSpeed));
			}
			temp |= (ccr_value & 0xFFF);
		}
		I2C_Handle->Instance->CCR = temp;

		if(I2C_Handle->Init.ClockSpeed <= I2C_SPEED_STANDART){

			temp = (RCC_GetPClock1() / 1000000U) + 1;
		}
		else{
			temp = ((RCC_GetPClock1()*300) / 1000000000U) + 1;
		}

		I2C_Handle->Instance->TRISE = (temp & 0x3FU);
	}
}

void I2C_MasterTransmitData(I2C_HandlerTypedef *I2C_Handle, uint8_t *pData, uint32_t sizeofdata, uint8_t SlaveAddr){

	I2C_GenerateStartCondition(I2C_Handle);

	while(!(I2C_GetFlagStatus(I2C_Handle, I2C_SB_FLAG)));

	I2C_ExecuteAddressPhase(I2C_Handle,SlaveAddr);

	while(!(I2C_GetFlagStatus(I2C_Handle, I2C_ADDR_FLAG)));

	I2C_ClearADDRFlag(I2C_Handle);

	while(sizeofdata > 0){
		while(!(I2C_GetFlagStatus(I2C_Handle, I2C_TxE_FLAG)))
		I2C_Handle->Instance->DR = *pData;
		pData++;
		sizeofdata--;
	}

	while(!(I2C_GetFlagStatus(I2C_Handle, I2C_TxE_FLAG)));

	while(!(I2C_GetFlagStatus(I2C_Handle, I2C_BTF_FLAG)));

	I2C_GenerateStopCondition(I2C_Handle);
}

I2C_FlagStatus I2C_GetFlagStatus(I2C_HandlerTypedef *I2C_Handle, uint16_t I2C_Flag){

	return(I2C_Handle->Instance->SR1 & I2C_Flag) ? I2C_FLAG_SET : I2C_FLAG_RESET;
}

void I2C_PeriphState(I2C_HandlerTypedef *I2C_Handle, FunctionalState I2CState){

	if(I2CState == ENABLE){
		I2C_Handle->Instance->CR1 |= (0x1U << I2C_CR1_PE);
	}
	else{
		I2C_Handle->Instance->CR1 &= ~(0x1U << I2C_CR1_PE);
	}
}


#endif /* SRC_I2C_C_ */
