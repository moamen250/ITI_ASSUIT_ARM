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


ES_t MSTK_errInit(void)
{
    // ENABLE STK INT - Clock = AHB/8 - Disable STK > SYSCLK = 16 MHZ -> STK_Frq = 2 MHZ , 0.5 Micro second
	MSTK->CTRL = 0x00000002 ;
}
ES_t MSTK_errTimerStart(void)
{
//TODO
}
void _delay_ms(u32 Copy_u32Time)
{
   //Initialize timer
	MSTK_errInit() ;
   //Disable INT
   CLR_BIT(MSTK->CTRL, 1 ) ;
   // LOAD_REG
   MSTK->LOAD = Copy_u32Time * 2000 ;
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
	MSTK_errInit() ;
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

