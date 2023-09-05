
#include "stm32f401re.h"

I2C_HandlerTypedef I2C_Handle;

void I2C_Config(void);

void I2C_GPIO_Config(void);

uint8_t some_data[] = "HELLO WORLD";

int main(){

	I2C_GPIO_Config();

	I2C_Config();

	//I2C_MasterTransmitData(&I2C_Handle, some_data,strlen((char*)some_data) , SlaveAddr);


}

void I2C_Config(void){

	RCC_I2C1_CLCK_ENABLE();

	I2C_Handle.Instance=I2C1;
	I2C_Handle.Init.ACKState = I2C_ACK_ENABLE;
	I2C_Handle.Init.DutyCycle = I2C_DUTY_FM_2;
	I2C_Handle.Init.AddressingMode = I2C_ADDRMODE_7;
	I2C_Handle.Init.ClockSpeed = I2C_SPEED_STANDART;
	I2C_Handle.Init.ClockStretch = I2C_STRETCH_DISABLE;
	I2C_Handle.Init.MyOwnAddress = 0;

	I2C_Init(&I2C_Handle);

	//NVIC_EnableInterrupt(SPI1_IRQNumber);

	I2C_PeriphState(&I2C_Handle,ENABLE);

}

void I2C_GPIO_Config(void){
	GPIO_InitTypedef GPIO_InitStruct = {0};

	RCC_GPIOB_CLCK_ENABLE();

	GPIO_InitStruct.pinnumber = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStruct.mode=GPIO_MODER_ALTERNATE;
	GPIO_InitStruct.otype=GPIO_OTYPER_PP;
	GPIO_InitStruct.speed=GPIO_OSPEED_VERY;
	GPIO_InitStruct.pupd=GPIO_PUPD_NOPULL;
	GPIO_InitStruct.alternate=GPIO_AF4;

	GPIO_Init(GPIOB,&GPIO_InitStruct);
}


