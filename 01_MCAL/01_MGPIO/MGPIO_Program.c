
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
    ES_t Local_ErrorState ;
    Local_ErrorState =ES_OK;
    if(Copy_pu8PinMode!=Null)
    {
        switch(Copy_uddtPortNum)
        {
        case GPIOA:
            *Copy_pu8PinMode = (GPIOA_IDR &(1U<<Copy_uddtPinNum));
            break;
        case GPIOB:
            *Copy_pu8PinMode = (GPIOB_IDR &(1U<<Copy_uddtPinNum));
            break;
        case GPIOC:
            *Copy_pu8PinMode = (GPIOC_IDR &(1U<<Copy_uddtPinNum));
            break;
        case GPIOD:
            *Copy_pu8PinMode = (GPIOD_IDR &(1U<<Copy_uddtPinNum));
            break;
        case GPIOE:
            *Copy_pu8PinMode = (GPIOE_IDR &(1U<<Copy_uddtPinNum));
            break;

        default:
            break;
        }
		else
		{    Local_ErrorState =	ES_NOK,
;

			
		}
    }
	return  Local_ErrorState ;

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
//TODO
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




