/*
 * DMA_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Menna Eid
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

typedef enum
{
	 DMA_Transfer_Complete=1,
	 DMA_Half_Transfer,
	 DMA_Transfer_Error
}DMA_InterruptFlags_t;

typedef enum
{
	DMA_MemoryToMemory,
	DMA_MemoryToPeriphral,
	DMA_PeriphralToMemory
}DMA_MODE_t;

typedef enum
{
	Channel1=1,
	Channel2,
	Channel3,
	Channel4,
	Channel5,
	Channel6,
	Channel7
}DMA_ChannelID;
typedef enum
{
	DMA_LOW,
	DMA_Medium,
	DMA_HIGH,
	DMA_VeryHigh
}DMA_ChannelsPriority_t;

typedef enum
{
	DMA_Byte,
	DMA_Half_Word,
	DMA_Word
}DMA_DataTransferSize_t;
typedef struct
{
	DMA_MODE_t mode;
	DMA_ChannelID ChannelId;
	DMA_DataTransferSize_t DataSize;
	DMA_ChannelsPriority_t  ChannelPriority;
	DMA_InterruptFlags_t  flag;
}DMA_ChannelConfig_t;

/* init channel Mode and chaennel Id*/
ES_t DMA_enuInitChannelMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DAM_enuEnableMemoryIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DAM_enuDisableMemoryIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuEnablePeripheralIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuDisablePeripheralIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuSetMemoryDataTransferSize(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuSetPeripheralDataTransferSize(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuSetChannelPriority(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuEnableCircularMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuDisableCircularMode(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuEnableInterruptFlag(DMA_ChannelConfig_t*Copy_PSChannelConfig);

ES_t DMA_enuTransferData(DMA_ChannelConfig_t*Copy_PSChannelConfig,u32_t Copy_u32Srcaddress,u32_t Copy_u32Desaddress,u16_t Copy_u16NOFData);

ES_t DMA_enuSetCallBack(void (*pf)(void),DMA_ChannelConfig_t*Copy_PSChannelConfig);
#endif /* DMA_INTERFACE_H_ */
