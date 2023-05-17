/**************************************************************************/
/*Author            : Kirollos Samir Ayad                                 */
/*Version           : V1.0.0                                              */
/*Date              : 14 MAY 2023                                         */
/*Description       : Program_File_For_Relay                              */
/*Features          :                                                     */
/*        - HRELAY_voidInit() 										      */
/*        - HRELAY_voidSetState()								          */
/*Future update     :                                                     */
/*       							                                      */
/**************************************************************************/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "HRELAY_Private.h"
#include "HRELAY_Interface.h"

/******************************************************************************/
/*                 HRELAY Functions implementation                            */
/******************************************************************************/



void MRELAY_voidInit(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum)
{
  /* Set the relay pin as output */
	MGPIO_errSetPinMode(Copy_uddtPortNum, Copy_uddtPinNum, MGPIO_MODE_OUTPUT);

  /* Set the relay output type as push-pull */
	MGPIO_errSetPinOutType(Copy_uddtPortNum, Copy_uddtPinNum, MGPIO_OUTPUT_PUSHPULL);

  /* Set the relay output speed as high */
	MGPIO_errSetPinOutSpeed(Copy_uddtPortNum, Copy_uddtPinNum, MGPIO_OUTPUT_HIGH_SPEED);

  /* Set the initial state to off (relay is typically active low) */
	MGPIO_errSetPullType(Copy_uddtPortNum, Copy_uddtPinNum, MGPIO_PULL_DOWN);
}

void MRELAY_voidSetState(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum, MGPIO_PinDataType Copy_uddtPinDataType)
{
  /* Set the relay state */
	MGPIO_errSetPinData(Copy_uddtPortNum, Copy_uddtPinNum, Copy_uddtPinDataType);
}
