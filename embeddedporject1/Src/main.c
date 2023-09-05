
#include "stm32f401re.h"

float distance = 0;

void GPIO_LEDConfig();

void delay(uint32_t time);

void GPIO_InterruptConfig();

void EXTI0_IRQHandler();

SPI_HandlerTypedef SPI_Handle;
USART_HandlerTypedef USART_Handle;

void EXTI15_10_IRQHandler(){
	char msgtosend[] = "Hello World!\n";
	if(EXTI->PR & (0x1 << 13U)){
		EXTI->PR |= (0x1U << 13U);

		SPI_TransmitData(&SPI_Handle, (uint8_t*)msgtosend, strlen(msgtosend));

		for(int i=0;i<8;i++){
			GPIO_Write_Pin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			delay(360000);
			GPIO_Write_Pin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			delay(360000);
		}
	}
}

void SPI1_IRQHandler(){
	SPI_InterruptHandler(&SPI_Handle);
}

void SPI_Config();

void SPI_GPIO_Config();

void USART_Config(void);

void USART_GPIO_Config(void);

float HCRS04_Read();



int main(void)
{

	GPIO_LEDConfig();

	//SPI_GPIO_Config();
	GPIO_InterruptConfig();

	//SPI_Config();

	USART_GPIO_Config();

	USART_Config();

	char msgtosend[] = "Hello World!\r\n";


	//SPI_TransmitData(&SPI_Handle, (uint8_t*)msgtosend, sizeof(msgtosend));

	for(;;){
		//if(GPIO_Read_Pin(GPIOC, GPIO_PIN_13)==GPIO_PIN_SET){
		//	GPIO_Write_Pin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		//}
		//else{
		//	GPIO_Write_Pin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		//}
		USART_TransmitData(&USART_Handle, (uint8_t*)msgtosend, sizeof(msgtosend));
		delay(5000);
	}


}

void GPIO_LEDConfig(){

	GPIO_InitTypedef GPIO_LEDStruct = {0};

	RCC_GPIOB_CLCK_ENABLE();
	RCC_GPIOC_CLCK_ENABLE();

	GPIO_LEDStruct.pinnumber=GPIO_PIN_13;
	GPIO_LEDStruct.mode=GPIO_MODER_OUTPUT;
	GPIO_LEDStruct.speed=GPIO_OSPEED_VERY;
	GPIO_LEDStruct.otype=GPIO_OTYPER_PP;
	GPIO_LEDStruct.pupd=GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOB, &GPIO_LEDStruct);

	//memset(&GPIO_LEDStruct,0,sizeof(GPIO_LEDStruct));

	GPIO_LEDStruct.pinnumber=GPIO_PIN_13;
	GPIO_LEDStruct.mode=GPIO_MODER_INPUT;
	GPIO_LEDStruct.pupd=GPIO_PUPD_NOPULL;
	GPIO_Init(GPIOC, &GPIO_LEDStruct);

}

void GPIO_InterruptConfig(){
	EXTI_IniTypedef EXTI_Struct = {0};

	RCC_SYSCFG_CLCK_ENABLE();
	EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_13);

	EXTI_Struct.EXTILineCmd=ENABLE;
	EXTI_Struct.EXTI_LineNumber=EXTI_LineSource_13;
	EXTI_Struct.EXTI_Mode=EXTI_MODE_Interrupt;
	EXTI_Struct.TriggerSelection=EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_Struct);
	NVIC_EnableInterrupt(EXTI15_10_IRQNumber);
}

void delay(uint32_t time){
	uint32_t newtime = time*24;
	while(newtime--);
}

void EXTI0_IRQHandler(){
	if(EXTI->PR & 0x1){
		EXTI->PR |= (0x1U << 0U);
		GPIO_Write_Pin(GPIOA, GPIO_PIN_ALL, GPIO_PIN_SET);
	}
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

float HCRS04_Read(){

	uint32_t time=0;
	float tempdistance = 0;

	GPIO_Write_Pin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	delay(10);
	GPIO_Write_Pin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	delay(10);
	GPIO_Write_Pin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	delay(10);

	while(!(GPIO_Read_Pin(GPIOC, GPIO_PIN_13)));

	while(GPIO_Read_Pin(GPIOC, GPIO_PIN_13)){
		time++;
		delay(1);
	}
	tempdistance = (float)time/58;

	delay(1000);

	return tempdistance;

}




