
#include "stm32f401re.h"

void USART_GPIO_Config(void);

void USART_Config(void);

void delay(uint32_t time);

USART_HandlerTypedef USART_Handle;

int main(void){

	USART_GPIO_Config();
	USART_Config();
	char msgtosend[] = "Hello World!\n";

	while(1){
		USART_TransmitData(&USART_Handle, (uint8_t*)msgtosend, strlen(msgtosend));
		delay(360000);
	}
}

void USART_GPIO_Config(void){

	GPIO_InitTypedef GPIO_InitStruct = {0};

	RCC_GPIOA_CLCK_ENABLE();

	GPIO_InitStruct.pinnumber = GPIO_PIN_2;
	GPIO_InitStruct.mode=GPIO_MODER_ALTERNATE;
	GPIO_InitStruct.otype=GPIO_OTYPER_PP;
	GPIO_InitStruct.speed=GPIO_OSPEED_VERY;
	GPIO_InitStruct.pupd=GPIO_PUPD_NOPULL;
	GPIO_InitStruct.alternate=GPIO_AF7;

	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void USART_Config(void){

	RCC_USART2_CLCK_ENABLE();

	USART_Handle.Instance = USART2;
	USART_Handle.Init.BaudRate = 9600;
	USART_Handle.Init.HardWareFlowControl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_TX;
	USART_Handle.Init.OverSampling = USART_OVERSAMPLE_16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.WordLength = USART_WORDLENGTH_8BITS;

	USART_Init(&USART_Handle);

	USART_PeriphState(&USART_Handle, ENABLE);

}

void delay(uint32_t time){
	while(time--);
}
