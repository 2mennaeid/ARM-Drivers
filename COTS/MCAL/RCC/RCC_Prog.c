/*****************                     *****************************************/
/***************** Name : Menna Eid    ****************************************/
/***************** Date: 8/18/2023     ***************************************/
/***************** Version: 1.0        **************************************/
/***************** SWC: RCC            *************************************/
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.H"
#include "../../LIB/stm32f103xx.h"
#include "RCC_Priv.h"
#include "RCC_Interface.h"

void RCC_voidSelectClock(CLOCK_TYPES enuclk_type)
{
	switch(enuclk_type)
	{
		case HSI:
			SET_BIT(RCC->CR,0);
			CLEAR_BIT(RCC->CFGR,0);
			CLEAR_BIT(RCC->CFGR,1);
			break;
		case HSE :
			SET_BIT(RCC->CR,16);
			SET_BIT(RCC->CFGR,0);
			CLEAR_BIT(RCC->CFGR,1);
			break;
		case PLL:
			SET_BIT(RCC->CR,24);
			CLEAR_BIT(RCC->CFGR,0);
			SET_BIT(RCC->CFGR,1);
			break;
		case NON:
			SET_BIT(RCC->CFGR,0);
			SET_BIT(RCC->CFGR,1);
			break;
	}
}

void RCC_voidEnablePeriphralCLK(u8_t Copy_u8BusId ,u8_t Copy_u8PeriphralId)
{
	switch(Copy_u8BusId)
	{
		case RCC_u8_APB1_BUS : SET_BIT(RCC->APB1ENR,Copy_u8PeriphralId);break;
		case RCC_u8_APB2_BUS : SET_BIT(RCC->APB2ENR,Copy_u8PeriphralId);break;
		case RCC_u8_AHB_BUS : SET_BIT(RCC->AHBENR,Copy_u8PeriphralId);break;

	}
}

void RCC_voidDisablePeriphralCLK(u8_t Copy_u8BusId ,u8_t Copy_u8PeriphralId)
{
	switch(Copy_u8BusId)
		{
			case RCC_u8_APB1_BUS : CLEAR_BIT(RCC->APB1ENR,Copy_u8PeriphralId);break;
			case RCC_u8_APB2_BUS : CLEAR_BIT(RCC->APB2ENR,Copy_u8PeriphralId);break;
			case RCC_u8_AHB_BUS :  CLEAR_BIT(RCC->AHBENR,Copy_u8PeriphralId);break;
		}
}
