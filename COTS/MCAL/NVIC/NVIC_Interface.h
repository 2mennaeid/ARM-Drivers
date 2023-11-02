/*****************                     *****************************************/
/***************** Name : Menna Eid    ****************************************/
/***************** Date: 19/10/2023     ***************************************/
/***************** Version: 1.0        **************************************/
/***************** SWC: NVIC       *************************************/

#ifndef NVIC_INTERFACE_h
#define NVIC_INTERFACE_h

typedef enum
{
   INT_WWDG=0,
   INT_PVD,
   INT_TAMPER,
   INT_RTC,
   INT_FLASH,
   INT_RCC,
   INT_EXTI0,
   INT_EXTI1,
   INT_EXTI2,
   INT_EXTI3,
   INT_EXTI4,
   INT_DMA1_Channel1,
   INT_DMA1_Channel2,
   INT_DMA1_Channel3,
   INT_DMA1_Channel4,
   INT_DMA1_Channel5,
   INT_DMA1_Channel6,
   INT_DMA1_Channel7,
   INT_ADC1_2,
   INT_USB_HP_CAN_TX,
   INT_USB_HP_CAN_RX0,
   INT_CAN_RX1,
   INT_CAN_SCE,
   INT_EXTI5=23,
   INT_EXTI6=23,
   INT_EXTI7=23,
   INT_EXTI8=23,
   INT_EXTI9=23,
   INT_TIM1_BRK,
   INT_TIM1_UP,
   INT_TIM1_TRG_COM,
   INT_TIM1_CC,
   INT_TIM2,
   INT_TIM3,
   INT_TIM4,
   INT_I2C1_EV,
   INT_I2C1_ER,
   INT_I2C2_EV,
   INT_I2C2_ER,
   INT_SPI1,
   INT_SPI2,
   INT_USART1,
   INT_USART2,
   INT_USART3,
   INT_EXTI10=40,
   INT_EXTI11=40,
   INT_EXTI12=40,
   INT_EXTI13=40,
   INT_EXTI14=40,
   INT_EXTI15=40,
   INT_RTCAlarm,
   INT_USBWakeup,
   INT_TIM8_BRK,
   INT_TIM8_UP,
   INT_TIM8_TRG_COM,
   INT_TIM8_CC,
   INT_ADC3,
   INT_FSMC,
   INT_SDIO,
   INT_TIM5,
   INT_SPI3,
   INT_UART4,
   INT_UART5,
   INT_TIM6,
   INT_TIM7,
   INT_DMA2_Channel1,
   INT_DMA2_Channel2,
   INT_DMA2_Channel3,
   INT_DMA2_Channel4_5

}InterruptID_t;

ES_t NVIC_enuEnableInterrupt(InterruptID_t Copy_enuID);

ES_t NVIC_enuDisableInterrupt(InterruptID_t Copy_enuID);

ES_t NVIC_enuSetInterruptPending(InterruptID_t Copy_enuID);

ES_t NVIC_enuClearInterruptPending(InterruptID_t Copy_enuID);

ES_t NVIC_enuGetActive(InterruptID_t Copy_enuID,u8_t*Copy_u8InterruptStatus);

ES_t NVIC_enuSetPriorityGroup(InterruptID_t Copy_enuID,u8_t Copy_u8GroupPriority);
#endif
