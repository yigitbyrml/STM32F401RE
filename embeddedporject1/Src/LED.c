
#include "stm32f401re.h"

void LEDConfig();

void delay(uint32_t time);

int main(void){

	LEDConfig();

	while(1){

		if(GPIO_Read_Pin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET){
			GPIO_Write_Pin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
			delay(360000);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
			delay(360000);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
			delay(360000);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
			delay(360000);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
			delay(360000);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
			delay(360000);
		}


	}
}



void LEDConfig(){

	GPIO_InitTypedef S = {0};

	RCC_GPIOC_CLCK_ENABLE();

	S.pinnumber= GPIO_PIN_4;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;+

	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC,&S);

	S.pinnumber= GPIO_PIN_3;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC,&S);

	S.pinnumber= GPIO_PIN_2;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC,&S);

	S.pinnumber= GPIO_PIN_0;
	S.mode = GPIO_MODER_INPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC,&S);

}

void delay(uint32_t time){
	//time = time*24;
	while(time > 0){
		time--;
	}
}


