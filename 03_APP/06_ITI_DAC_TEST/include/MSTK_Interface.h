/*
 * MSTK_Interface.h
 *
 *  Created on: May 12, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_


typedef enum
{
 MSTK_DISABLE = 0 ,
 MSTK_ENABLE
}MSTK_uddtSTK_State_t ;


typedef enum
{
 MSTK_INT_DISABLE = 0 ,
 MSTK_INT_ENABLE
}MSTK_uddtINTState_t ;

void MSTK_Init(void) ;
void MSTK_TimerStart(void) ;
void  _delay_ms(f32 Copy_u32Time);
void _delay_us(u32 Copy_u32Time)  ;
ES_t MSTK_errSetCallBackSTK(void (*PFunc) (void));
void MSTK_TimerStart_INT(f32 Copy_u32Time);
void MSTK_INT_Disable(void);
void MSTK_INT_Enable(f32 Copy_u32Time);
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) ) ;
#endif /* MSTK_INTERFACE_H_ */
