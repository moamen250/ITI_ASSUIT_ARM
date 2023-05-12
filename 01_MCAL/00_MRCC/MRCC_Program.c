/***********************************************************************************************************/
/* Authur               : John Salah Makar                                                                 */
/* Version              : V1.0.0                                                                           */
/* Date                 : 6 May 2023         													           */
/* Description          : "MRCC_Program.c" This File.c To Implementation The Of MRCC Driver     		   */
/***********************************************************************************************************/


/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MRCC_Private.h"
#include "MRCC_Config.h"
#include "MRCC_Interface.h"

/**************************************************************************/
/*                 MGPIO Functions implementation                         */
/**************************************************************************/


ES_t MRCC_errEnablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)
{
	ES_t LOC_uddtState = ES_OK ;
    switch(Copy_uddtBusName)
    {
    case MRCC_AHB1 : SET_BIT(MRCC_AHB1ENR,Copy_u8PerNum) ; break ;
    case MRCC_AHB2 : SET_BIT(MRCC_AHB2ENR,Copy_u8PerNum) ; break ;
    case MRCC_APB1 : SET_BIT(MRCC_APB1ENR,Copy_u8PerNum) ; break ;
    case MRCC_APB2 : SET_BIT(MRCC_APB2ENR,Copy_u8PerNum) ; break ;
    default :  /*ERROR*/                                   break ;
    }
    return LOC_uddtState ;
}


ES_t MRCC_errDisablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)
{
	ES_t LOC_uddtState = ES_OK ;
    switch(Copy_uddtBusName)
    {
    case MRCC_AHB1 : CLR_BIT(MRCC_AHB1ENR,Copy_u8PerNum) ; break ;
    case MRCC_AHB2 : CLR_BIT(MRCC_AHB2ENR,Copy_u8PerNum) ; break ;
    case MRCC_APB1 : CLR_BIT(MRCC_APB1ENR,Copy_u8PerNum) ; break ;
    case MRCC_APB2 : CLR_BIT(MRCC_APB2ENR,Copy_u8PerNum) ; break ;
    default :  /*ERROR*/                                   break ;
    }
    return LOC_uddtState ;
}
ES_t MRCC_errInitSystemClk(void)
{
	ES_t LOC_uddtState = ES_OK ;

    /****************** HSI ********************/
		/* 1- EN HSI
		 * 3- Switch HSI
		 * 4- Confirm -> read SWS bits
		 * */
		SET_BIT(MRCC_CR,0U) ;
		while(GET_BIT(MRCC_CR,1U) != READY) ;
		CLR_BIT(MRCC_CFGR,0U) ;
	    CLR_BIT(MRCC_CFGR,1U) ;

	/****************** HSE ********************/
	/*               Crystal Clock
	 * 1- EN HSE
	 * 2- Disable BYPASS
	 * 2- Wait till ready
	 * 3- Switch HSE
	 * 4- Confirm -> read SWS bits
	 * */
//	SET_BIT(MRCC_CR,16U) ;
//	CLR_BIT(MRCC_CR,18U) ;
//	while(GET_BIT(MRCC_CR,17U) != READY) ;
//	SET_BIT(MRCC_CFGR,0U) ;
//    CLR_BIT(MRCC_CFGR,1U) ;

    /*               Crystal Clock
    	 * 1- EN HSE
    	 * 2- Enable BYPASS
    	 * 2- Wait till ready
    	 * 3- Switch HSE
    	 * 4- Confirm -> read SWS bits
    	 * */

	/****************** PLL ********************/
    return LOC_uddtState ;

}

