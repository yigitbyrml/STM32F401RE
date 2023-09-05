
#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f401re.h"

#define EXTI_PortSource_GPIOA      ((uint8_t)(0x0))
#define EXTI_PortSource_GPIOB      ((uint8_t)(0x1))
#define EXTI_PortSource_GPIOC      ((uint8_t)(0x2))
#define EXTI_PortSource_GPIOD      ((uint8_t)(0x3))
#define EXTI_PortSource_GPIOE      ((uint8_t)(0x4))

#define EXTI_LineSource_0          ((uint8_t)(0x0))
#define EXTI_LineSource_1          ((uint8_t)(0x1))
#define EXTI_LineSource_2          ((uint8_t)(0x2))
#define EXTI_LineSource_3          ((uint8_t)(0x3))
#define EXTI_LineSource_4          ((uint8_t)(0x4))
#define EXTI_LineSource_5          ((uint8_t)(0x5))
#define EXTI_LineSource_6          ((uint8_t)(0x6))
#define EXTI_LineSource_7          ((uint8_t)(0x7))
#define EXTI_LineSource_8          ((uint8_t)(0x8))
#define EXTI_LineSource_9          ((uint8_t)(0x9))
#define EXTI_LineSource_10         ((uint8_t)(0xA))
#define EXTI_LineSource_11         ((uint8_t)(0xB))
#define EXTI_LineSource_12         ((uint8_t)(0xC))
#define EXTI_LineSource_13         ((uint8_t)(0xD))
#define EXTI_LineSource_14         ((uint8_t)(0xE))
#define EXTI_LineSource_15         ((uint8_t)(0xF))

//EXTI MODES
#define EXTI_MODE_Interrupt        (0x00U)
#define EXTI_MODE_Event            (0x04U)

//EXTI TRIGGER MODES
#define EXTI_Trigger_Rising        (0x08U)
#define EXTI_Trigger_Falling       (0x0CU)
#define EXTI_Trigger_RF            (0x10U)


typedef enum{
	EXTI0_IRQNumber=6,
	EXTI1_IRQNumber=7,
	EXTI2_IRQNumber=8,
	EXTI3_IRQNumber=9,
	EXTI4_IRQNumber=10,
	EXTI9_5_IRQNumber=23,
	EXTI15_10_IRQNumber=40,
	SPI1_IRQNumber=35
}IRQNumber_Typedef;

typedef struct{
	FunctionalState EXTILineCmd;
	uint8_t EXTI_LineNumber;
	uint8_t TriggerSelection;
	uint8_t EXTI_Mode;

}EXTI_IniTypedef;


void EXTI_LineConfig(uint8_t PortSource,uint8_t EXTI_LineSource);
void EXTI_Init(EXTI_IniTypedef *EXTI_InitStruct);
void NVIC_EnableInterrupt(IRQNumber_Typedef IRQnumber);



#endif /* INC_EXTI_H_ */
