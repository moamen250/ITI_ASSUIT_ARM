/**************************************************************************/
/*       Author             : MOAMEN MAMDOUH THABET                       */
/*       Version            : V1.0.0                                      */
/*       Date               : 16 May 2023                                 */
/*       Description        : HBUZ_Program.c                              */
/*             This File.c To Implementation The Of BUZZER Driver         */
/**************************************************************************/


/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            MCAL   Files                                */
/**************************************************************************/

#include "MRCC_Interface.h"
#include "MGPIO_Inteface.h"
#include "MSTK_Interface.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "HBUZ_Private.h"
#include "HBUZ_Config.h"
#include "HBUZ_Interface.h"

/**************************************************************************/
/*                 MGPIO Functions implementation                         */
/**************************************************************************/

/******************************************************************************/
/*                           01_ HBUZZ_errInt                                 */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> Initialize Buzzer                               */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_uddtPortNum                                */
/*                     @param Copy_uddtBuzzNum                                */
/* 3- Function Return      -> @return  ES_t                                   */
/* [ ES_OK ,  HBUZ_ES_PIN_Invalid , HBUZ_ES_PORT_Invalid,                     */
/******************************************************************************/
ES_t HBUZZ_errInt(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum)
{
	ES_t LOC_uddtErrorState = ES_OK;
	/* Enable GPIO Clock Peripheral  */
	LOC_uddtErrorState =MRCC_errEnablePeripherialClk(MRCC_AHB1,Copy_uddtPortNum);
	/* Configure PINS As output */
	LOC_uddtErrorState = MGPIO_errSetPinMode(Copy_uddtPortNum , Copy_uddtBuzzNum ,MGPIO_MODE_OUTPUT);

	return LOC_uddtErrorState;
}
/******************************************************************************/
/*                           02_ HBUZZ_errOn                                  */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> Set  Buzzer                                     */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_uddtPortNum                                */
/*                     @param Copy_uddtBuzzNum                                */
/* 3- Function Return      -> @return  ES_t                                   */
/* [ HBUZ_ES_OK ,  HBUZ_ES_PIN_Invalid , HBUZ_ES_PORT_Invalid]                */
/******************************************************************************/
ES_t HBUZZ_errOn(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum)
{
	ES_t LOC_uddtErrorState = ES_OK;

	/* SET PINS As High */
	LOC_uddtErrorState = MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtBuzzNum,MGPIO_PIN_HIGH);

	return LOC_uddtErrorState;
}
/******************************************************************************/
/*                           03_ HBUZZ_errOf                                  */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> turn off  Buzzer                                */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_uddtPortNum                                */
/*                     @param Copy_uddtBuzzNum                                */
/* 3- Function Return      -> @return  HBUZ_ErrStatus_t                       */
/* [ ES_OK ,  HBUZ_ES_PIN_Invalid , HBUZ_ES_PORT_Invalid]                     */
/******************************************************************************/
ES_t HBUZZ_errvOff(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum)
{
	ES_t LOC_uddtErrorState = ES_OK;
	/* Clear PINS  To Turn off Buzzer */
	LOC_uddtErrorState =	MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtBuzzNum,MGPIO_PIN_LOW);

	return LOC_uddtErrorState;
}
/******************************************************************************/
/*                           04_ HBUZZ_errFlip                                */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> SET a specific numbers of tones                 */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_uddtPortNum                                */
/*                     @param Copy_uddtBuzzNum                                */
/*                     @param copy_u8NumTone                                  */
/* 3- Function Return      -> @return  HBUZ_ErrStatus_t                       */
/* [ HBUZ_ES_OK ,  HBUZ_ES_PIN_Invalid , HBUZ_ES_PORT_Invalid]                */
/******************************************************************************/
ES_t HBUZZ_errFlip(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum,u8 copy_u8NumTone)
{
	u8 Loc_Iteration=0;
	ES_t LOC_uddtErrorState = ES_OK;
	/* LOOP for Turn Buzzer A specific Number of Tones */
	for(Loc_Iteration=0;Loc_Iteration<copy_u8NumTone;Loc_Iteration++)
	{
		/* Configure PINS As High */
		LOC_uddtErrorState=	MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtBuzzNum,MGPIO_PIN_HIGH);
		/* polling to 1 second */
		_delay_ms(1000);
		/* Configure PINS As LOW */
		LOC_uddtErrorState= MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtBuzzNum,MGPIO_PIN_LOW);
	}

	return LOC_uddtErrorState;
}




