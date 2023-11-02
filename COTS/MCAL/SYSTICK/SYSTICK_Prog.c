/*****************                     *****************************************/
/***************** Name : Menna Eid    ****************************************/
/***************** Date: 6/10/2023     ***************************************/
/***************** Version: 1.0        **************************************/
/***************** SWC: SYSTICK_PROG      *************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/stm32f103xx.h"
#include "../../LIB/errorstate.h"
#include "SYSTICK_Priv.h"
#include "SYSTICK_Interface.h"

f32 Tick_Time;
u8_t flag;
static void (*STK_Pfunc) (void) = NULLPTR;
ES_t SYSTICK_enuInit(SYSTICK_Prescaler_t Copy_enuPressValue)
{
	ES_t LocalErrorState = ES_OK;

	switch(Copy_enuPressValue)
	{
		case PRESSCALER_8:
			CLEAR_BIT(STK->CTRL,CLKSOURCE);
			Tick_Time =((f32)1/1000000U)*1000;
			break;
		case NO_PRESSCALER:
			SET_BIT(STK->CTRL,CLKSOURCE);
			Tick_Time = ((f32)1/8000000U)*1000;
			break;
		default:
			LocalErrorState = ES_NOK;
			break;
	}
	return LocalErrorState;
}

void  SYSTICK_voidEnable()
{

  SET_BIT(STK->CTRL,ENABLE);

}

void  SYSTICK_voidDisable()
{

	CLEAR_BIT(STK->CTRL,ENABLE);
	STK->LOAD = 0;
	STK->VAL = 0;
}

void SYSTICK_voidSetPreload(u32_t Copy_u32preload)
{

    STK->LOAD = Copy_u32preload;

}

void  SYSTICK_voidEnableInterrupet()
{
	SET_BIT(STK->CTRL,TICKINT);
}

void  SYSTICK_voidDisableInterrupet()
{
	CLEAR_BIT(STK->CTRL,TICKINT);
}

ES_t SYSTICK_enuDelay_ms_SingleInterval(u32_t Copy_u32delay,void (*STK_pf)(void))
{
	ES_t LocalErrorState = ES_OK;
	flag = 0;
	u32_t preload;
	if(Copy_u32delay <= 0x00FFFFFF && STK_pf!=NULL_PTR)
	{
		       /*set preload*/
				preload = Copy_u32delay / Tick_Time;
				SYSTICK_voidSetPreload(preload);
				/*Start Timer*/
				SYSTICK_voidEnable();
				SYSTICK_voidEnableInterrupet();
				STK_Pfunc = STK_pf;

	}
	else
	{
		LocalErrorState = ES_NOK;

	}


	return LocalErrorState;
}

ES_t SYSTICK_enuDelay_ms_PeriodicInterval(u32_t Copy_u32delay,void (*STK_pf)(void))
{
	ES_t LocalErrorState = ES_OK;
		flag = 1;
		u32_t preload;
		if(Copy_u32delay <= 0x00FFFFFF && STK_pf!=NULL_PTR)
			{
		         /*set preload*/
		 	   preload = Copy_u32delay / Tick_Time;
		 	   SYSTICK_voidSetPreload(preload);
		 	   /*Start Timer*/
		 	   SYSTICK_voidEnable();
		 	   SYSTICK_voidEnableInterrupet();
		 	   STK_Pfunc = STK_pf;

			}
		else
		{
			LocalErrorState = ES_NOK;

		}
		return LocalErrorState;
}

ES_t SYSTICK_enuDelay_ms(u32_t Copy_u32delay)
{
	   ES_t LocalErrorState = ES_OK;
		u32_t preload;
		if(Copy_u32delay > 0x00FFFFFF)
		{
			LocalErrorState = ES_NOK;

		}
		else
		{

			/*set preload*/
			preload = Copy_u32delay / Tick_Time;
			SYSTICK_voidSetPreload(preload);
			/*Start Timer*/
			SYSTICK_voidEnable();
			/*wait on flag  */
			while( READ_BIT(STK->CTRL,COUNTFLAG) == 0 );
		//	CLEAR_BIT(STK->CTRL,COUNTFLAG);
			/*stop timer*/
             SYSTICK_voidDisable();

		}
		return LocalErrorState;
}

ES_t SYSTICK_enuGetRemainingTime(u32_t*Copy_u32time)
{
	ES_t LocalErrorState = ES_OK;

	*Copy_u32time = STK->VAL;

	return LocalErrorState;
}

ES_t SYSTICK_enuGetElapsedTime(u32_t*Copy_u32time)
{
		ES_t LocalErrorState = ES_OK;

		*Copy_u32time = STK->LOAD - STK->VAL;

		return LocalErrorState;

}

void SysTick_Handler()
{
		if(flag == STK_u8_SINGLE_INTERVAL)
		{
		   SYSTICK_voidDisableInterrupet();
			/*stop timer*/
			SYSTICK_voidDisable();
		}
		if(STK_Pfunc != NULLPTR)
		{
			STK_Pfunc();
		}

}

