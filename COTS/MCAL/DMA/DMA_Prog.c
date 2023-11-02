/*
 * DMA_Prog.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Menna Eid
 *
 */
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"
#include "../../LIB/errorstate.h"
#include "DMA_Interface.h"

static void (*DMA_PF[7]) (void) = {NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR};
	/*Set mode and Set direction*/
ES_t DMA_enuInitChannelMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{

	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId) {
			case Channel1:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR1,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR1,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
						SET_BIT(DMA->CCR1,4);
				}
				break;
			case Channel2:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR2,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR2,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR2,4);
				}
				break;
			case Channel3:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR3,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR3,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR3,4);
				}
				break;
			case Channel4:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR4,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR4,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR4,4);
				}
				break;
			case Channel5:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR5,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR5,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR5,4);
				}
				break;
			case Channel6:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR6,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR6,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR6,4);
				}
				break;
			case Channel7:
				if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				{
					SET_BIT(DMA->CCR7,14);
				}
				else if(Copy_PSChannelConfig->mode==DMA_PeriphralToMemory)
				{
					CLEAR_BIT(DMA->CCR7,4);
				}
				else if(Copy_PSChannelConfig->mode==DMA_MemoryToPeriphral)
				{
					SET_BIT(DMA->CCR7,4);
				}
				break;
			default:
				LocalErrorState = ES_NOK;
				break;

		}

		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DAM_enuEnableMemoryIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
					case Channel1:
						SET_BIT(DMA->CCR1,7);
						break;
					case Channel2:
						SET_BIT(DMA->CCR2,7);
						break;
					case Channel3:
						SET_BIT(DMA->CCR3,7);
						break;
					case Channel4:
						SET_BIT(DMA->CCR4,7);
						break;
					case Channel5:
						SET_BIT(DMA->CCR5,7);
						break;
					case Channel6:
						SET_BIT(DMA->CCR6,7);
						break;
					case Channel7:
						SET_BIT(DMA->CCR7,7);
						break;
					default:
						LocalErrorState = ES_NOK;
						break;
			 }

		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}
ES_t DAM_enuDisableMemoryIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
					case Channel1:
						CLEAR_BIT(DMA->CCR1,7);
						break;
					case Channel2:
						CLEAR_BIT(DMA->CCR2,7);
						break;
					case Channel3:
						CLEAR_BIT(DMA->CCR3,7);
						break;
					case Channel4:
						CLEAR_BIT(DMA->CCR4,7);
						break;
					case Channel5:
						CLEAR_BIT(DMA->CCR5,7);
						break;
					case Channel6:
						CLEAR_BIT(DMA->CCR6,7);
						break;
					case Channel7:
						CLEAR_BIT(DMA->CCR7,7);
						break;
					default:
						LocalErrorState = ES_NOK;
						break;
			}

		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuEnablePeripheralIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
					case Channel1:
						SET_BIT(DMA->CCR1,6);
						break;
					case Channel2:
						SET_BIT(DMA->CCR2,6);
						break;
					case Channel3:
						SET_BIT(DMA->CCR3,6);
						break;
					case Channel4:
						SET_BIT(DMA->CCR4,6);
						break;
					case Channel5:
						SET_BIT(DMA->CCR5,6);
						break;
					case Channel6:
						SET_BIT(DMA->CCR6,6);
						break;
					case Channel7:
						SET_BIT(DMA->CCR7,6);
						break;
					default:
						LocalErrorState = ES_NOK;
						break;
			}
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuDisablePeripheralIncrementMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				CLEAR_BIT(DMA->CCR1,6);
				break;
			case Channel2:
				CLEAR_BIT(DMA->CCR2,6);
				break;
			case Channel3:
				CLEAR_BIT(DMA->CCR3,6);
				break;
			case Channel4:
				CLEAR_BIT(DMA->CCR4,6);
				break;
			case Channel5:
				CLEAR_BIT(DMA->CCR5,6);
				break;
			case Channel6:
				CLEAR_BIT(DMA->CCR6,6);
				break;
			case Channel7:
				CLEAR_BIT(DMA->CCR7,6);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		}

		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuSetMemoryDataTransferSize(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
					case Channel1:
						DMA->CCR1 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel2:
						DMA->CCR2 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel3:
						DMA->CCR3 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel4:
						DMA->CCR4 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel5:
						DMA->CCR5 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel6:
						DMA->CCR6 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					case Channel7:
						DMA->CCR7 |= ((Copy_PSChannelConfig->DataSize) << 10);
						break;
					default:
						LocalErrorState = ES_NOK;
						break;
			}
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuSetPeripheralDataTransferSize(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				DMA->CCR1 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel2:
				DMA->CCR2 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel3:
				DMA->CCR3 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel4:
				DMA->CCR4 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel5:
				DMA->CCR5 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel6:
				DMA->CCR6 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			case Channel7:
				DMA->CCR7 |= ((Copy_PSChannelConfig->DataSize) << 8);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		 }
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuSetChannelPriority(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;

	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				DMA->CCR1 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel2:
				DMA->CCR2 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel3:
				DMA->CCR3 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel4:
				DMA->CCR4 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel5:
				DMA->CCR5 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel6:
				DMA->CCR6 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			case Channel7:
				DMA->CCR7 |= ((Copy_PSChannelConfig->ChannelPriority)<<12);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		}
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuEnableCircularMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				SET_BIT(DMA->CCR3,5);
				break;
			case Channel2:
				SET_BIT(DMA->CCR3,5);
				break;
			case Channel3:
				SET_BIT(DMA->CCR3,5);
				break;
			case Channel4:
				SET_BIT(DMA->CCR4,5);
				break;
			case Channel5:
				SET_BIT(DMA->CCR5,5);
				break;
			case Channel6:
				SET_BIT(DMA->CCR6,5);
				break;
			case Channel7:
				SET_BIT(DMA->CCR7,5);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		 }
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuDisableCircularMode(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				CLEAR_BIT(DMA->CCR3,5);
				break;
			case Channel2:
				CLEAR_BIT(DMA->CCR3,5);
				break;
			case Channel3:
				CLEAR_BIT(DMA->CCR3,5);
				break;
			case Channel4:
				CLEAR_BIT(DMA->CCR4,5);
				break;
			case Channel5:
				CLEAR_BIT(DMA->CCR5,5);
				break;
			case Channel6:
				CLEAR_BIT(DMA->CCR6,5);
				break;
			case Channel7:
				CLEAR_BIT(DMA->CCR7,5);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		 }
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuEnableInterruptFlag(DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
				{
					case Channel1:
						SET_BIT(DMA->CCR1,(Copy_PSChannelConfig->flag));
						break;
					case Channel2:
						SET_BIT(DMA->CCR2,(Copy_PSChannelConfig->flag));
						break;
					case Channel3:
						SET_BIT(DMA->CCR3,(Copy_PSChannelConfig->flag));
						break;
					case Channel4:
						SET_BIT(DMA->CCR4,(Copy_PSChannelConfig->flag));
						break;
					case Channel5:
						SET_BIT(DMA->CCR5,(Copy_PSChannelConfig->flag));
						break;
					case Channel6:
						SET_BIT(DMA->CCR6,(Copy_PSChannelConfig->flag));
						break;
					case Channel7:
						SET_BIT(DMA->CCR7,(Copy_PSChannelConfig->flag));
						break;
					default:
						LocalErrorState = ES_NOK;
						break;
				 }
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

ES_t DMA_enuTransferData(DMA_ChannelConfig_t*Copy_PSChannelConfig,u32_t Copy_u32Srcaddress,u32_t Copy_u32Desaddress,u16_t Copy_u16NOFData)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		switch (Copy_PSChannelConfig->ChannelId)
		{
			case Channel1:
				/*set number of data to transfer*/
				DMA->CNDTR1 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR1 = Copy_u32Srcaddress;
					 DMA->CMAR1 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR1,4) == 1 )
					 {
						 DMA->CMAR1 = Copy_u32Srcaddress;
						 DMA->CPAR1 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR1 = Copy_u32Srcaddress;
						 DMA->CMAR1 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR1,0);
				break;
			case Channel2:
				/*set number of data to transfer*/
				DMA->CNDTR2 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR2 = Copy_u32Srcaddress;
					 DMA->CMAR2 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR2,4) == 1 )
					 {
						 DMA->CMAR2 = Copy_u32Srcaddress;
						 DMA->CPAR2 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR2 = Copy_u32Srcaddress;
						 DMA->CMAR2 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR2,0);
				break;
			case Channel3:
				/*set number of data to transfer*/
				DMA->CNDTR3 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR3 = Copy_u32Srcaddress;
					 DMA->CMAR3 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR3,4) == 1 )
					 {
						 DMA->CMAR3 = Copy_u32Srcaddress;
						 DMA->CPAR3 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR3 = Copy_u32Srcaddress;
						 DMA->CMAR3 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR3,0);
				break;
			case Channel4:
				/*set number of data to transfer*/
				DMA->CNDTR4 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR4 = Copy_u32Srcaddress;
					 DMA->CMAR4 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR4,4) == 1 )
					 {
						 DMA->CMAR4 = Copy_u32Srcaddress;
						 DMA->CPAR4 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR4 = Copy_u32Srcaddress;
						 DMA->CMAR4 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR4,0);
				break;
			case Channel5:
				/*set number of data to transfer*/
				DMA->CNDTR5 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR5 = Copy_u32Srcaddress;
					 DMA->CMAR5 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR5,4) == 1 )
					 {
						 DMA->CMAR5 = Copy_u32Srcaddress;
						 DMA->CPAR5 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR5 = Copy_u32Srcaddress;
						 DMA->CMAR5 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				SET_BIT(DMA->CCR5,0);
				break;
			case Channel6:
				/*set number of data to transfer*/
				DMA->CNDTR6 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR6 = Copy_u32Srcaddress;
					 DMA->CMAR6 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR6,4) == 1 )
					 {
						 DMA->CMAR6 = Copy_u32Srcaddress;
						 DMA->CPAR6 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR6 = Copy_u32Srcaddress;
						 DMA->CMAR6 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR6,0);
				break;
			case Channel7:
				/*set number of data to transfer*/
				DMA->CNDTR7 = Copy_u16NOFData;
				 if(Copy_PSChannelConfig->mode==DMA_MemoryToMemory)
				 {
					 DMA->CPAR7 = Copy_u32Srcaddress;
					 DMA->CMAR7 = Copy_u32Desaddress;
				 }
				 else
				 {
					 /*checking if the memory to peripheral is the mode*/
					 if(READ_BIT(DMA->CCR7,4) == 1 )
					 {
						 DMA->CMAR7 = Copy_u32Srcaddress;
						 DMA->CPAR7 = Copy_u32Desaddress;
					 }
					 else
					 {
						 DMA->CPAR7 = Copy_u32Srcaddress;
						 DMA->CMAR7 = Copy_u32Desaddress;
					 }
				 }
				 /*enable channel*/
				 SET_BIT(DMA->CCR7,0);
				break;
			default:
				LocalErrorState = ES_NOK;
				break;
		  }
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}
ES_t DMA_enuSetCallBack(void (*pf)(void),DMA_ChannelConfig_t*Copy_PSChannelConfig)
{
	ES_t LocalErrorState = ES_NOK;
	if(Copy_PSChannelConfig!=NULLPTR)
	{
		LocalErrorState = ES_OK;
		DMA_PF[Copy_PSChannelConfig->ChannelId-1] = pf;
	}
	return LocalErrorState;

}
void DMA1_Channel1_IRQHandler()
{
	/*clear INT flag*/
	SET_BIT(DMA->IFCR,1);
	if(DMA_PF[0]!=NULLPTR)
	{
		DMA_PF[0]();
	}

}
void DMA1_Channel2_IRQHandler()
{
		/*clear INT flag*/
		SET_BIT(DMA->IFCR,5);
		if(DMA_PF[1]!=NULLPTR)
		{
			DMA_PF[1]();
		}

}
void DMA1_Channel3_IRQHandler()
{
	/*clear INT flag*/
	SET_BIT(DMA->IFCR,9);
	if(DMA_PF[2]!=NULLPTR)
	{
		DMA_PF[2]();
	}

}
void DMA1_Channel4_IRQHandler()
{
		/*clear INT flag*/
		SET_BIT(DMA->IFCR,13);
		if(DMA_PF[3]!=NULLPTR)
		{
			DMA_PF[3]();
		}

}
void DMA1_Channel5_IRQHandler()
{
		/*clear INT flag*/
		SET_BIT(DMA->IFCR,17);
		if(DMA_PF[4]!=NULLPTR)
		{
			DMA_PF[4]();
		}

}
void DMA1_Channel6_IRQHandler()
{
		/*clear INT flag*/
		SET_BIT(DMA->IFCR,21);
		if(DMA_PF[5]!=NULLPTR)
		{
			DMA_PF[5]();
		}

}
void DMA1_Channel7_IRQHandler()
{
		/*clear INT flag*/
		SET_BIT(DMA->IFCR,25);
		if(DMA_PF[6]!=NULLPTR)
		{
			DMA_PF[6]();
		}

}
