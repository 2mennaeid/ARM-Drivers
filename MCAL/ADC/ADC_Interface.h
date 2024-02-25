/*
 * ADC_Interface.h
 *
 *  Created on: Jan 27, 2024
 *      Author: Menna Eid
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_RES     4096
#define ADC_VREF    3300

typedef enum
{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC8,
	ADC9,
	ADC10,
	ADC11,
	ADC12,
	ADC13,
	ADC14,
	ADC15,
	ADC16,
	ADC17
}ADC_enCHANNELS;

typedef enum
{
	Single,
	Continuous,
	Scan_Single,
	Scan_Continuous
}ADC_MODE;


typedef enum
{
	Cycle_1,
	Cycle_7,
	Cycle_13,
	Cycle_28

}ADC_SampleTime;

typedef enum
{
	SQR1=1,
	SQR2,
	SQR3,
	SQR4,
	SQR5,
	SQR6,
	SQR7,
	SQR8,
	SQR9,
	SQR10,
	SQR11,
	SQR12,
	SQR13,
	SQR14,
	SQR15,
	SQR16

}ADC_Order_SQR;



ES_t ADC_enuInit(ADC_MODE enuMode);

ES_t ADC_SelectChannel(ADC_enCHANNELS enChannelId,ADC_Order_SQR enuSQR,u8_t Copy_u8NumOfConversion);

void ADC_vSetSampleTime(ADC_enCHANNELS enChannelId,ADC_SampleTime enuSampleTime);

void ADC_vStartConversion();

void ADC_vPollingSystem(void);

u16_t ADC_enuRead();

ES_t ADC_enuAnalogRead(u32_t*Copy_u32value);

#endif /* ADC_INTERFACE_H_ */
