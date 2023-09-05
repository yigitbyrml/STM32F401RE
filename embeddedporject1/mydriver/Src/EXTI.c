/*
 * EXTI.c
 *
 *  Created on: 19 Tem 2023
 *      Author: yigit
 */

#ifndef SRC_EXTI_C_
#define SRC_EXTI_C_

#include "EXTI.h"

void EXTI_LineConfig(uint8_t PortSource,uint8_t EXTI_LineSource){

	uint32_t temp=SYSCFG->EXTICR[EXTI_LineSource >> 2U];
	temp &= ~(0xFU << ((EXTI_LineSource & 0x3U)*4));
	temp=(PortSource << ((EXTI_LineSource & 0x3U)*4));
	SYSCFG->EXTICR[EXTI_LineSource >> 2U]=temp;
}

void EXTI_Init(EXTI_IniTypedef *EXTI_InitStruct){
	uint32_t temp=(uint32_t)(EXTI_BASE_ADDR);

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if(EXTI_InitStruct->EXTILineCmd != DISABLE){

		temp += EXTI_InitStruct->EXTI_Mode;
		*((volatile uint32_t*)temp)|=(0x1 << EXTI_InitStruct->EXTI_LineNumber);

		temp=(uint32_t)(EXTI_BASE_ADDR);

		EXTI->RTSR  &=  ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR  &=  ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if(EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF){
			EXTI->RTSR  |=  (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR  |=  (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		}
		else{
			temp += EXTI_InitStruct->TriggerSelection;
			*((volatile uint32_t*)temp)|=(0x1 << EXTI_InitStruct->EXTI_LineNumber);
		}
	}
	else{
		uint32_t temp=(uint32_t)(EXTI_BASE_ADDR);
		temp += EXTI_InitStruct->EXTI_Mode;
		*((volatile uint32_t*)temp) &= ~(0x1 << EXTI_InitStruct->EXTI_LineNumber);
	}
}

void NVIC_EnableInterrupt(IRQNumber_Typedef IRQnumber){
	uint32_t temp=0;
	temp = *((IRQnumber >> 5U)+NVIC_ISER0);
	temp &= ~(0x1 << (IRQnumber & 0x1FU));
	temp |= (0x1 << (IRQnumber & 0x1FU));
	*((IRQnumber >> 5U)+NVIC_ISER0) = temp;
}










#endif /* SRC_EXTI_C_ */
