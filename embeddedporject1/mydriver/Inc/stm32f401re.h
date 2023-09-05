/*
 * stm32f401re.h
 *
 *  Created on: Jul 12, 2023
 *      Author: yigit
 */

#ifndef INC_STM32F401RE_H_
#define INC_STM32F401RE_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>


#define NVIC_ISER0          ((uint32_t *)(0xE000E100))

#define SET_BIT(REG,BIT)    ((REG) |= (BIT))
#define CLEAR_BIT(REG,BIT)  ((REG) &= ~(BIT))
#define READ_BIT(REG,BIT)   ((REG) & (BIT))
#define UNUSED(x)           (void)x

typedef enum{
	DISABLE = 0,
	ENABLE
}FunctionalState;

//MEMORY BASE ADDRESS

#define FLASH_BASE_ADDR            0x08000000UL
#define SRAM1_BASE_ADDR            0x20000000UL

//PERIPERALS BASE ADDRESS

#define PERIPH_BASE_ADDR           0x40000000UL

#define APB1_BASE_ADDR       (PERIPH_BASE_ADDR)
#define APB2_BASE_ADDR       (PERIPH_BASE_ADDR + 0x00010000UL)
#define AHB1_BASE_ADDR       (PERIPH_BASE_ADDR + 0x00020000UL)
#define AHB2_BASE_ADDR       (PERIPH_BASE_ADDR + 0x10000000UL)

//APB1 PERIPERALS BASE ADDRESS
#define TIM2_BASE_ADDR             (APB1_BASE_ADDR + 0x0000UL)
#define TIM3_BASE_ADDR             (APB1_BASE_ADDR + 0x0400UL)
#define TIM4_BASE_ADDR             (APB1_BASE_ADDR + 0x0800UL)
#define TIM5_BASE_ADDR             (APB1_BASE_ADDR + 0x0C00UL)
#define RTC_BASE_ADDR              (APB1_BASE_ADDR + 0x2800UL)
#define WWDG_BASE_ADDR             (APB1_BASE_ADDR + 0x2C00UL)
#define IWDG_BAS_ADDRE             (APB1_BASE_ADDR + 0x3000UL)
#define I2S2ext_BASE_ADDR          (APB1_BASE_ADDR + 0x3400UL)
#define SPI2_BASE_ADDR             (APB1_BASE_ADDR + 0x3800UL)
#define SPI3_BASE_ADDR             (APB1_BASE_ADDR + 0x3C00UL)
#define I2S3ext_BASE_ADDR          (APB1_BASE_ADDR + 0x4000UL)
#define USART2_BASE_ADDR           (APB1_BASE_ADDR + 0x4400UL)
#define I2C1_BASE_ADDR             (APB1_BASE_ADDR + 0x5400UL)
#define I2C2_BASE_ADDR             (APB1_BASE_ADDR + 0x5800UL)
#define I2C3_BASE_ADDR             (APB1_BASE_ADDR + 0x5C00UL)
#define PWR_BASE_ADDR              (APB1_BASE_ADDR + 0x7000UL)

//APB2 PERIPERALS BASE ADDREESS
#define TIM1_BASE_ADDR             (APB2_BASE_ADDR + 0x0000UL)
#define USART1_BASE_ADDR           (APB2_BASE_ADDR + 0x1000UL)
#define USART6_BASE_ADDR           (APB2_BASE_ADDR + 0x1400UL)
#define ADC1_BASE_ADDR             (APB2_BASE_ADDR + 0x2000UL)
#define SDIO_BASE_ADDR             (APB2_BASE_ADDR + 0x2C00UL)
#define SPI1_BASE_ADDR             (APB2_BASE_ADDR + 0x3000UL)
#define SPI4_BASE_ADDR             (APB2_BASE_ADDR + 0x3400UL)
#define SYSCFG_BASE_ADDR           (APB2_BASE_ADDR + 0x3800UL)
#define EXTI_BASE_ADDR             (APB2_BASE_ADDR + 0x3C00UL)
#define TIM9_BASE_ADDR             (APB2_BASE_ADDR + 0x4000UL)
#define TIM10_BASE_ADDR            (APB2_BASE_ADDR + 0x4400UL)
#define TIM11_BASE_ADDR            (APB2_BASE_ADDR + 0x4800UL)

//AHB1 PERIPERALS BASE ADDRESS
#define GPIOA_BASE_ADDR            (AHB1_BASE_ADDR + 0x0000UL)
#define GPIOB_BASE_ADDR            (AHB1_BASE_ADDR + 0x0400UL)
#define GPIOC_BASE_ADDR            (AHB1_BASE_ADDR + 0x0800UL)
#define GPIOD_BASE_ADDR            (AHB1_BASE_ADDR + 0x0C00UL)
#define GPIOE_BASE_ADDR            (AHB1_BASE_ADDR + 0x1000UL)
#define GPIOH_BASE_ADDR            (AHB1_BASE_ADDR + 0x1C00UL)
#define CRC_BASE_ADDR              (AHB1_BASE_ADDR + 0x3000UL)
#define RCC_BASE_ADDR              (AHB1_BASE_ADDR + 0x3800UL)
#define FLASH_R_BASE_ADDR          (AHB1_BASE_ADDR + 0x3C00UL)
#define DMA1_BASE_ADDR             (AHB1_BASE_ADDR + 0x6000UL)



typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSSR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_Typedef;

#define GPIOA                  ((GPIO_Typedef *)(GPIOA_BASE_ADDR))
#define GPIOB                  ((GPIO_Typedef *)(GPIOB_BASE_ADDR))
#define GPIOC                  ((GPIO_Typedef *)(GPIOC_BASE_ADDR))
#define GPIOD                  ((GPIO_Typedef *)(GPIOD_BASE_ADDR))
#define GPIOE                  ((GPIO_Typedef *)(GPIOE_BASE_ADDR))
#define GPIOH                  ((GPIO_Typedef *)(GPIOH_BASE_ADDR))

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t RESERVED1[2];
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t RESERVED3[2];
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED4[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t RESERVED5[2];
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED6[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED7[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t DCKCFGR;
}RCC_Typedef;

#define RCC           ((RCC_Typedef *)(RCC_BASE_ADDR))

#define RCC_AHB1ENR_GPIOAEN_POS      (0x0U)
#define RCC_AHB1ENR_GPIOAEN_MSK      (0x1 << RCC_AHB1ENR_GPIOAEN_POS)
#define RCC_AHB1ENR_GPIOAEN          (RCC_AHB1ENR_GPIOAEN_MSK)

#define RCC_AHB1ENR_GPIOBEN_POS      (0x1U)
#define RCC_AHB1ENR_GPIOBEN_MSK      (0x1 << RCC_AHB1ENR_GPIOBEN_POS)
#define RCC_AHB1ENR_GPIOBEN          (RCC_AHB1ENR_GPIOBEN_MSK)

#define RCC_AHB1ENR_GPIOCEN_POS      (0x2U)
#define RCC_AHB1ENR_GPIOCEN_MSK      (0x1 << RCC_AHB1ENR_GPIOCEN_POS)
#define RCC_AHB1ENR_GPIOCEN          (RCC_AHB1ENR_GPIOCEN_MSK)

#define RCC_AHB1ENR_GPIODEN_POS      (0x3U)
#define RCC_AHB1ENR_GPIODEN_MSK      (0x1 << RCC_AHB1ENR_GPIODEN_POS)
#define RCC_AHB1ENR_GPIODEN          (RCC_AHB1ENR_GPIODEN_MSK)

#define RCC_AHB1ENR_GPIOEEN_POS      (0x4U)
#define RCC_AHB1ENR_GPIOEEN_MSK      (0x1 << RCC_AHB1ENR_GPIOEEN_POS)
#define RCC_AHB1ENR_GPIOEEN          (RCC_AHB1ENR_GPIOEEN_MSK)

#define RCC_AHB1ENR_GPIOHEN_POS      (0x7U)
#define RCC_AHB1ENR_GPIOHEN_MSK      (0x1 << RCC_AHB1ENR_GPIOHEN_POS)
#define RCC_AHB1ENR_GPIOHEN          (RCC_AHB1ENR_GPIOHEN_MSK)


typedef struct{

	volatile uint32_t MEMPRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;

}SYSCFG_Typedef;

#define SYSCFG          ((SYSCFG_Typedef *)(SYSCFG_BASE_ADDR))

#define RCC_APB2ENR_SYSCFGEN_POS     (14U)
#define RCC_APB2ENR_SYSCFGEN_MSK     (0x1U << RCC_APB2ENR_SYSCFGEN_POS)
#define RCC_APB2ENR_SYSCFGEN         (RCC_APB2ENR_SYSCFGEN_MSK)


typedef struct{

	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_Typedef;

#define EXTI            ((EXTI_Typedef *)(EXTI_BASE_ADDR))


typedef struct{

	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

}SPI_Typedef;

#define SPI1           ((SPI_Typedef *)(SPI1_BASE_ADDR))
#define SPI2           ((SPI_Typedef *)(SPI2_BASE_ADDR))
#define SPI3           ((SPI_Typedef *)(SPI3_BASE_ADDR))
#define SPI4           ((SPI_Typedef *)(SPI4_BASE_ADDR))

#define RCC_APB2ENR_SPI1EN_POS     (12U)
#define RCC_APB2ENR_SPI1EN_MSK     (0x1U << RCC_APB2ENR_SPI1EN_POS)
#define RCC_APB2ENR_SPI1EN         (RCC_APB2ENR_SPI1EN_MSK)

#define RCC_APB1ENR_SPI2EN_POS     (14U)
#define RCC_APB1ENR_SPI2EN_MSK     (0x1U << RCC_APB1ENR_SPI2EN_POS)
#define RCC_APB1ENR_SPI2EN         (RCC_APB1ENR_SPI2EN_MSK)

#define RCC_APB1ENR_SPI3EN_POS     (15U)
#define RCC_APB1ENR_SPI3EN_MSK     (0x1U << RCC_APB1ENR_SPI3EN_POS)
#define RCC_APB1ENR_SPI3EN         (RCC_APB1ENR_SPI3EN_MSK)

#define RCC_APB2ENR_SPI4EN_POS     (13U)
#define RCC_APB2ENR_SPI4EN_MSK     (0x1U << RCC_APB2ENR_SPI4EN_POS)
#define RCC_APB2ENR_SPI4EN         (RCC_APB2ENR_SPI4EN_MSK)

#define SPI_CR1_SPE                (6U)
#define SPI_CR1_DFF                (11U)

#define SPI_CR2_TXEIE              (7U)
#define SPI_CR2_RXNEIE             (6U)

#define SPI_SR_TxE                 (1U)
#define SPI_SR_BUSY                (7U)
#define SPI_SR_RxNE                (0U)

#define SPI_TxE_FLAG               (0x1U << SPI_SR_TxE)
#define SPI_BUSY_FLAG              (0x1U << SPI_SR_BUSY)
#define SPI_RxNE_FLAG              (0x1U << SPI_SR_RxNE)


typedef struct{

	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}USART_Typedef;

#define USART1                 ((USART_Typedef *)(USART1_BASE_ADDR))
#define USART2                 ((USART_Typedef *)(USART2_BASE_ADDR))
#define USART6                 ((USART_Typedef *)(USART6_BASE_ADDR))


#define RCC_APB2ENR_USART1EN_POS     (4U)
#define RCC_APB2ENR_USART1EN_MSK     (0x1U << RCC_APB2ENR_USART1EN_POS)
#define RCC_APB2ENR_USART1EN         (RCC_APB2ENR_USART1EN_MSK)

#define RCC_APB1ENR_USART2EN_POS     (17U)
#define RCC_APB1ENR_USART2EN_MSK     (0x1U << RCC_APB1ENR_USART2EN_POS)
#define RCC_APB1ENR_USART2EN         (RCC_APB1ENR_USART2EN_MSK)

#define RCC_APB2ENR_USART6EN_POS     (5U)
#define RCC_APB2ENR_USART6EN_MSK     (0x1U << RCC_APB2ENR_USART6EN_POS)
#define RCC_APB2ENR_USART6EN         (RCC_APB2ENR_USART6EN_MSK)


#define USART_CR1_UE                 (13U)
#define USART_CR2_STOP               (12U)

#define USART_SR_TxE                 (7U)
#define USART_SR_TC                  (6U)
#define USART_SR_RxNE                (5U)


#define USART_TC_FLAG                (0x1U << USART_SR_TC)
#define USART_TxE_FLAG               (0x1U << USART_SR_TxE)
#define USART_RxNE_FLAG              (0x1U << USART_SR_RxNE)


typedef struct{

	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;

}I2C_Typedef;

#define I2C1                      ((I2C_Typedef *)(I2C1_BASE_ADDR))
#define I2C2                      ((I2C_Typedef *)(I2C2_BASE_ADDR))
#define I2C3                      ((I2C_Typedef *)(I2C3_BASE_ADDR))


#define RCC_APB1ENR_I2C1EN_POS     (21U)
#define RCC_APB1ENR_I2C1EN_MSK     (0x1U << RCC_APB1ENR_I2C1EN_POS)
#define RCC_APB1ENR_I2C1EN         (RCC_APB1ENR_I2C1EN_MSK)

#define RCC_APB1ENR_I2C2EN_POS     (22U)
#define RCC_APB1ENR_I2C2EN_MSK     (0x1U << RCC_APB1ENR_I2C2EN_POS)
#define RCC_APB1ENR_I2C2EN         (RCC_APB1ENR_I2C2EN_MSK)

#define RCC_APB1ENR_I2C3EN_POS     (23U)
#define RCC_APB1ENR_I2C3EN_MSK     (0x1U << RCC_APB1ENR_I2C3EN_POS)
#define RCC_APB1ENR_I2C3EN         (RCC_APB1ENR_I2C3EN_MSK)

#define I2C_CR1_PE                 (0U)
#define I2C_CR1_START              (8U)
#define I2C_CR1_STOP               (9U)

#define I2C_SR1_TxE                (7U)
#define I2C_SR1_RxNE               (6U)
#define I2C_SR1_BTF                (2U)
#define I2C_SR1_ADDR               (1U)
#define I2C_SR1_SB                 (0U)

#define I2C_TxE_FLAG               (0x1U << I2C_SR1_TxE)
#define I2C_RxNE_FLAG              (0x1U << I2C_SR1_RxNE)
#define I2C_SB_FLAG                (0x1U << I2C_SR1_SB)
#define I2C_ADDR_FLAG              (0x1U << I2C_SR1_ADDR)
#define I2C_BTF_FLAG               (0x1U << I2C_SR1_BTF)


#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#include "USART.h"
#include "I2C.h"




#endif /* INC_STM32F401RE_H_ */
