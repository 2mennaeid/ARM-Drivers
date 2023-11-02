/*****************                     *****************************************/
/***************** Name : Menna Eid    ****************************************/
/***************** Date: 8/18/2023     ***************************************/
/***************** Version: 1.0        **************************************/
/***************** SWC: Bit math       *************************************/
#ifndef BIT_MATH_h
#define BIT_MATH_h

#define SET_BIT(PORT,PIN)          (PORT |= (1<<PIN))
#define CLEAR_BIT(PORT,PIN)        (PORT &= ~(1<<PIN))
#define READ_BIT(PORT,PIN)         ((PORT>>PIN)&1)
#define TOOGLE_BIT(PORT,PIN)       (PORT ^= (1<<PIN))

#endif