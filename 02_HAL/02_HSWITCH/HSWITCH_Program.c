/**************************************************************************/
/* Author     : John Salah Makar                                          */
/* Version    : V1.0.0                                                    */
/*Date        : 13 May 2023                                               */
/*Description : HSWITCH_Interface.h                                       */
/*Features    : -HSWITCH_errInit()                                        */
/*              -HSWITCH_errON()                                          */
/*              -HSWITCH_errOFF()                                         */
/**************************************************************************/

/**************************************************************************/
/*                              Standard Types                            */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"
#include "MGPIO_Inteface.h"
/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/
#include "HSWITCH_Config.h"
#include "HSWITCH_Interface.h"
#include "HSWITCH_Private.h"
#include "MRCC_Interface.h"
#define HLED_PIN  MGPIO_PIN0
#define HLED_PORT MGPIO_PORTA

/**************************************************************************/
/*                         Function Implementation                        */
/**************************************************************************/
ES_t HSWITCH_errInit(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum)
{
	ES_t Local_errState = ES_OK;

	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA :
		/* ENABLE RCC */
		MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOA_EN);
		/* Select PIN MODE*/
		MGPIO_errSetPinMode(MGPIO_PORTA,Copy_uddtPinNum,MGPIO_MODE_INPUT);
		/* SELECT PULL TYPE*/
		MGPIO_errSetPullType(MGPIO_PORTA,Copy_uddtPinNum,MGPIO_PULL_DOWN);
		break;
	case MGPIO_PORTB :
		/* ENABLE RCC */
		MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOB_EN);
		/*SELECT PIN MODE*/
		MGPIO_errSetPinMode(MGPIO_PORTB,Copy_uddtPinNum,MGPIO_MODE_INPUT);
		/*SELECT PULL TYPE*/
		MGPIO_errSetPullType(MGPIO_PORTB,Copy_uddtPinNum,MGPIO_PULL_DOWN);
		break;
	case MGPIO_PORTC :
		/* ENABLE RCC*/
		MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOC_EN);
		/* SELECT PIN MODE*/
		MGPIO_errSetPinMode(MGPIO_PORTB,Copy_uddtPinNum,MGPIO_MODE_INPUT);
		/*SELECT PULL TYPE*/
		MGPIO_errSetPullType(MGPIO_PORTC,Copy_uddtPinNum,MGPIO_PULL_DOWN);
		break;
	default: Local_errState = ES_NOK;
		break;
	}

	return Local_errState;
}
u8 HSWITCH_u8GetSwitchState(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum)
{
	u8 LOC_SwitchState;
	MGPIO_errGetPinData(Copy_uddtPortNum,Copy_uddtPinNum,&LOC_SwitchState);
	return LOC_SwitchState;
}






