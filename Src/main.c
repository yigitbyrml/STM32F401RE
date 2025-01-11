
#include <stm32f401re.h>

#include <stdio.h>
#include <unistd.h>

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t MyTask1_Handle = NULL;
TaskHandle_t MyTask2_Handle = NULL;

void Task1_Handler(void *params);
void Task2_Handler(void *params);

void GPIO_LedConfig();
void GPIO_InterruptConfig();

void delay(uint32_t time);

void SPI_Config();
void SPI_GPIO_Config();

SPI_HandlerTypedef SPI_Handle;

void USART_Config(void);

void USART_GPIO_Config(void);

USART_HandlerTypedef USART_Handle;

uint32_t accesss = 1;
uint32_t accesss2 = 1;

void EXTI9_5_IRQHandler(){
	if(EXTI->PR & 0x40){
		EXTI->PR |= (0x1U << 6U);
		GPIO_Write_Pin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
	}
}

int main(void)
{
    GPIO_LedConfig();

    GPIO_InterruptConfig();

    //SPI_GPIO_Config();

    //SPI_Config();

    USART_GPIO_Config();

    USART_Config();

    //SPI_TransmitData(&SPI_Handle, (uint8_t*)msgtosend, sizeof(msgtosend));



    xTaskCreate(Task1_Handler, "Task1", 128, NULL, 4, &MyTask1_Handle);
    xTaskCreate(Task2_Handler, "Task2", 128, NULL, 4, &MyTask2_Handle);

    vTaskStartScheduler();

	for(;;){
	}
}

void GPIO_LedConfig(){
	GPIO_InitTypedef deneme = {0};

	RCC_GPIOC_CLCK_ENABLE();

	deneme.mode = GPIO_MODER_OUTPUT;
	deneme.otype = GPIO_OTYPER_PP;
	deneme.pinnumber=GPIO_PIN_5;
	deneme.pupd = GPIO_PUPD_NOPULL;
	deneme.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC, &deneme);

	memset(&deneme,0,sizeof(deneme));

	deneme.mode = GPIO_MODER_INPUT;
	deneme.pinnumber = GPIO_PIN_6;
	deneme.pupd = GPIO_PUPD_PULLDOWN;
	GPIO_Init(GPIOC, &deneme);

	memset(&deneme,0,sizeof(deneme));
}

void delay(uint32_t time){
	time = time*12;
	while(time--);
}

void GPIO_InterruptConfig(){
	EXTI_IniTypedef interruptdeneme = {0};

	RCC_SYSCFG_CLCK_ENABLE();
	EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_6);

	interruptdeneme.EXTILineCmd = ENABLE;
	interruptdeneme.EXTI_LineNumber = EXTI_LineSource_6;
	interruptdeneme.EXTI_Mode = EXTI_MODE_Interrupt;
	interruptdeneme.TriggerSelection = EXTI_Trigger_Rising;

	EXTI_Init(&interruptdeneme);

	NVIC_EnableInterrupt(EXTI9_5_IRQNumber);
}

void SPI_Config(){

	RCC_SPI1_CLCK_ENABLE();

	SPI_Handle.Instance=SPI1;
	SPI_Handle.Init.BaudRate=SPI_BAUDRATE_DIV8;
	SPI_Handle.Init.BusConfig=SPI_BUS_FULLDUPLEX;
	SPI_Handle.Init.Cpha=SPI_CPHA_FIRST;
	SPI_Handle.Init.Cpol=SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format=SPI_DFF_8BITS;
	SPI_Handle.Init.Frame_Format=SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode=SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd=SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);

	//NVIC_EnableInterrupt(SPI1_IRQNumber);

	SPI_PeriphState(&SPI_Handle,ENABLE);

}

void SPI_GPIO_Config(){
	GPIO_InitTypedef GPIO_InitStruct = {0};

	RCC_GPIOA_CLCK_ENABLE();

	GPIO_InitStruct.pinnumber = GPIO_PIN_5 | GPIO_PIN_7;
	GPIO_InitStruct.mode=GPIO_MODER_ALTERNATE;
	GPIO_InitStruct.otype=GPIO_OTYPER_PP;
	GPIO_InitStruct.speed=GPIO_OSPEED_VERY;
	GPIO_InitStruct.pupd=GPIO_PUPD_NOPULL;
	GPIO_InitStruct.alternate=GPIO_AF5;

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

void USART_GPIO_Config(void){

	GPIO_InitTypedef GPIO_InitStruct = {0};

	RCC_GPIOA_CLCK_ENABLE();

	GPIO_InitStruct.pinnumber = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.mode=GPIO_MODER_ALTERNATE;
	GPIO_InitStruct.otype=GPIO_OTYPER_PP;
	GPIO_InitStruct.speed=GPIO_OSPEED_VERY;
	GPIO_InitStruct.pupd=GPIO_PUPD_NOPULL;
	GPIO_InitStruct.alternate=GPIO_AF7;

	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void Task1_Handler(void *params){

	char msgtosend1[] = "DUSAN TADIC\r\n";

	while(1){
		if(accesss == 1){
			accesss2 = 0;
			USART_TransmitData(&USART_Handle, (uint8_t*)msgtosend1, sizeof(msgtosend1));
			delay(50000);
			accesss2 = 1;
			accesss=0;
		}
	}
}

void Task2_Handler(void *params){

	char msgtosend2[] = "EDIN DZEKO\r\n";

	while(1){
		if(accesss2 == 1){
			accesss = 0;
			USART_TransmitData(&USART_Handle, (uint8_t*)msgtosend2, sizeof(msgtosend2));
			delay(50000);
			accesss = 1;
			accesss2=0;
		}
	}
}



