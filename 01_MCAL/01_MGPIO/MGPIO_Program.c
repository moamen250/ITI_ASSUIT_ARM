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

/***********************************************************************************************************************************************************************/
/*                                                                                   MGPIO Functions implementation                                                                                                              */
/***********************************************************************************************************************************************************************/
#if MGPIO_PIN_APIs          ==          MGPIO_ENABLE
/***********************************************************************************************************************************************************************/

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

/******************************************************************************************************************************************************************/
/*                                                05_ MGPIO_errSetPinOutType                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Initialize the output type of a specific pin  ( OUTPUT PUSHPULL or OUTPUT OPERDRAIN )   @ref MGPIO_OutputCircuit                     */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtPortNum number of port   @ref MGPIO_uddtPortNum                                                                                */
/*               @param : Copy_uddtPinNum  number of pin      @ref MGPIO_uddtPinNum                                                                               */
/*               @param :Copy_u8PinOutType number of type    @ref MGPIO_OutputCircuit                                                                             */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (ES_OUT_OF_RANGE_PIN)     : The user enter number of PIN more than PORT PINs  or negative number                                      */
/*                              (ES_OUT_OF_RANGE_PORT)  : The user enter number of PORT more than MC PORTs  or negative number                                   */
/*                              (ES_WRONG_MODE_VALUE) : The user enter wrong value to configure specific mode or negative value                                 */
/******************************************************************************************************************************************************************/
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,MGPIO_OutputCircuit Copy_u8PinOutType)
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t LOC_uddtState = ES_OK;
	/************************************************************************StartOFChecking***************************************************************************/
	/* Check if the input PIN out of range  0 -> 15  , IF yes, return Error_OUT_OF_RANGE_PIN */
	if (   (  (  (u8) Copy_uddtPinNum) > MGPIO_PIN15  )  )	{   LOC_uddtState  = ES_OUT_OF_RANGE_PIN ; 	}
	/* Check if the input PORT out of range A -> C , IF yes , return ES_OUT_OF_RANGE_PORT */
	else if ((((u8)Copy_uddtPortNum ) > MGPIO_PORTC ) ) { LOC_uddtState =  ES_OUT_OF_RANGE_PORT ;}
	/* PORT C  have 3 PINs  13->15 , IF the user entered pin not in this port , return Error_OUT_OF_RANGE_PIN  */
	else  if ((((u8)Copy_uddtPortNum) == MGPIO_PORTC ) && ((u8) Copy_uddtPinNum) < MGPIO_PIN13 ){   LOC_uddtState  = ES_OUT_OF_RANGE_PIN ; 	}
	/* First mode  : OUTPUT_PUSHPULL   , The PORT & PIN in the right range  */
	else if  ( Copy_u8PinOutType  == MGPIO_OUTPUT_PUSHPULL  ){ GPIOx_REG( Copy_uddtPortNum )->OTYPER &= ~( 1U << Copy_uddtPinNum); }
	/* Second mode  : OUTPUT_OPERDRAIN , The PORT & PIN in  the right  range */
	else if( Copy_u8PinOutType  == MGPIO_OUTPUT_OPERDRAIN ){ GPIOx_REG( Copy_uddtPortNum )->OTYPER |=    ( 1U << Copy_uddtPinNum); }
	/* the user entered wrong value or negative  */
	else {  LOC_uddtState  = ES_WRONG_MODE_VALUE;}
	/*************************************************************************EndOFChecking***************************************************************************/
	return      LOC_uddtState ;                                 /* Return Error Status */
}
/******************************************************************************************************************************************************************/

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
/**************************************************************************/
#endif
/******************************************************************************************************************************************************************/

#if MGPIO_GROUP_OF_PINs_APIs          ==          MGPIO_ENABLE

/******************************************************************************************************************************************************************/
/*                                                01_ MGPIO_errSetPINsGroupMode                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Initialize the operation mode of group of pins  ( INPUT or OUTPUT  or ALTF or ANALOG )   @ref MGPIO_PinMode                     */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtPortNum number of port     @ref MGPIO_uddtPortNum                                                                                */
/*               @param : Copy_uddtPINsGroup  value of pins      @ref MGPIO_PINsGroup                                                                              */
/*               @param :Copy_uddtGroupMode number of type    @ref MGPIO_GroupMode                                                                             */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (ES_WRONG_PINs_VALUE)    : The user enter value of PINs equal to zero ( no pins to configure ), or PINs not in PORT C           */
/*                              (ES_OUT_OF_RANGE_PORT)  : The user enter number of PORT more than MC PORTs  or negative number                                   */
/*                              (ES_WRONG_MODE_VALUE) : The user enter wrong value to configure specific mode or negative value                                 */
/******************************************************************************************************************************************************************/
ES_t MGPIO_errSetPINsGroupMode(MGPIO_uddtPortNum Copy_uddtPortNum,u16 Copy_uddtPINsGroup,MGPIO_PinMode Copy_uddtGroupMode)
{
	ES_t LOC_uddtState          = ES_OK; 	/*	Initiate  The Error State variable to detect any error then return it  */
	u32 LOC_uddtPUTOnes   = 0;           	/*	Initiate  The Reset variable to clear the register before write the mode value  */
	u32 LOC_uddtPUTMode = 0;           /*	Initiate  The Mode variable to write on the register with the total value  */
	u32 LOC_uddtPINsNum  = 0;           /*	Initiate  The PIN number variable to save the number of PIN need to configure */
	/************************************************************************StartOFChecking***************************************************************************/
	/* Check if the input PINs Group == 0    , IF yes , return  ES_WRONG_PINs_VALUE */
	if      ( Copy_uddtPINsGroup  == 0U  )                                                   { LOC_uddtState  = ES_WRONG_PINs_VALUE ;}
	/* Check if the input MODE not found  , IF yes, return ES_WRONG_MODE_VALUE */
	else if ((((u8) Copy_uddtGroupMode) > MGPIO_MODE_ANALOG  )  )	{ LOC_uddtState  = ES_WRONG_MODE_VALUE ; }
	/* Check if the input PORT out of range A -> C , IF yes , return ES_OUT_OF_RANGE_PORT */
	else if ((((u8)Copy_uddtPortNum ) > MGPIO_PORTC ) )                    { LOC_uddtState =  ES_OUT_OF_RANGE_PORT ;}
	/* PORT C  have 3 PINs  13->15 , IF the user entered PINs Group not in this port , return ES_WRONG_PINs_VALUE  */
	else if ((((u8)Copy_uddtPortNum ) == MGPIO_PORTC ) && (( Copy_uddtPINsGroup | PINs_PORTC_MASK) > PINs_PORTC_MASK ))
	                                                                                                                      { LOC_uddtState =  ES_WRONG_PINs_VALUE ;}
	else    /* Start of operation   -NOW  The PORT & PINs  & MODE in the right  range    -   */
	{
		while ( Copy_uddtPINsGroup != 0U )
		{             /* Only chosen PINs  */
			if( Copy_uddtPINsGroup  & 1U )
			{                   /* Set Ones to clear the register before write & Set the Mode value to write it on the register */
				LOC_uddtPUTOnes   |= ( BITS_MODE_MASK    <<  ( LOC_uddtPINsNum * 2 ) ) ;
				LOC_uddtPUTMode |= ( Copy_uddtGroupMode <<  ( LOC_uddtPINsNum * 2 ) ) ;
			}
			Copy_uddtPINsGroup >>= 1U ; //NEXT PIN
			LOC_uddtPINsNum++;               //Number of  NEXT PIN
		}
		GPIOx_REG( Copy_uddtPortNum  )->MODER  &=  ~LOC_uddtPUTOnes ;  //Clear bits to write
		GPIOx_REG( Copy_uddtPortNum  )->MODER    |=   LOC_uddtPUTMode ;  //Write Mode
	}                      /* END of operation */
	/*************************************************************************EndOFChecking***************************************************************************/
	return      LOC_uddtState ;                                 /* Return Error Status */
}

/***********************************************************************************************************************************************************************/
/*                                                02_ MGPIO_errSetPINsGroupData                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Set the Logic output of group of pins  ( MGPIO_PIN_HIGH  or MGPIO_PIN_LOW )   @ref MGPIO_GroupDataLogic                     */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtPortNum number of port       @ref MGPIO_uddtPortNum                                                                                */
/*               @param : Copy_uddtPINsGroup  value of pins        @ref MGPIO_PINsGroup                                                                              */
/*               @param :Copy_uddtGroupLogic number of type    @ref MGPIO_GroupDataLogic                                                                             */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (ES_WRONG_PINs_VALUE)    : The user enter value of PINs equal to zero ( no pins to configure ), or PINs not in PORT C           */
/*                              (ES_OUT_OF_RANGE_PORT)  : The user enter number of PORT more than MC PORTs  or negative number                                   */
/******************************************************************************************************************************************************************/
ES_t MGPIO_errSetPINsGroupData(MGPIO_uddtPortNum Copy_uddtPortNum,u16 Copy_uddtPINsGroup,u16 Copy_uddtGroupLogic)
{
	ES_t LOC_uddtState          = ES_OK; 	/*	Initiate  The Error State variable to detect any error then return it  */
	/************************************************************************StartOFChecking***************************************************************************/
	/* Check if the input PINs Group == 0    , IF yes , return  ES_WRONG_PINs_VALUE */
	if      ( Copy_uddtPINsGroup  == 0U  )                                                   { LOC_uddtState  = ES_WRONG_PINs_VALUE ;}
	/* Check if the input PORT out of range A -> C , IF yes , return ES_OUT_OF_RANGE_PORT */
	else if ((((u8)Copy_uddtPortNum ) > MGPIO_PORTC ) )                     { LOC_uddtState =  ES_OUT_OF_RANGE_PORT ;}
	/* PORT C  have 3 PINs  13->15 , IF the user entered PINs Group not in this port , return ES_WRONG_PINs_VALUE  */
	else if ((((u8)Copy_uddtPortNum ) == MGPIO_PORTC ) && (( Copy_uddtPINsGroup | PINs_PORTC_MASK) > PINs_PORTC_MASK ))
	                                                                                                                      { LOC_uddtState =  ES_WRONG_PINs_VALUE ;}
	else                                                                      /* Start of operation */
	{	       /* PINsGroup is Ones so can complement them to clear the register before write  *//*  Set the GroupLogic value to write it on the register */
		GPIOx_REG( Copy_uddtPortNum  )->ODR    &=  ~Copy_uddtPINsGroup;
		GPIOx_REG( Copy_uddtPortNum  )->ODR    |=   ( Copy_uddtPINsGroup & Copy_uddtGroupLogic ) ;  //Set bits for only needed PINs
	}
                                                                                   /* END of operation */
	/*************************************************************************EndOFChecking***************************************************************************/
	return      LOC_uddtState ;                                 /* Return Error Status */
}
#endif
/***********************************************************************************************************************************************************************/
#if MGPIO_PORTs_APIs                            ==          MGPIO_ENABLE
/***********************************************************************************************************************************************************************/
//TODO
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
/***********************************************************************************************************************************************************************/
#endif
/***********************************************************************************************************************************************************************/

