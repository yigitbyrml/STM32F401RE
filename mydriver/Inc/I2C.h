/*
 * I2C.h
 *
 *  Created on: 24 Ağu 2023
 *      Author: yigit
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32f401re.h"

#define I2C_SPEED_STANDART     (100000U)
#define I2C_SPEED_FAST         (400000U)

#define I2C_ACK_DISABLE        (0x00000000U)
#define I2C_ACK_ENABLE         (0x00000400U)

#define I2C_STRETCH_ENABLE     (0x00000000U)
#define I2C_STRETCH_DISABLE    (0x00000080U)

#define I2C_ADDRMODE_7         (0x00004000U)
#define I2C_ADDRMODE_10        (0x0000C000U)

#define I2C_DUTY_STANDART      (0x00000000U)
#define I2C_DUTY_FM_2          (0x00008000U)
#define I2C_DUTY_FM_16_9       (0x0000C000U)

#define Check_PClock_Value(__pClock__, __I2C_Clock__)     ((__I2C_Clock__ <= I2C_SPEED_STANDART) ? (__pClock__ <= 2000000U) : (__pClock__ <= 4000000U) )
#define I2C_Get_FreqValue(__pClock__)                     ((__pClock__) / (1000000U))


typedef enum{
	I2C_FLAG_RESET=0,
	I2C_FLAG_SET
}I2C_FlagStatus;

typedef  struct{

	uint32_t ClockSpeed;
	uint32_t ACKState;
	uint32_t ClockStretch;
	uint32_t AddressingMode;
	uint32_t DutyCycle;
	uint32_t MyOwnAddress;
}I2C_InitTypedef;

typedef struct{
	I2C_Typedef *Instance;
	I2C_InitTypedef Init;
}I2C_HandlerTypedef;

void I2C_Init(I2C_HandlerTypedef *I2C_Handle);
void I2C_PeriphState(I2C_HandlerTypedef *I2C_Handle, FunctionalState I2CState);
I2C_FlagStatus I2C_GetFlagStatus(I2C_HandlerTypedef *I2C_Handle, uint16_t I2C_Flag);
void I2C_MasterTransmitData(I2C_HandlerTypedef *I2C_Handle, uint8_t *pData, uint32_t sizeofdata, uint8_t SlaveAddr);


#endif /* INC_I2C_H_ */
