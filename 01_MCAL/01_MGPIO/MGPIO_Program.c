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
/******************************************************************************/


ES_t MGPIO_errSetPinMode(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinMode)
{
	ES_t LOC_uddtState= ES_OK;
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA : MGPIOA->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum )) ;
	MGPIOA->MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	case MGPIO_PORTB : MGPIOB->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum )) ;
	MGPIOB->MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	case MGPIO_PORTC : MGPIOC->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum )) ;
	MGPIOC->MODER  |= (u32) ( Copy_u8PinMode << ( 2* Copy_uddtPinNum )) ; break;
	default : LOC_uddtState=ES_NOK   ; break ;
	}
	return LOC_uddtState;
}

/******************************************************************************/
/*                           02_ MGPIO_errSetPinData                          */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> Set pin value                                   */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_uddtPortNum                                */
/*                     @param Copy_uddtPinNum                                 */
/*                     @param Copy_u8PinValue                                 */
/* 3- Function Return      -> @return  ES_t                                   */
/*       [ ES_OK ,  ES_NOK , ES_OUT_OF_RANGE_PIN, ES_OUT_OF_RANGE_PORT ,      */
/*        ES_OUT_OF_RANGE_PIN_MODE                                            */
/******************************************************************************/

ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue)
{

	ES_t LOC_uddtState= ES_OK;
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PORTA :
		if(Copy_u8PinValue == MGPIO_PIN_LOW)
		{
			MGPIOA->ODR  &= ~(u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		else
		{
			MGPIOA->ODR  |= (u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		break ;
	case MGPIO_PORTB :
		if(Copy_u8PinValue == MGPIO_PIN_LOW)
		{
			MGPIOB->ODR  &= ~(u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		else
		{
			MGPIOB->ODR  |= (u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		break ;
	case MGPIO_PORTC :
		if(Copy_u8PinValue == MGPIO_PIN_LOW)
		{
			MGPIOC->ODR  &= ~(u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		else
		{
			MGPIOC->ODR  |= (u32) ( 1 << (Copy_uddtPinNum )) ;
		}
		break ;
	default : LOC_uddtState=ES_NOK   ; break ;
	}
	return LOC_uddtState;

}

ES_t MGPIO_errGetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 *Copy_pu8PinValue)
{
	//TODO
	ES_t Local_ErrorState = ES_OK ;
	if(Copy_pu8PinValue != NULL)
	{
		switch(Copy_uddtPortNum)
		{
		case MGPIO_PORTA:
			*Copy_pu8PinValue = (GPIOA_IDR &(1U<<Copy_uddtPinNum));
			break;
		case MGPIO_PORTB:
			*Copy_pu8PinValue = (GPIOB_IDR &(1U<<Copy_uddtPinNum));
			break;
		case MGPIO_PORTC:
			*Copy_pu8PinValue = (GPIOC_IDR &(1U<<Copy_uddtPinNum));
			break;
		default:
			break;
		}
	}
	else
	{
		Local_ErrorState =	ES_NULL_POINTER;
	}

	return  Local_ErrorState ;
}

ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType)
{
	/*FUNCTION TO SELECT PIN PULL TYPE*/
	//variable to return error state
	ES_t Local_ErrState = ES_OK;
	switch (Copy_uddtPortNum)
	{
	   case MGPIO_PORTA: MGPIOA->PUPDR &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum ));
	        MGPIOA->PUPDR |= (Copy_u8PullType << (2 * Copy_uddtPinNum));
	        break;
	  case MGPIO_PORTB: MGPIOB->PUPDR &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum ));
	       MGPIOB->PUPDR |= (Copy_u8PullType << (2 * Copy_uddtPinNum));
	       break;
   	  case MGPIO_PORTC: MGPIOC->PUPDR &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_uddtPinNum ));
           MGPIOC->PUPDR |= (Copy_u8PullType << (2 * Copy_uddtPinNum));
	       break;
	  default: 	 	  Local_ErrState = ES_NOK;
	       break;
	}
	return Local_ErrState;
}
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutType)
{
	//	/*	Initiat the error state variable to detect any error then return it  */
	ES_t Local_uddtError = ES_OK;
	//	/* Check if the input port found or not  , if found continue , if not return Error_OUT_OF_RANGE_PORT */
	//	switch(Copy_uddtPortNum)
	//	{
	//	case MGPIO_PORTA :
	//		/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
	//		if((u8)Copy_uddtPinNum < MGPIO_INVALID_PIN)
	//		{			/* First mode  : OUTPUT_PUSHPULL */
	//			if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
	//			{	/* config OTYPER register by setting bit  */
	//				SET_BIT(GPIOA_OTYPER ,Copy_uddtPinNum);
	//			}		/* Second mode  : OUTPUT_OPERDRAIN */
	//			else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
	//			{	/* config OTYPER register by Clearing bit  */
	//				CLR_BIT(GPIOA_OTYPER ,Copy_uddtPinNum);
	//			}
	//			else
	//			{	/* No More Modes to config , return NOT OK */
	//				Local_uddtError = ES_NOK ;
	//			}
	//		}
	//		else
	//		{	/* the user enterd pin not in this port */
	//			Local_uddtError = ES_OUT_OF_RANGE_PIN ;
	//		}
	//		break;
	//	case MGPIO_PORTB :
	//		/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
	//		if((u8)Copy_uddtPinNum < MGPOI_INVALID_PIN)
	//		{			/* First mode  : OUTPUT_PUSHPULL */
	//			if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
	//			{	/* config OTYPER register by setting bit  */
	//				SET_BIT(GPIOB_OTYPER ,Copy_uddtPinNum);
	//			}		/* Second mode  : OUTPUT_OPERDRAIN */
	//			else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
	//			{	/* config OTYPER register by Clearing bit  */
	//				CLR_BIT(GPIOB_OTYPER ,Copy_uddtPinNum);
	//			}
	//			else
	//			{	/* No More Modes to config , return NOT OK */
	//				Local_uddtError = ES_NOK ;
	//			}
	//		}
	//		else
	//		{	/* the user enterd pin not in this port */
	//			Local_uddtError = ES_OUT_OF_RANGE_PIN ;
	//		}
	//		break;
	//	case MGPIO_PORTC :
	//		/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
	//		if((u8)Copy_uddtPinNum < MGPOI_INVALID_PIN && Copy_uddtPinNum >= MGPIO_PIN13)
	//		{			/* First mode  : OUTPUT_PUSHPULL */
	//			if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
	//			{	/* config OTYPER register by setting bit  */
	//				SET_BIT(GPIOC_OTYPER ,Copy_uddtPinNum);
	//			}		/* Second mode  : OUTPUT_OPERDRAIN */
	//			else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
	//			{	/* config OTYPER register by Clearing bit  */
	//				CLR_BIT(GPIOC_OTYPER ,Copy_uddtPinNum);
	//			}
	//			else
	//			{	/* No More Modes to config , return NOT OK */
	//				Local_uddtError = ES_NOK ;
	//			}
	//		}
	//		else
	//		{	/* The user enterd pin not in this port */
	//			Local_uddtError = ES_OUT_OF_RANGE_PIN ;
	//		}
	//		break;
	//	default :	/* The user enterd port not in this MC*/
	//		Local_uddtError = ES_OUT_OF_RANGE_PORT ;
	//		break;
	//	}/* Return Error Status */
	return Local_uddtError ;
}
ES_t MGPIO_errSetPinOutSpeed(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutSpeed)
{
	/*Chick for ES_OUT_OF_RANGE_PORT */
	//	if (Copy_uddtPortNum >= MGPOI_INVALID_PORT )
	//	{
	//		return ES_OUT_OF_RANGE_PORT;
	//	}
	//	else
	//	{
	//		/*Chick for ES_OUT_OF_RANGE_Pin */
	//		if(Copy_uddtPinNum >= MGPOI_INVALID_PIN )
	//		{
	//			return ES_OUT_OF_RANGE_PIN;
	//		}
	//		else
	//		{
	//			/*Chick for ES_OUT_OF_RANGE_PIN in PORT C*/
	//			if ((Copy_uddtPortNum == MGPIO_PORTC) && (Copy_uddtPinNum > MGPIO_PIN2))
	//			{
	//				return ES_OUT_OF_RANGE_PIN;
	//			}
	//			else
	//			{
	//				/*Chick for ES_OUT_OF_RANGE_Speed */
	//				if (Copy_u8PinOutSpeed > MGPIO_OUTPUT_VHIGH_SPEED )
	//				{
	//					return ES_NOK;
	//				}
	//				else
	//				{
	//					/*0xFFFFFFF3  is clearing mask*/
	//					CLR_BITS(GPIOA_OSPEEDR,0xFFFFFFF3);
	//					SET_BITS(GPIOA_OSPEEDR,Copy_u8PinOutSpeed);
	//				}
	//			}
	//		}
	//
	//
	//

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

ES_t MGPIO_errSetPortData(MGPIO_uddtPortNum Copy_uddtPortNum,u32 Copy_u8PortValue)
{
	ES_t LOC_uddtState= ES_OK;
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PORTA : MGPIOA->ODR = Copy_u8PortValue ;    break;
	case MGPIO_PORTB : MGPIOB->ODR = Copy_u8PortValue ;    break;
	case MGPIO_PORTC : MGPIOC->ODR = Copy_u8PortValue ;    break;
	default : LOC_uddtState=ES_NOK                    ;    break ;
	}
	return LOC_uddtState;
}



