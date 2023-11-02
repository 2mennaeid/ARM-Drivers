#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/errorstate.h"
#include "../../LIB/stm32f103xx.h"
#include "NVIC_Priv.h"
#include "NVIC_Interface.h"

ES_t NVIC_enuEnableInterrupt(InterruptID_t Copy_enuID)
{
	ES_t LocalErrorState = ES_OK;
	u8_t Local_Id = Copy_enuID;
		if(Copy_enuID<32)
		{

			SET_BIT(NVIC->ISER[0],Copy_enuID);
		}
		else if(Copy_enuID>31 && Copy_enuID<64)
		{
			/*ISR[1]*/
			Local_Id -= 32;
			SET_BIT(NVIC->ISER[1],Local_Id);

		}
		else if (Copy_enuID>=64 && Copy_enuID<=95)
		{
			/*ISR[2]*/
			Local_Id -= 64;
			SET_BIT(NVIC->ISER[2],Local_Id);
		}
		else
		{
			LocalErrorState = ES_NOK;
		}
	return LocalErrorState;
}

ES_t NVIC_enuDisableInterrupt(InterruptID_t Copy_enuID)
{
	ES_t LocalErrorState = ES_OK;
	u8_t Local_Id = Copy_enuID;
	if(Copy_enuID<32)
	{
		SET_BIT(NVIC->ICER[0],Copy_enuID);
	}
	else if(Copy_enuID>31 && Copy_enuID<64)
	{
		Local_Id -= 32;
		SET_BIT(NVIC->ICER[1],Copy_enuID);
	}
	else if (Copy_enuID>=64 && Copy_enuID<=95)
	{
		Local_Id -= 64;
		SET_BIT(NVIC->ICER[2],Copy_enuID);
	}
	else
	{
		LocalErrorState = ES_NOK;
	}
	return LocalErrorState;
}

ES_t NVIC_enuSetInterruptPending(InterruptID_t Copy_enuID)
{
	ES_t LocalErrorState = ES_OK;
	u8_t Local_Id = Copy_enuID;
	if(Copy_enuID<32)
	{
		SET_BIT(NVIC->ISPR[0],Copy_enuID);
	}
	else if(Copy_enuID>31 && Copy_enuID<64)
	{
		Local_Id -= 32;
		SET_BIT(NVIC->ISPR[1],Local_Id);
	}
	else if (Copy_enuID>=64 && Copy_enuID<=95)
	{
		Local_Id -= 64;
		SET_BIT(NVIC->ISPR[1],Local_Id);
	}
	else
	{
		LocalErrorState = ES_NOK;
	}
	return LocalErrorState;
}

ES_t NVIC_enuClearInterruptPending(InterruptID_t Copy_enuID)
{
	ES_t LocalErrorState = ES_OK;
	u8_t Local_Id = Copy_enuID;
	if(Copy_enuID<32)
	{
		SET_BIT(NVIC->ICPR[0],Copy_enuID);
	}
	else if(Copy_enuID>31 && Copy_enuID<64)
	{
		Local_Id -= 32;
		SET_BIT(NVIC->ICPR[1],Local_Id);
	}
	else if (Copy_enuID>=64 && Copy_enuID<=95)
	{
		Local_Id -= 64;
		SET_BIT(NVIC->ICPR[2],Local_Id);
	}
	else
	{
		LocalErrorState = ES_NOK;
	}
	return LocalErrorState;
}

ES_t NVIC_enuGetActive(InterruptID_t Copy_enuID,u8_t*Copy_u8InterruptStatus)
{
	ES_t LocalErrorState = ES_OK;
	u8_t Local_Id = Copy_enuID;
  if(Copy_u8InterruptStatus!=NULLPTR)
  {
	if(Copy_enuID<32)
	{
		*Copy_u8InterruptStatus = READ_BIT(NVIC->IABR[0],Copy_enuID);
	}
	else if(Copy_enuID>31 && Copy_enuID<64)
	{
		Local_Id -=32;
		*Copy_u8InterruptStatus = READ_BIT(NVIC->IABR[1],Local_Id);
	}
	else if (Copy_enuID>=64 && Copy_enuID<=95)
	{
		Local_Id -=64;
		*Copy_u8InterruptStatus = READ_BIT(NVIC->IABR[2],Local_Id);
	}
	else
	{
		LocalErrorState = ES_NOK;
	}
  }
  else
  {
	  LocalErrorState = ES_NOK;
  }
	return LocalErrorState;
}
ES_t NVIC_enuSetPriorityGroup(InterruptID_t Copy_enuID,u8_t Copy_u8GroupPriority)
{

}
