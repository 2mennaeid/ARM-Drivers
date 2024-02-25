/*
 * ADC_Prog.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Menna Eid
 */

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"
#include "../../LIB/errorstate.h"
#include "../RCC/RCC_Priv.h"
#include "../RCC/RCC_Interface.h"
#include "../GPIO/GPIO_Priv.h"
#include "../GPIO/GPIO_Interface.h"
#include "ADC_Interface.h"

ES_t ADC_enuInit(ADC_MODE enuMode)
{
	ES_t LocalErrorState = ES_OK;
	/*Enable RCC for ADC*/
	RCC_voidEnablePeriphralCLK(RCC_u8_APB2_BUS,9);
	RCC_voidEnablePeriphralCLK(RCC_u8_APB2_BUS,0);
	/* Enable RCC for GPIOA*/
	RCC_voidEnablePeriphralCLK(RCC_u8_APB2_BUS,2);


	/*select Mode*/
	switch(enuMode)
	{
		case Continuous:
			SET_BIT(ADC->CR2,1);
			break;
		case Single:
			CLEAR_BIT(ADC->CR2,1);
			break;
		case Scan_Single:
			SET_BIT(ADC->CR1,8);
			CLEAR_BIT(ADC->CR2,1);
			break;
		case Scan_Continuous:
			SET_BIT(ADC->CR1,8);
			SET_BIT(ADC->CR2,1);
			break;
		default:
			LocalErrorState = ES_NOK;
			break;

	}
	/*set Data alignment : right*/
	CLEAR_BIT(ADC->CR2,11);
    /* set prescaler -->4*/
	RCC->CFGR |= (1<<14);
	/*Enable ADC */
	SET_BIT(ADC->CR2,0);
	return LocalErrorState;
}

ES_t ADC_SelectChannel(ADC_enCHANNELS enChannelId,ADC_Order_SQR enuSQR,u8_t Copy_u8NumOfConversion)
{
	ES_t LocalErrorState = ES_NOK;
	u8_t bit_index =0;
	Copy_u8NumOfConversion -= 1;
	//u8_t Local_u8PinMode  = 0b0000;
	/*set channel in SQRx*/
	if(enuSQR<=6)
	{
		bit_index = 5*(enuSQR-1);
		ADC->SQR3 |= (enChannelId<< bit_index);
	}
	else if(enuSQR>6 && enuSQR<=12)
	{
		bit_index =  (5*(enuSQR-1)) - 30;
		ADC->SQR2 |= (enChannelId<< bit_index);
	}
	else if(enuSQR>12)
	{
		bit_index =  (5*(enuSQR-1)) - 60;
		ADC->SQR1 |= (enChannelId<< bit_index);

	}
	/*set regular channel sequence length*/
	ADC->SQR1 |= (Copy_u8NumOfConversion<< 20);
	return LocalErrorState;
}

void ADC_vSetSampleTime(ADC_enCHANNELS enChannelId,ADC_SampleTime enuSampleTime)
{
		u8_t bit_index =0;
		/*set sample time*/
		if(enChannelId<=9)
		{
			bit_index = 3*enChannelId;
			ADC->SMPR2 |= (enuSampleTime<<bit_index);
		}
		else if(enChannelId>9)
		{
			bit_index = (3*enChannelId)-30;
			ADC->SMPR1 |= (enuSampleTime<<bit_index);
		}
}
void ADC_vStartConversion()
{
    ADC->CR2 |= (7<<17);
    SET_BIT(ADC->CR2,22);
}

void ADC_vPollingSystem(void)
{
	if(READ_BIT(ADC->SR,4)==1)
	{
		/*waiting for EOC*/
		while(READ_BIT(ADC->SR,1)==0);
		CLEAR_BIT(ADC->SR,1);
	}

}

u16_t ADC_enuRead()
{
	u16_t Copy_u16value;
	Copy_u16value = ADC->DR;
	return Copy_u16value;
}

ES_t ADC_enuAnalogRead(u32_t*Copy_u32value)
{
	ES_t LocalErrorState = ES_OK;
		u16_t Copy_u16value;
		Copy_u16value = ADC_enuRead();
		if(Copy_u32value!=NULLPTR)
		{

			*Copy_u32value = (Copy_u16value*ADC_VREF)/ADC_RES;
		}
		else
		{
			LocalErrorState = ES_NOK;
		}
		return LocalErrorState;
}
