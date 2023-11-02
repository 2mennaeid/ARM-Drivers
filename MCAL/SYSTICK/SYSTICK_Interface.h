/*
 * SYSTICK_Interface.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Menna Eid
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

typedef enum
{
	PRESSCALER_8,
	NO_PRESSCALER

}SYSTICK_Prescaler_t;

ES_t SYSTICK_enuInit(SYSTICK_Prescaler_t Copy_enuPressValue);

void  SYSTICK_voidEnable();

void  SYSTICK_voidDisable();

void SYSTICK_voidSetPreload(u32_t Copy_u32preload);

ES_t SYSTICK_enuDelay_ms_SingleInterval(u32_t Copy_u32delay,void (*STK_pf)(void));

ES_t SYSTICK_enuDelay_ms(u32_t Copy_u32delay);

ES_t SYSTICK_enuDelay_ms_PeriodicInterval(u32_t Copy_u32delay,void (*STK_pf)(void));

void  SYSTICK_voidEnableInterrupet();

ES_t SYSTICK_enuGetRemainingTime(u32_t*Copy_u32time);

ES_t SYSTICK_enuGetElapsedTime(u32_t*Copy_u32time);

//ES_t SYSTICK_enuCallBack();

void SysTick_Handler();
#endif /* SYSTICK_INTERFACE_H_ */
