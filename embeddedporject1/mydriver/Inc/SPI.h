
#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f401re.h"

#define SPI_BAUDRATE_DIV2           ((uint32_t)(0x00000000))
#define SPI_BAUDRATE_DIV4           ((uint32_t)(0x00000008))
#define SPI_BAUDRATE_DIV8           ((uint32_t)(0x00000010))
#define SPI_BAUDRATE_DIV16          ((uint32_t)(0x00000018))
#define SPI_BAUDRATE_DIV32          ((uint32_t)(0x00000020))
#define SPI_BAUDRATE_DIV64          ((uint32_t)(0x00000028))
#define SPI_BAUDRATE_DIV128         ((uint32_t)(0x00000030))
#define SPI_BAUDRATE_DIV256         ((uint32_t)(0x00000038))

#define SPI_CPHA_FIRST              ((uint32_t)(0x00000000))
#define SPI_CPHA_SECOND             ((uint32_t)(0x00000001))

#define SPI_CPOL_LOW                ((uint32_t)(0x00000000))
#define SPI_CPOL_HIGH               ((uint32_t)(0x00000002))

#define SPI_DFF_8BITS               ((uint32_t)(0x00000000))
#define SPI_DFF_16BITS              ((uint32_t)(0x00000800))

#define SPI_MODE_MASTER             ((uint32_t)(0x00000004))
#define SPI_MODE_SLAVE              ((uint32_t)(0x00000000))

#define SPI_FRAMEFORMAT_MSB         ((uint32_t)(0x00000000))
#define SPI_FRAMEFORMAT_LSB         ((uint32_t)(0x00000080))

#define SPI_BUS_FULLDUPLEX          ((uint32_t)(0x00000000))
#define SPI_BUS_RECEIVEONLY         ((uint32_t)(0x00000400))
#define SPI_BUS_HALDUPLEX_T         ((uint32_t)(0x0000C000))
#define SPI_BUS_HALDUPLEX_R         ((uint32_t)(0x00008000))

#define SPI_SSM_DISABLE             ((uint32_t)(0x00000000))
#define SPI_SSM_ENABLE              ((uint32_t)(0x00000300))

typedef enum{
	SPI_FLAG_RESET=0,
	SPI_FLAG_SET
}SPI_FlagStatus;

typedef enum{
	SPI_BUS_FREE=0x0U,
	SPI_BUS_BUSY_TX=0x1U,
	SPI_BUS_BUSY_RX=0x2U
}SPI_BusStatus;

typedef struct{
	uint32_t Mode;
	uint32_t Cpha;
	uint32_t Cpol;
	uint32_t BaudRate;
	uint32_t SSM_Cmd;
	uint32_t DFF_Format;
	uint32_t BusConfig;
	uint32_t Frame_Format;

}SPI_InitTypedef;

typedef struct __SPI_HandlerTypedef{

	SPI_Typedef *Instance;
	SPI_InitTypedef Init;
	uint8_t *pDataAddr;
	uint16_t TxDataSize;
	uint8_t busStateTx;
	void(*TxISRFunction)(struct __SPI_HandlerTypedef *SPI_Handle);
	uint8_t busStateRx;
	uint8_t *pRxDataAddr;
	uint16_t RxDataSize;
	void(*RxISRFunction)(struct __SPI_HandlerTypedef *SPI_Handle);

}SPI_HandlerTypedef;

void SPI_Init(SPI_HandlerTypedef *SPI_Handle);

void SPI_PeriphState(SPI_HandlerTypedef *SPI_Handle,FunctionalState SPIstate);

void SPI_TransmitData(SPI_HandlerTypedef *SPI_Handle,uint8_t *pData, uint16_t sizeofData);

SPI_FlagStatus SPI_GetFlagStatus(SPI_HandlerTypedef *SPI_Handle, uint16_t SPI_Flag);

void SPI_ReceiveData(SPI_HandlerTypedef *SPI_Handle,uint8_t *pBuffer, uint16_t sizeofData);

void SPI_TransmitData_Interrupt(SPI_HandlerTypedef *SPI_Handle,uint8_t *pData, uint16_t sizeofData);

void SPI_ReceiveData_Interrupt(SPI_HandlerTypedef *SPI_Handle,uint8_t *pBuffer, uint16_t sizeofData);

void SPI_InterruptHandler(SPI_HandlerTypedef *SPI_Handle);






#endif /* INC_SPI_H_ */
