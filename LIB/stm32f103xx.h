/*************************************  *************************************/
/***************** Name : Menna Eid     ************************************/
/***************** Date: 8/23/2023   ***********************************************/
/***************** Version: 2.0       *********************************************/
/***************** SWC: stm32f103xx   ********************************************/

#ifndef  STM32F103XX_h
#define  STM32F103XX_h

/***************************************************RCC Registers*****************************************************/

#define RCC_u32_Base_ADDRESS   	 		 0x40021000U


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
}RCC_RegDef_t;

#define RCC         ((RCC_RegDef_t*)RCC_u32_Base_ADDRESS)
/**********************************************************************************************************************/

/***************************************************GPIO Registers*****************************************************/

#define GPIO_PORTA_u32_BASE_ADDRESS  	 0x40010800U
#define GPIO_PORTB_u32_BASE_ADDRESS  	 0x40010C00U
#define GPIO_PORTC_u32_BASE_ADDRESS  	 0x40011000U

typedef struct
{
	volatile u32_t GPIO_CRL;
	volatile u32_t GPIO_CRH;
	volatile u32_t GPIO_IDR;
	volatile u32_t GPIO_ODR;
	volatile u32_t GPIO_BSRR;
	volatile u32_t GPIO_BRR;
	volatile u32_t GPIO_LCKR;
}GPIO_RegDef_t;

#define GPIO_PORTA       ((GPIO_RegDef_t*)GPIO_PORTA_u32_BASE_ADDRESS)
#define GPIO_PORTB       ((GPIO_RegDef_t*)GPIO_PORTB_u32_BASE_ADDRESS)
#define GPIO_PORTC       ((GPIO_RegDef_t*)GPIO_PORTC_u32_BASE_ADDRESS)

/**********************************************************************************************************************/
/***************************************************SYSTICK Registers*****************************************************/

#define SYSTICK_u32_Base_ADDRESS   	 		  0xE000E010U

typedef struct
{
	volatile u32_t CTRL;
	volatile u32_t LOAD;
	volatile u32_t VAL;
	volatile u32_t CALIB;

}SYSTICK_RegDef_t;

#define STK                     ((SYSTICK_RegDef_t*)SYSTICK_u32_Base_ADDRESS)


/**********************************************************************************************************************/

/***************************************************NCVIC Registers*****************************************************/

#define NVIC_u32_Base_ADDRESS   	 		   0xE000E100U

typedef struct
{
	volatile u32_t ISER[32];
	volatile u32_t ICER[32];
	volatile u32_t ISPR[32];
	volatile u32_t ICPR[32];
	volatile u32_t IABR[64];
	volatile u32_t IPR[9];

}NVIC_RegDef_t;

#define NVIC                     ((NVIC_RegDef_t*)NVIC_u32_Base_ADDRESS)


/**********************************************************************************************************************/
/***************************************************DMA Registers*****************************************************/

#define DMA_u32_Base_ADDRESS   	 		   0x40020000U

typedef struct
{
	volatile u32_t ISR;
	volatile u32_t IFCR;
	volatile u32_t CCR1;
	volatile u32_t CNDTR1;
	volatile u32_t CPAR1;
	volatile u32_t CMAR1;
	volatile u32_t _Reserved0;
	volatile u32_t CCR2;
	volatile u32_t CNDTR2;
	volatile u32_t CPAR2;
	volatile u32_t CMAR2;
	volatile u32_t CCR3;
	volatile u32_t CNDTR3;
	volatile u32_t CPAR3;
	volatile u32_t CMAR3;
	volatile u32_t _Reserved1;
	volatile u32_t CCR4;
	volatile u32_t CNDTR4;
	volatile u32_t CPAR4;
	volatile u32_t CMAR4;
	volatile u32_t _Reserved2;
	volatile u32_t CCR5;
	volatile u32_t CNDTR5;
	volatile u32_t CPAR5;
	volatile u32_t CMAR5;
	volatile u32_t _Reserved3;
	volatile u32_t CCR6;
	volatile u32_t CNDTR6;
	volatile u32_t CPAR6;
	volatile u32_t CMAR6;
	volatile u32_t _Reserved4;
	volatile u32_t CCR7;
	volatile u32_t CNDTR7;
	volatile u32_t CPAR7;
	volatile u32_t CMAR7;


}DMA_RegDef_t;

#define DMA                     ((DMA_RegDef_t*)DMA_u32_Base_ADDRESS)


/**********************************************************************************************************************/

#endif

