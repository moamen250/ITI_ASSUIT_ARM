
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
}
ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType)
{
//TODO
}
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutType)
{
	/*	Initiat the error state variable to detect any error then return it  */
	ES_t Local_uddtError = ES_OK;
	/* Check if the input port found or not  , if found continue , if not return Error_OUT_OF_RANGE_PORT */
		switch(Copy_uddtPortNum)
		{
			case MGPIO_PORTA :
			/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
				if((u8)Copy_uddtPinNum < MGPOI_INVALID_PIN)
				{			/* First mode  : OUTPUT_PUSHPULL */ 
					if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
					{	/* config OTYPER register by setting bit  */
						SET_BIT(GPIOA_OTYPER ,Copy_uddtPinNum);
					}		/* Second mode  : OUTPUT_OPERDRAIN */ 
					else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
					{	/* config OTYPER register by Clearing bit  */
						CLR_BIT(GPIOA_OTYPER ,Copy_uddtPinNum);
					}
					else 
					{	/* No More Modes to config , return NOT OK */
						Local_uddtError = ES_NOK ;
					}
				}
				else 
				{	/* the user enterd pin not in this port */
					Local_uddtError = ES_OUT_OF_RANGE_PIN ;
				}
			break;
			case MGPIO_PORTB :
			/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
				if((u8)Copy_uddtPinNum < MGPOI_INVALID_PIN)
				{			/* First mode  : OUTPUT_PUSHPULL */ 
					if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
					{	/* config OTYPER register by setting bit  */
						SET_BIT(GPIOB_OTYPER ,Copy_uddtPinNum);
					}		/* Second mode  : OUTPUT_OPERDRAIN */ 
					else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
					{	/* config OTYPER register by Clearing bit  */
						CLR_BIT(GPIOB_OTYPER ,Copy_uddtPinNum);
					}
					else 
					{	/* No More Modes to config , return NOT OK */
						Local_uddtError = ES_NOK ;
					}
				}
				else 
				{	/* the user enterd pin not in this port */
					Local_uddtError = ES_OUT_OF_RANGE_PIN ;
				}
			break;
			case MGPIO_PORTC :
			/* Check if the input PIN in port A in range  0 -> 15  or not , if not return Error_OUT_OF_RANGE_PIN */
				if((u8)Copy_uddtPinNum < MGPOI_INVALID_PIN && Copy_uddtPinNum >= MGPIO_PIN13)
				{			/* First mode  : OUTPUT_PUSHPULL */ 
					if(Copy_u8PinOutType == MGPIO_OUTPUT_PUSHPULL )
					{	/* config OTYPER register by setting bit  */
						SET_BIT(GPIOC_OTYPER ,Copy_uddtPinNum);
					}		/* Second mode  : OUTPUT_OPERDRAIN */ 
					else if (Copy_u8PinOutType == MGPIO_OUTPUT_OPERDRAIN)
					{	/* config OTYPER register by Clearing bit  */
						CLR_BIT(GPIOC_OTYPER ,Copy_uddtPinNum);
					}
					else 
					{	/* No More Modes to config , return NOT OK */
						Local_uddtError = ES_NOK ;
					}
				}
				else 
				{	/* The user enterd pin not in this port */
					Local_uddtError = ES_OUT_OF_RANGE_PIN ;
				}
			break;
			default :	/* The user enterd port not in this MC*/
				Local_uddtError = ES_OUT_OF_RANGE_PORT ;
			break;
		}/* Return Error Status */
		return Local_uddtError ;
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




