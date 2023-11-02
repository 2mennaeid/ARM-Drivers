/*
 * GPIO_Prog.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Menna Eid
 */


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"
#include "../../LIB/errorstate.h"
#include "GPIO_Priv.h"
#include "GPIO_Interface.h"

static GPIO_RegDef_t*GPIO_APS[3] = {GPIO_PORTA,GPIO_PORTB,GPIO_PORTC};

ES_t GPIO_enuSetPinMode(GPIO_PinConfig_t*Copy_PsPinConfig)
{
	ES_t LoclaErrorState = ES_OK;
	u8_t Local_u8PinMode = Copy_PsPinConfig->PinMode;
	u8_t Local_u8PinId = Copy_PsPinConfig->PinId;
	if(Copy_PsPinConfig!=NULLPTR)
	{
		if((Copy_PsPinConfig->PortId>=PORTA)&&(Copy_PsPinConfig->PortId<=PORTC))
		{
			/*Check if Pullup */
			if(Copy_PsPinConfig->PinMode==INPUT_PULLUP)
			{
				/*set ODR */
				SET_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_ODR,Copy_PsPinConfig->PinId);
				Local_u8PinMode &= ~(1<<4);

			}
			else if(Copy_PsPinConfig->PinMode==INPUT_PULLDOWN)
			{
				/*clear ODR */
				CLEAR_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_ODR,Copy_PsPinConfig->PinId);
			}
					/*Set bits of CRL*/
			if(Copy_PsPinConfig->PinId<PIN8)
			{
				/*clear 4 bits*/
				GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_CRL &=((~(0b1111))<<(Copy_PsPinConfig->PinId*4));
				/*set mode */
				GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_CRL |=(Local_u8PinMode<<(Copy_PsPinConfig->PinId*4));
			}
				/*Set bits of CRH*/
			else if(Copy_PsPinConfig->PinId>=PIN8)
			{
				Local_u8PinId -= 8;
				/*clear 4 bits*/
				GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_CRL &=((~(0b1111))<<(Local_u8PinId*4));
				/*set mode */
				GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_CRH |=(Local_u8PinMode<<(Local_u8PinId*4));
			}
		}
		else
		{
			LoclaErrorState = ES_NOK;
		}
	}

	else
	{
		LoclaErrorState = ES_NOK;
	}

	return LoclaErrorState;
}

ES_t GPIO_enuSetPinValue(GPIO_PinConfig_t*Copy_PsPinConfig,u8_t Copy_u8Value)
{
	ES_t LoclaErrorState = ES_OK;
	if(Copy_PsPinConfig!=NULLPTR)
	{
		if(Copy_PsPinConfig->PortId>=PORTA && Copy_PsPinConfig->PortId<=PORTC)
		{
			SET_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_ODR,Copy_PsPinConfig->PinId);
		}
		else
		{
			LoclaErrorState = ES_NOK;
		}
	}
	else
	{
		LoclaErrorState = ES_NOK;
	}

	return LoclaErrorState;
}

ES_t GPIO_enuGetPinValue(GPIO_PinConfig_t*Copy_PsPinConfig,u8_t*Copy_u8Value)
{
	ES_t LoclaErrorState = ES_OK;
	if(Copy_PsPinConfig!=NULLPTR && Copy_u8Value!= NULLPTR)
	{
			if(Copy_PsPinConfig->PortId>=PORTA && Copy_PsPinConfig->PortId<=PORTC)
			{
				*Copy_u8Value = READ_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_ODR,Copy_PsPinConfig->PinId);
			}
			else
			{
				LoclaErrorState = ES_NOK;
			}
	}
	else
	{
		LoclaErrorState = ES_NOK;
	}
	return LoclaErrorState;
}

ES_t GPIO_enuTogglePin(GPIO_PinConfig_t*Copy_PsPinConfig)
{
	ES_t LoclaErrorState = ES_NOK;
	if(Copy_PsPinConfig!=NULLPTR)
	{
			if(Copy_PsPinConfig->PortId>=PORTA && Copy_PsPinConfig->PortId<=PORTC)
			{
				TOOGLE_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_ODR,Copy_PsPinConfig->PinId);
			}
			else
			{
				LoclaErrorState = ES_NOK;
			}
	}
	else
	{
		LoclaErrorState = ES_NOK;
	}
	return LoclaErrorState;
}

ES_t GPIO_enuLockPin(GPIO_PinConfig_t*Copy_PsPinConfig)
{
	ES_t LoclaErrorState = ES_OK;
	if(Copy_PsPinConfig!=NULLPTR)
	{
		if(Copy_PsPinConfig->PortId>=PORTA && Copy_PsPinConfig->PortId<=PORTC)
		{
			SET_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_LCKR,Copy_PsPinConfig->PinId);
			/*LOCK key writing sequence*/
			SET_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_LCKR,16);
			CLEAR_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_LCKR,16);
			if(READ_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_LCKR,16)==LOW)
			{
				if(READ_BIT(GPIO_APS[Copy_PsPinConfig->PortId]->GPIO_LCKR,16)==HIGH)
				{
					LoclaErrorState = ES_OK;
				}
			}
			else
			{
				LoclaErrorState = ES_NOK;
			}


		}
		else
		{
			LoclaErrorState = ES_NOK;
		}
	}
	else
	{
		LoclaErrorState = ES_NOK;
	}
	return LoclaErrorState;
}

