
/**************************************************************************/
/*Author            : Mohamed Sayed EL_Gawy                               */
/*Version           : V1.0.0                                              */
/*Date              : 6 MAY 2023                                          */
/*Description       : MGPIO_Program.c                                     */
/*Features          :                                                     */
/*        - MGPIO_errSetPinMode()                                         */
/*        - MGPIO_errSetPinData()                                         */
/*        - MGPIO_errGetPinData()                                         */
/*        - MGPIO_errSetPullType()                                        */
/*        - MGPIO_errSetPinOutType()                                      */
/*        - MGPIO_errSetPinOutSpeed()                                     */
/*        - MGPIO_errSetPinLock()                                         */
/*        - MGPIO_errSetOrResetPinAtomic()                                */
/*        - MGPIO_errSetPinAltFun()                                       */
/*Future update     :                                                     */
/*        - Write Some APIs or PORT                                       */
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

#include "MGPIO_Private.h"
#include "MGPIO_Config.h"
#include "MGPIO_Inteface.h"

/******************************************************************************/
/*                 MGPIO Functions implementation                             */
/*                        MGPIO Functions implementation                      */
/******************************************************************************/



ES_t MGPIO_errSetPinMode(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinMode)
{
//TODO
}
ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue)
{
//TODO
}
ES_t MGPIO_errGetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 *Copy_pu8PinMode)
{
//TODO
}
ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType)
{
//TODO
}
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutType)
{
//TODO
}
ES_t MGPIO_errSetPinOutSpeed(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutSpeed)
{
	/*Chick for ES_OUT_OF_RANGE_PORT */
	if (Copy_uddtPortNum >= MGPOI_INVALID_PORT )
	{
		return ES_OUT_OF_RANGE_PORT;
	}
	else
	{
		/*Chick for ES_OUT_OF_RANGE_Pin */
		if(Copy_uddtPinNum >= MGPOI_INVALID_PIN )
		{
			return ES_OUT_OF_RANGE_PIN;
		}
		else
		{
			/*Chick for ES_OUT_OF_RANGE_PIN in PORT C*/
			if ((Copy_uddtPortNum == MGPIO_PORTC) && (Copy_uddtPinNum > MGPIO_PIN2))
			{
				return ES_OUT_OF_RANGE_PIN;
			}
			else
			{
				/*Chick for ES_OUT_OF_RANGE_Speed */
				if (Copy_u8PinOutSpeed > MGPIO_OUTPUT_VHIGH_SPEED )
				{
					return ES_NOK;
				}
				else
				{
					/*0xFFFFFFF3  is clearing mask*/
					CLR_BITS(GPIOA_OSPEEDR,0xFFFFFFF3);
					SET_BITS(GPIOA_OSPEEDR,Copy_u8PinOutSpeed);
				}
			}
		}




}
ES_t MGPIO_errSetPinLock()
{
//TODO
}
ES_t MGPIO_errSetOrResetPinAtomic()
{
//TODO
}
ES_t MGPIO_errSetPinAltFun()
{
//TODO
}




