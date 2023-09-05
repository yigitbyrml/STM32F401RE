/*
 * GPIO.c
 *
 *  Created on: 13 Tem 2023
 *      Author: yigit
 */

#ifndef SRC_GPIO_C_
#define SRC_GPIO_C_

#include "GPIO.h"

void GPIO_Write_Pin(GPIO_Typedef *GPIOx,uint16_t pinnumber,GPIO_PinState pinstate){
	if(pinstate == GPIO_PIN_SET){
		GPIOx->BSSR=pinnumber;
	}
	else{
		GPIOx->BSSR=pinnumber << 16U;
	}
}

GPIO_PinState GPIO_Read_Pin(GPIO_Typedef *GPIOx,uint16_t pinnumber){

	GPIO_PinState bitstatus = GPIO_PIN_RESET;
	if((GPIOx->IDR & pinnumber) != (uint32_t)GPIO_PIN_RESET){
		bitstatus = GPIO_PIN_SET;
	}

	return bitstatus;
}

void GPIO_LockPin(GPIO_Typedef *GPIOx,uint16_t pinnumber){

	uint32_t temp=(0x1U << 16U) | pinnumber;
	GPIOx->LCKR=temp;
	GPIOx->LCKR=pinnumber;
	GPIOx->LCKR=temp;
	temp=GPIOx->LCKR;

}

void GPIO_Init(GPIO_Typedef *GPIOx,GPIO_InitTypedef *GPIOStructures){
	uint32_t position;
	uint32_t fakeposition=0;
	uint32_t lastposition=0;

	for(position = 0;position < 16;position++){

		fakeposition = (0x1 << position);
		lastposition = (uint32_t)(GPIOStructures->pinnumber)&fakeposition;

		if(fakeposition == lastposition){

			uint32_t temp=GPIOx->MODER;
			temp &= ~(0x3U << (position * 2));
			temp |= (GPIOStructures->mode << (position * 2));
			GPIOx->MODER = temp;

			if(GPIOStructures->mode == GPIO_MODER_OUTPUT || GPIOStructures->mode == GPIO_MODER_ALTERNATE){
				temp = GPIOx->OTYPER;
				temp &= ~(0x1U << position);
				temp |= (GPIOStructures->otype << position);
				GPIOx->OTYPER = temp;

				temp=GPIOx->OSPEEDR;
				temp &= ~(0x3U << (position * 2));
				temp |= (GPIOStructures->speed<< (position * 2));
				GPIOx->OSPEEDR= temp;
			}

			temp=GPIOx->PUPDR;
			temp &= ~(0x3U << (position * 2));
			temp |= (GPIOStructures->pupd<< (position * 2));
			GPIOx->PUPDR= temp;

			if(GPIOStructures->mode == GPIO_MODER_ALTERNATE){
				temp = GPIOx->AFR[position >> 3U];
				temp &= ~(0xFU << ((position & 0x7U)*4));
				temp |= (GPIOStructures->alternate << ((position & 0x7U)*4));
				GPIOx->AFR[position >> 3U] = temp;
			}
		}

	}
}

void GPIO_TogglePin(GPIO_Typedef *GPIOx,uint16_t pinnumber){
	uint32_t temp=GPIOx->ODR;
	GPIOx->BSSR=((temp & pinnumber) << 16U) | (~temp & pinnumber);
}








#endif /* SRC_GPIO_C_ */
