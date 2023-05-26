/************************************************************************************************/
/* Authur               : AHMED HAMMA                                                           */
/* Version              : V1.0.0                                                                */
/* Date                 : 12 May 2023         												    */
/* Description          : "MSTK_Program.c" This File.c To Implementation The Of MSTKK Driver    */
/************************************************************************************************/


/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MSTK_Private.h"
#include "MSTK_Config.h"
#include "MSTK_Interface.h"

/**************************************************************************/
/*                 MGPIO Functions implementation                         */
/**************************************************************************/
void (*MSTK_PFunk_CallBack)(void);
f32 GLO_u32Time= 0;
/***************************************************************************************/
void MSTK_Init(void)
{
#if CLKSOURCE ==AHB
	SET_BIT(MSTK->CTRL,CLK_BIN);
#elif CLKSOURCE ==AHB_8
	CLR_BIT(MSTK->CTRL,CLK_BIN);
#endif
}
/***************************************************************************************/

void MSTK_INT_Enable(f32 Copy_u32Time)
{
	// ENABLE STK INT - Clock = AHB/8 - Disable STK > SYSCLK = 16 MHZ -> STK_Frq = 2 MHZ , 0.5 Micro second
	//MSTK->CTRL = 0x00000002 ;
	 MSTK_TimerStart_INT(Copy_u32Time);
}
/***************************************************************************************/
void MSTK_INT_Disable(void)
{
	CLR_BIT(MSTK->CTRL,1);
}
/***************************************************************************************/
void MSTK_TimerStart_INT(f32 Copy_u32Time)
{
	GLO_u32Time = Copy_u32Time ;
	CLR_BIT(MSTK->CTRL, 0 ) ;
	CLR_BIT(MSTK->CTRL,16);
	CLR_BIT(MSTK->CTRL, 1 ) ;
	// LOAD_REG
	MSTK->LOAD =(u32 )(Copy_u32Time * 2000.0) ;
	// VAL with any value -> Immediate Reload
	MSTK->VAL = 0 ;
	// Enable Timer
	SET_BIT(MSTK->CTRL, ENABLE_BIN ) ;
	SET_BIT(MSTK->CTRL,1);
}
/***************************************************************************************/
ES_t MSTK_errSetCallBackSTK(void (*PFunc) (void))
{
	if(PFunc != NULL)
	{
	MSTK_PFunk_CallBack=PFunc;
	return ES_OK;
	}
	else
		return ES_NOK;
}
/***************************************************************************************/
void SysTick_Handler(void)
{
	if(MSTK_PFunk_CallBack != NULL)
		{
	      MSTK_PFunk_CallBack();
	      CLR_BIT(MSTK->CTRL, 0 ) ;
	      	MSTK->LOAD =(u32 )(GLO_u32Time * 2000.0) ;
	      	// VAL with any value -> Immediate Reload
	      	MSTK->VAL = 0 ;
	      	SET_BIT(MSTK->CTRL, 0 ) ;
		}
	else
	{
		CLR_BIT(MSTK->CTRL, 0 ) ;
	}
	CLR_BIT(MSTK->CTRL,16);
}
/***************************************************************************************/
void _delay_ms(f32 Copy_u32Time)
{
	//Initialize timer
	MSTK_Init() ;
	//Disable INT
	CLR_BIT(MSTK->CTRL, 1 ) ;
	// LOAD_REG
	MSTK->LOAD =(u32 )(Copy_u32Time * 2000) ;
	// VAL with any value -> Immediate Reload
	MSTK->VAL = 0 ;
	// Enable Timer
	SET_BIT(MSTK->CTRL, 0 ) ;
	// Polling
	while(GET_BIT(MSTK->CTRL,16) == 0) ;
	// Stop Timer
	CLR_BIT(MSTK->CTRL, 0 ) ;
}
/******************************************************************************/
/*                           02_ MGPIO_errSetPinData                          */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> Set Delay by MicroSec---->>_delay_us            */
/* 2- Function Input       ->                                                 */
/*                     @param u32 Copy_u32Time                                */
/*                                                                            */
/* 3- Function Return      -> void                                            */
/*                                                                            */
/******************************************************************************/
/* Clock = AHB/8 - Disable STK > SYSCLK = 16 MHZ -> STK_Frq = 2 MHZ , 0.5 Micro second */
void _delay_us(u32 Copy_u32Time)
{
	//Initialize timer
	MSTK_Init() ;
	//Disable INT
	CLR_BIT(MSTK->CTRL, 1 ) ;
	// LOAD_REG
	MSTK->LOAD = Copy_u32Time * 2 ;
	// VAL with any value -> Immediate Reload
	MSTK->VAL = 0 ;
	// Enable Timer
	SET_BIT(MSTK->CTRL, 0 ) ;
	// Polling
	while(GET_BIT(MSTK->CTRL,16) == 0) ;
	// Stop Timer
	CLR_BIT(MSTK->CTRL, 0 ) ;
}
/***************************************************************************************/

