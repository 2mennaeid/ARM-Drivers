/*
 * SYSTICK_Priv.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Menna Eid
 */

#ifndef SYSTICK_PRIV_H_
#define SYSTICK_PRIV_H_

typedef enum
{
	ENABLE,
	TICKINT,
    CLKSOURCE,
	COUNTFLAG=16
}STK_BITS;

#define STK_u8_PERIODIC_INTERVAL      1
#define STK_u8_SINGLE_INTERVAL      0

#endif /* SYSTICK_PRIV_H_ */
