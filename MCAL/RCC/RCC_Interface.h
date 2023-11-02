/*****************                     *****************************************/
/***************** Name : Menna Eid    ****************************************/
/***************** Date: 8/18/2023     ***************************************/
/***************** Version: 1.0        **************************************/
/***************** SWC: RCC            *************************************/

#ifndef RCC_Interface_h
#define RCC_Interface_h

#include "RCC_Priv.h"
/*Macros for Buses*/
#define RCC_u8_AHB_BUS           0
#define RCC_u8_APB1_BUS          1
#define RCC_u8_APB2_BUS          2

void RCC_voidSelectClock(CLOCK_TYPES enuclk_type);

void RCC_voidEnablePeriphralCLK(u8_t Copy_u8BusId ,u8_t Copy_u8PeriphralId);

void RCC_voidDisablePeriphralCLK(u8_t Copy_u8BusId ,u8_t Copy_u8PeriphralId);

#endif
