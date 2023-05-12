
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
 ES_t state=OK;
	 switch(Copy_uddtPortNum)
	{
	  case MGPIO_PORTA : GPIOA_MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	  case MGPIO_PORTB : GPIOB_MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	  case MGPIO_PORTC : GPIOC_MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	  
	  default : state=NOK; break ;
    }
	return state;
}
/**
 *
 * @param Copy_uddtPortNum
 * @param Copy_uddtPinNum
 * @param Copy_u8PinValue
 * @return  ES_t
 */
/******************************************************************************/
/*                      implementation  MGPIO_errSetPinData                   */
/******************************************************************************/

ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue)
{
                                                           /* define local error state and initialize by ES_OK */
	ES_t Local_ES_t=ES_OK;
                                                          /* switch to port number */
	switch(Copy_uddtPortNum)
	{
	                                                       /* port A  */
	case MGPIO_PORTA:
		                                                   /* check if bin number out of range */
		if(Copy_uddtPinNum>MGPIO_PIN15 || Copy_uddtPinNum<MGPIO_PIN0 )
		{
			                                               /* if bin number out of range Local_ES_t equal  ES_OUT_OF_RANGE_PIN */
			Local_ES_t=ES_OUT_OF_RANGE_PIN;
		}
		else
		{                                                 /* if bin number in the range  */
			                                              /* switch to pin value (pin low or pin high) */
			switch(Copy_u8PinValue)
			{                                             /* if pin value equal pin low */
			case MGPIO_PIN_LOW:
				                                          /* clear pin */
				CLR_BIT(GPIOA_ODR,Copy_uddtPinNum);
				break;
				                                          /* if pin value equal pin high */
			case MGPIO_PIN_HIGH:
				                                          /* set pin */
				SET_BIT(GPIOA_ODR,Copy_uddtPinNum);
				break;
			default:
				                                         /*  if pin value out of range */
				                                         /*  Local_ES_t = ES_OUT_OF_VALUE_PIN */
				Local_ES_t=ES_OUT_OF_VALUE_PIN;
				break;

			}
		}

		break;
	case MGPIO_PORTB:
		                                               /* check if bin number out of range */
		if(Copy_uddtPinNum>MGPIO_PIN15 || Copy_uddtPinNum<MGPIO_PIN0 )
		{
		                                               /* if bin number out of range Local_ES_t equal  ES_OUT_OF_RANGE_PIN */
			Local_ES_t=ES_OUT_OF_RANGE_PIN;
		}
		                                               /* if bin number in the range  */
		else
		{
		                                               /* switch to pin value (pin low or pin high) */
			switch(Copy_u8PinValue)
			{
			                                           /* if pin value equal pin low */
			case MGPIO_PIN_LOW:
				                                       /* clear pin */
				CLR_BIT(GPIOB_ODR,Copy_uddtPinNum);
				break;
				                                       /* if pin value equal pin high */
			case MGPIO_PIN_HIGH:
				                                       /* set bit */
				SET_BIT(GPIOB_ODR,Copy_uddtPinNum);
				break;
			default:
				                                       /*  if pin value out of range */
				                                       /*  Local_ES_t = ES_OUT_OF_VALUE_PIN */
				Local_ES_t=ES_OUT_OF_VALUE_PIN;
				break;

			}
		}

		break;
	case MGPIO_PORTC:
		                                               /* check if bin number out of range */
		if(Copy_uddtPinNum>MGPIO_PIN2 || Copy_uddtPinNum<MGPIO_PIN0 )
		{
			                                           /* if bin number out of range Local_ES_t equal  ES_OUT_OF_RANGE_PIN */
			Local_ES_t=ES_OUT_OF_RANGE_PIN;
		}
		else                                           /* if bin number in the range  */
		{
			                                           /* switch to pin value (pin low or pin high) */
			switch(Copy_u8PinValue)
			{
			                                           /* if pin value equal pin low */
			case MGPIO_PIN_LOW:
				                                       /* clear pin */
				CLR_BIT(GPIOC_ODR,Copy_uddtPinNum);
				break;
				                                       /* if pin value = pin high */
			case MGPIO_PIN_HIGH:
				                                       /* set bit */
				SET_BIT(GPIOC_ODR,Copy_uddtPinNum);
				break;
			default:
				                                       /*  if pin value out of range */
				Local_ES_t=ES_OUT_OF_VALUE_PIN;        /*  Local_ES_t equal ES_OUT_OF_VALUE_PIN */
				break;

			}
		}

		break;
	default:                                          /*  if port number out of range */
		Local_ES_t=ES_OUT_OF_RANGE_PORT;              /*  Local_ES_t equal ES_OUT_OF_RANGE_PORT */
		break;

    return Local_ES_t;                                /*  return Local_ES_t */



	}

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
//TODO
}
ES_t MGPIO_errSetPinLock( MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum)
{
//TODO
}
ES_t MGPIO_errSetOrResetPinAtomic(MGPIO_uddtPortNum Copy_uddtPortNum,u32 MGPIO_Pin_Value)
{
//TODO
}
ES_t MGPIO_errSetPinAltFun(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 GPIO_AFSelection )
{
//TODO
}




