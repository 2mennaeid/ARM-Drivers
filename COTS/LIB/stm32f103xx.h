/*************************************  *************************************/
/***************** Name : Menna Eid     ************************************/
/***************** Date: 8/23/2023   ***********************************************/
/***************** Version: 1.0       *********************************************/
/***************** SWC: stm32f103xx   ********************************************/

#ifndef  STM32F103XX_h
#define  STM32F103XX_h

// RCC REGISTERS
#define RCC_u32_Base_ADDRESS   	  0x40021000

typedef  struct
{
    volatile u32_t CR;
	volatile u32_t CFGR;
	volatile u32_t CIR ;
	volatile u32_t APB2RSTR; 
	volatile u32_t APB1RSTR;
	volatile u32_t AHBENR;
	volatile u32_t APB2ENR;
	volatile u32_t APB1ENR;
	volatile u32_t BDCR;
	volatile u32_t CSR;  
}RCC_RegDef_t;

#define RCC         ((RCC_RegDef_t*)RCC_u32_Base_ADDRESS)

#endif
