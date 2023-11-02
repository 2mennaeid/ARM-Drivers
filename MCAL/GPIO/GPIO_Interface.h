/*
 * GPIO_Interface.h
 *
 *  Created on: Sep 24, 2023
 *  Author: Menna Eid
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_u8_HIGH           1
#define GPIO_u8_LOW            0

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15

}GPIO_PINS;
typedef enum
{
	HIGH,
	LOW
}Pin_Value_t;
/*************************************************************************************************/
typedef enum
{
	INPUT_PULLUP = 0b11000,
    INPUT_PULLDOWN =0b1000,
    INPUT_Floating = 0b0100,
	INPUT_ANALOG = 0b0000,
	OUTPUT_AF_PUSHPULL_10MHZ = 0b1001,
	OUTPUT_AF_PUSHPULL_50MHZ = 0b1011,
	OUTPUT_AF_PUSHPULL_2MHZ  = 0b1010,
	OUTPUT_AF_OPENDRAIN_10MHZ= 0b1101,
	OUTPUT_AF_OPENDRAIN_50MHZ= 0b1111,
	OUTPUT_AF_OPENDRAIN_2MHZ = 0b1110,
	OUTPUT_PUSHPULL_10MHZ = 0b0001,
	OUTPUT_PUSHPULL_50MHZ = 0b0011,
	OUTPUT_PUSHPULL_2MHZ  = 0b0010,
	OUTPUT_OPENDRAIN_10MHZ= 0b0101,
	OUTPUT_OPENDRAIN_50MHZ= 0b0111,
	OUTPUT_OPENDRAIN_2MHZ = 0b0110


}PIN_MODE;
/*************************************************************************************************/

typedef enum
{
	PORTA,
	PORTB,
	PORTC

}GPIO_PORT;
/*************************************************************************************************/
typedef struct
{
	GPIO_PORT PortId;
	GPIO_PINS PinId;
	PIN_MODE PinMode;

}GPIO_PinConfig_t;

/*************************************************************************************************/

ES_t GPIO_enuSetPinMode(GPIO_PinConfig_t*Copy_PsPinConfig);

ES_t GPIO_enuSetPinValue(GPIO_PinConfig_t*Copy_PsPinConfig,u8_t Copy_u8Value);

ES_t GPIO_enuGetPinValue(GPIO_PinConfig_t*Copy_PsPinConfig,u8_t*Copy_u8Value);

ES_t GPIO_enuTogglePin(GPIO_PinConfig_t*Copy_PsPinConfig);

ES_t GPIO_enuLockPin(GPIO_PinConfig_t*Copy_PsPinConfig);

#endif /* GPIO_INTERFACE_H_ */
