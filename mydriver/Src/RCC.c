/*
 * RCC.c
 *
 *  Created on: Jul 13, 2023
 *      Author: yigit
 */

#ifndef SRC_RCC_C_
#define SRC_RCC_C_

#include "RCC.h"

uint32_t SystemCoreClock = 16000000;

const uint8_t AHB_Prescaler[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

const uint8_t APB_Prescaler[] = {0, 0, 0, 0, 1, 2, 3, 4};

uint32_t RCC_GetSystemClock(void){


	uint8_t clckSource = 0;

	clckSource = ((RCC->CFGR >> 2U) & 0x3U);

	switch(clckSource){
	case 0:
		SystemCoreClock = 16000000;
		break;
	case 1:
		SystemCoreClock = 8000000;
		break;
	default:
		SystemCoreClock = 16000000;

	}

	return SystemCoreClock;
}

uint32_t RCC_GetHClock(void){

	uint32_t AHB_PeriphClock = 0;
	uint32_t SystemCoreClock = 0;
	uint8_t HPRE_Value = 0;
	uint8_t temp = 0;

	SystemCoreClock = RCC_GetSystemClock();

	HPRE_Value = ( (RCC->CFGR >> 4U) & 0xFU);
	temp = AHB_Prescaler[HPRE_Value];

	AHB_PeriphClock = SystemCoreClock >> temp;

	return AHB_PeriphClock;
}

uint32_t RCC_GetPClock1(void){

	uint32_t APB1_PeriphClock = 0;
	uint32_t Hclock = 0;
	uint8_t HPRE1_Value = 0;
	uint8_t temp = 0;

	Hclock = RCC_GetHClock();

	HPRE1_Value = ((RCC->CFGR >> 10U) & 0x7U);

	temp = APB_Prescaler[HPRE1_Value];

	APB1_PeriphClock = (Hclock >> temp);

	return APB1_PeriphClock;
}

uint32_t RCC_GetPClock2(void){

	uint32_t APB2_PeriphClock = 0;
	uint32_t Hclock = 0;
	uint8_t HPRE2_Value = 0;
	uint8_t temp = 0;

	Hclock = RCC_GetHClock();

	HPRE2_Value = ((RCC->CFGR >> 13U) & 0x7U);

	temp = APB_Prescaler[HPRE2_Value];

	APB2_PeriphClock = (Hclock >> temp);

	return APB2_PeriphClock;
}






#endif /* SRC_RCC_C_ */
