
#include "stm32f401re.h"

float distance = 0;

void DISPLAYConfig();

void delayus(uint32_t time);

void delay(uint32_t time);

float HCRS04_Read();

int main(void){

	DISPLAYConfig();

	GPIO_Write_Pin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET); // SOL ALT
	GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // ALT
	GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET); // ORTA
	GPIO_Write_Pin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // SAĞ ALT
	GPIO_Write_Pin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // SAĞ ÜST
	GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // YUKARI
	GPIO_Write_Pin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET); // SOL ÜST
	GPIO_Write_Pin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET); //NOKTA

	GPIO_Write_Pin(GPIOB, GPIO_PIN_ALL, GPIO_PIN_RESET);
	GPIO_Write_Pin(GPIOC, GPIO_PIN_ALL, GPIO_PIN_RESET);




	while(1){
		distance = HCRS04_Read();



		if((distance * 10) >= 2 && (distance * 10) <= 3){
			GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // YUKARI
			GPIO_Write_Pin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // SAĞ ÜST
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET); // ORTA
			GPIO_Write_Pin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET); // SOL ALT
			GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // ALT

			while(1){
				distance = HCRS04_Read();
				if((distance * 10) > 3 || (distance * 10) < 2){
					break;
				}
			}
			GPIO_Write_Pin(GPIOB, GPIO_PIN_ALL, GPIO_PIN_RESET);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_ALL, GPIO_PIN_RESET);

		}
		else if((distance * 10) >= 3 && (distance * 10) <= 4){
			GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // YUKARI
			GPIO_Write_Pin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // SAĞ ÜST
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET); // ORTA
			GPIO_Write_Pin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // SAĞ ALT
			GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // ALT

			while(1){
				distance = HCRS04_Read();
				if((distance * 10) > 4 || (distance * 10) < 3){
					break;
				}
			}
			GPIO_Write_Pin(GPIOB, GPIO_PIN_ALL, GPIO_PIN_RESET);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_ALL, GPIO_PIN_RESET);
		}
		else if((distance * 10) >= 4 && (distance * 10) <= 5){
			GPIO_Write_Pin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET); // SOL ÜST
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET); // ORTA
			GPIO_Write_Pin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // SAĞ ÜST
			GPIO_Write_Pin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // SAĞ ALT

			while(1){
				distance = HCRS04_Read();
				if((distance * 10) > 5 || (distance * 10) < 4){
					break;
				}
			}
			GPIO_Write_Pin(GPIOB, GPIO_PIN_ALL, GPIO_PIN_RESET);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_ALL, GPIO_PIN_RESET);
		}
		else if((distance * 10) >= 5 && (distance * 10) <= 6){
			GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // YUKARI
			GPIO_Write_Pin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET); // SOL ÜST
			GPIO_Write_Pin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET); // ORTA
			GPIO_Write_Pin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // SAĞ ALT
			GPIO_Write_Pin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // ALT

			while(1){
				distance = HCRS04_Read();
				if((distance * 10) > 6 || (distance * 10) < 5){
					break;
				}
			}
			GPIO_Write_Pin(GPIOB, GPIO_PIN_ALL, GPIO_PIN_RESET);
			GPIO_Write_Pin(GPIOC, GPIO_PIN_ALL, GPIO_PIN_RESET);
		}
	}
}

void delayus(uint32_t time){
	while(time--);
}

void DISPLAYConfig(){

	GPIO_InitTypedef S = {0};

	RCC_GPIOC_CLCK_ENABLE();
	RCC_GPIOB_CLCK_ENABLE();

	S.pinnumber= GPIO_PIN_4 | GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_0;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOC,&S);

	S.pinnumber = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_10;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOB, &S);

	S.pinnumber = GPIO_PIN_13;
	S.mode = GPIO_MODER_OUTPUT;
	S.pupd = GPIO_PUPD_NOPULL;
	S.otype = GPIO_OTYPER_PP;
	S.speed = GPIO_OSPEED_LOW;

	GPIO_Init(GPIOB, &S);

	S.pinnumber= GPIO_PIN_13;
	S.mode = GPIO_MODER_INPUT;
	S.pupd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOC,&S);
}

void delay(uint32_t time){
	uint32_t newtime = time*24;
	while(newtime--);
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


