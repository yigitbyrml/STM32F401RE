
#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f401re.h"


//GPIO RCC ENABLE

#define RCC_GPIOA_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

#define RCC_GPIOB_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

#define RCC_GPIOC_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

#define RCC_GPIOD_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

#define RCC_GPIOE_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

#define RCC_GPIOH_CLCK_ENABLE()       do{ uint32_t temp=0;                                 \
	                                      SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);        \
	                                      temp=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);   \
	                                      UNUSED(temp);                                       \
}while(0)

//GPIO RCC DISABLE

#define RCC_GPIOA_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN)

#define RCC_GPIOB_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN)

#define RCC_GPIOC_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN)

#define RCC_GPIOD_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN)

#define RCC_GPIOE_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN)

#define RCC_GPIOH_CLCK_DISABLE()       CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN)


//SYSCFG RCC ENABLE

#define RCC_SYSCFG_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                      SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);       \
	                                      temp=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);  \
	                                      UNUSED(temp);                                       \
}while(0)

//SYSCFG RCC DISABLE

#define RCC_SYSCFG_CLCK_DISABLE()       CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN)


//SPI RCC ENABLE

#define RCC_SPI1_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN);        \
	                                     temp=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN);   \
	                                     UNUSED(temp);                                      \
}while(0)

#define RCC_SPI2_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN);        \
	                                     temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN);   \
	                                     UNUSED(temp);                                      \
}while(0)

#define RCC_SPI3_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN);        \
	                                     temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN);   \
	                                     UNUSED(temp);                                      \
}while(0)

#define RCC_SPI4_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN);        \
	                                     temp=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN);   \
	                                     UNUSED(temp);                                      \
}while(0)

//SPI RCC DISABLE

#define RCC_SPI1_CLCK_DISABLE()       CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN)

#define RCC_SPI2_CLCK_DISABLE()       CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN)

#define RCC_SPI3_CLCK_DISABLE()       CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN)

#define RCC_SPI4_CLCK_DISABLE()       CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN)

//USART RCC ENABLE

#define RCC_USART1_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN);        \
	                                     temp=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN);   \
	                                     UNUSED(temp);                                        \
}while(0)

#define RCC_USART2_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);        \
	                                     temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);   \
	                                     UNUSED(temp);                                        \
}while(0)

#define RCC_USART6_CLCK_ENABLE()       do{ uint32_t temp=0;                                \
	                                     SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN);        \
	                                     temp=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN);   \
	                                     UNUSED(temp);                                        \
}while(0)

//USART RCC DISABLE

#define RCC_USART1_CLCK_DISABLE()       CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN)

#define RCC_USART2_CLCK_DISABLE()       CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN)

#define RCC_USART6_CLCK_DISABLE()       CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN)

uint32_t RCC_GetSystemClock(void);

uint32_t RCC_GetHClock(void);

uint32_t RCC_GetPClock1(void);

uint32_t RCC_GetPClock2(void);


// I2C RCC ENABLE

#define RCC_I2C1_CLCK_ENABLE()        do{ uint32_t temp=0;                                 \
                                          SET_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1EN);         \
                                          temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1EN);    \
                                          UNUSED(temp);                                       \
}while(0)

#define RCC_I2C2_CLCK_ENABLE()        do{ uint32_t temp=0;                                 \
                                          SET_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C2EN);         \
                                          temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C2EN);    \
                                          UNUSED(temp);                                       \
}while(0)

#define RCC_I2C3_CLCK_ENABLE()        do{ uint32_t temp=0;                                 \
                                          SET_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C3EN);         \
                                          temp=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C3EN);    \
                                          UNUSED(temp);                                       \
}while(0)

// I2C RCC DISABLE

#define RCC_I2C1_CLCK_DISABLE()        CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1EN)

#define RCC_I2C2_CLCK_DISABLE()        CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C2EN)

#define RCC_I2C3_CLCK_DISABLE()        CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C3EN)








#endif /* INC_RCC_H_ */
