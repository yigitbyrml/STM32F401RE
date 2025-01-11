
#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f401re.h"

typedef enum{
	GPIO_PIN_RESET= 0,
	GPIO_PIN_SET
}GPIO_PinState;

#define GPIO_PIN_0     (uint16_t)(0x0001)
#define GPIO_PIN_1     (uint16_t)(0x0002)
#define GPIO_PIN_2     (uint16_t)(0x0004)
#define GPIO_PIN_3     (uint16_t)(0x0008)
#define GPIO_PIN_4     (uint16_t)(0x0010)
#define GPIO_PIN_5     (uint16_t)(0x0020)
#define GPIO_PIN_6     (uint16_t)(0x0040)
#define GPIO_PIN_7     (uint16_t)(0x0080)
#define GPIO_PIN_8     (uint16_t)(0x0100)
#define GPIO_PIN_9     (uint16_t)(0x0200)
#define GPIO_PIN_10    (uint16_t)(0x0400)
#define GPIO_PIN_11    (uint16_t)(0x0800)
#define GPIO_PIN_12    (uint16_t)(0x1000)
#define GPIO_PIN_13    (uint16_t)(0x2000)
#define GPIO_PIN_14    (uint16_t)(0x4000)
#define GPIO_PIN_15    (uint16_t)(0x8000)
#define GPIO_PIN_ALL   (uint16_t)(0xFFFF)


typedef struct{
	uint32_t pinnumber;
	uint32_t mode;
	uint32_t otype;
	uint32_t pupd;
	uint32_t speed;
	uint32_t alternate;
}GPIO_InitTypedef;

//GPIO MODER MOD
#define GPIO_MODER_INPUT       (0x0U)
#define GPIO_MODER_OUTPUT      (0x1U)
#define GPIO_MODER_ALTERNATE   (0x2U)
#define GPIO_MODER_ANALOG      (0x3U)

//GPIO OTYPER MOD
#define GPIO_OTYPER_PP         (0x0U)
#define GPIO_OTYPER_OD         (0x1U)

//GPIO OSPEEDR MOD
#define GPIO_OSPEED_LOW        (0x0U)
#define GPIO_OSPEED_MEDIUM     (0x1U)
#define GPIO_OSPEED_HIGH       (0x2U)
#define GPIO_OSPEED_VERY       (0x3U)

//GPIO PUPDR MOD
#define GPIO_PUPD_NOPULL       (0x0U)
#define GPIO_PUPD_PULLUP       (0x1U)
#define GPIO_PUPD_PULLDOWN     (0x2U)

//GPIO AF MOD
#define GPIO_AF0               (0x0U)
#define GPIO_AF1               (0x1U)
#define GPIO_AF2               (0x2U)
#define GPIO_AF3               (0x3U)
#define GPIO_AF4               (0x4U)
#define GPIO_AF5               (0x5U)
#define GPIO_AF6               (0x6U)
#define GPIO_AF7               (0x7U)
#define GPIO_AF8               (0x8U)
#define GPIO_AF9               (0x9U)
#define GPIO_AF10              (0xAU)
#define GPIO_AF11              (0xBU)
#define GPIO_AF12              (0xCU)
#define GPIO_AF13              (0xDU)
#define GPIO_AF14              (0xEU)
#define GPIO_AF15              (0xFU)


void GPIO_Init(GPIO_Typedef *GPIOx,GPIO_InitTypedef *GPIOStructures);

void GPIO_Write_Pin(GPIO_Typedef *GPIOx,uint16_t pinnumber,GPIO_PinState pinstate);

GPIO_PinState GPIO_Read_Pin(GPIO_Typedef *GPIOx,uint16_t pinnumber);

void GPIO_LockPin(GPIO_Typedef *GPIOx,uint16_t pinnumber);

void GPIO_TogglePin(GPIO_Typedef *GPIOx,uint16_t pinnumber);



#endif /* INC_GPIO_H_ */
