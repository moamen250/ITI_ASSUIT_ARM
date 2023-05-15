/***********************************************************************************************************************************************/
/* Author :                                             Mohamed Yehia El-Greatly                                                               */
/* Description :                                            HCLCD_Program.c                                                                    */
/***********************************************************************************************************************************************/
/* Version :V1.0.0                                                                                                                             */
/* Date :     13 May 2023                                                                                                                      */
/***********************************************************************************************************************************************/
/*                                                      Include  LIB Files                                                                     */
/***********************************************************************************************************************************************/
#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"
/***********************************************************************************************************************************************/
/*                                                  Include Peripherals Files                                                                  */
/***********************************************************************************************************************************************/
#include  "MRCC_Interface.h"
#include  "MGPIO_Inteface.h"
#include  "MSTK_Interface.h"
#include  "HCLCD_Private.h"
#include  "HCLCD_Config.h"
#include  "HCLCD_Interface.h"
/***********************************************************************************************************************************************/
/*                                                 HCLCD Functions implementation                                                              */
/***********************************************************************************************************************************************/
/*                                                          01_ HCLCD_errInit                                                                  */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                            */
/***********************************************************************************************************************************************/
/* 1- Function Description                                                                                                                     */
/*               @brief    : Initialize the operation mode of the LCD   ( 4-Bit or 8-Bit  )   @ref Configuration File   &  LCD Data Sheet      */
/* 2- Function Return                                                                                                                          */
/*               @return Error status of the function                                                                                          */
/*                              (E_OK) : The function done successfully                                                                        */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                  */
/***********************************************************************************************************************************************/
ES_t HCLCD_errInit (void)
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
/***********************************************************************************************************************************************/
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )
/***********************************************************************************************************************************************/

	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORT_CLOCK);  //configure port clock and pin direction
	Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_D4,HCLCD_D7) , MGPIO_MODE_OUTPUT);
	Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To( HCLCD_RS , HCLCD_E ) , MGPIO_MODE_OUTPUT);
	_delay_ms(1)  ; //power on delay
	Local_uddtError = HCLCD_errSendCommand(HLCD_4BITM_CMD);            //configure 4-Bit mode
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DDRAM__First_CMD);

/***********************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )
/***********************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTData_CLK);
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTControl_CLK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_DataPINs , MGPIO_PINs_From_To(HCLCD_D4 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ControlPINs , MGPIO_PINs_From_To(HCLCD_RS ,HCLCD_E )  , MGPIO_MODE_OUTPUT);
	_delay_ms(1)  ;
	Local_uddtError = HCLCD_errSendCommand(HLCD_4BITM_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DDRAM__First_CMD);
/***********************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )
/***********************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORT_CLOCK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_D0 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_RS,HCLCD_E) , MGPIO_MODE_OUTPUT);
	_delay_ms(1)  ;
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
/***********************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )
/***********************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTData_CLK);
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTControl_CLK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_DataPINs , MGPIO_PINs_From_To(HCLCD_D0 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ControlPINs , MGPIO_PINs_From_To(HCLCD_RS,HCLCD_E)  , MGPIO_MODE_OUTPUT);
	_delay_ms(1)  ;
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
/***********************************************************************************************************************************************/
#endif
/***********************************************************************************************************************************************/
	return Local_uddtError;
}
/***********************************************************************************************************************************************/
/*                                                          02_ HCLCD_errClearDisplay                                                          */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                            */
/***********************************************************************************************************************************************/
/* 1- Function Description                                                                                                                     */
/*               @brief    :  Clear Screen       @ref LCD Data Sheet                                                                           */
/* 2- Function Return                                                                                                                          */
/*               @return Error status of the function                                                                                          */
/*                              (E_OK) : The function done successfully                                                                        */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                  */
/***********************************************************************************************************************************************/
ES_t  HCLCD_errClearDisplay(void)
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
/***********************************************************************************************************************************************/
	Local_uddtError =HCLCD_errSendCommand(HLCD_CLR_CMD);
/***********************************************************************************************************************************************/
	return Local_uddtError;
}
/***********************************************************************************************************************************************/
/*                                                03_ HCLCD_errSendData                                                                        */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                            */
/***********************************************************************************************************************************************/
/* 1- Function Description                                                                                                                     */
/*               @brief    : Send data to LCD  ( To Configure or Display  )   @ref LCD Data Sheet                                              */
/* 2- Function Input                                                                                                                           */
/*               @param : Copy_uddtData  data      @ref HCLCD_Char                                                                             */
/* 3- Function Return                                                                                                                          */
/*               @return Error status of the function                                                                                          */
/*                              (E_OK) : The function done successfully                                                                        */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                  */
/***********************************************************************************************************************************************/
ES_t  HCLCD_errSendData( HCLCD_Char  Copy_uddtData )
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
/***********************************************************************************************************************************************/
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )
	/* First Send   Bits  From Bit 7 To Bit 4    then  Send  Bits from  Bit 3 to bit 1            */
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData>>4)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(1)  ;

#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

	/* First Send   Bits  From Bit 7 To Bit 4    then  Send  Bits from  Bit 3 to bit 1            */
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_DataPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData>>4)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_DataPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(1)  ;

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtData<<HCLCD_D0));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(1)  ;
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_DataPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtData<<HCLCD_D0));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(1)  ;
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#endif
/***********************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                04_ HCLCD_errSendString                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Send string to LCD "character by character"  until the null character                      */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtString  Pointer to String      @ref HCLCD_String                                                                                */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                                                 */
/******************************************************************************************************************************************************************/
ES_t HCLCD_errSendString( HCLCD_String Copy_uddtString )
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
	while(( *Copy_uddtString ) != '\0')      /* Send each char of string till the NULL */
	{
		Local_uddtError=HCLCD_errSendData ( *Copy_uddtString ) ;      /* Call LCD data write */
		Copy_uddtString++;
	}
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                05_ HCLCD_errSendCommand                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Send data to LCD  ( To Configure  )   @ref LCD Data Sheet                     */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtCommand  data for command      @ref HCLCD_Command                                                                                */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                                                 */
/******************************************************************************************************************************************************************/
ES_t  HCLCD_errSendCommand( HCLCD_Command Copy_uddtCommand )
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	/* First Send  Bits  From Bit 7 To Bit 4   then  Send  Bits from  Bit 3 to bit 1            */
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand>>4)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(1)  ;

#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

	/* First Send  Bits  From Bit 7 To Bit 4   then  Send  Bits from  Bit 3 to bit 1            */
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_DataPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand>>4)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_DataPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand)<<HCLCD_D4));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(1)  ;

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtCommand<<HCLCD_D0));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(2)  ;
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtCommand<<HCLCD_D0));
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(2)  ;
	Local_uddtError=MGPIO_errSetPINsGroupData( HCLCD_PORT_ControlPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#endif
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                06_ HCLCD_errSendNumber                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Send Number to LCD  "character by character" until the null character                      */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtDecimalNumber  Signed number      @ref HCLCD_SignedNumber                                                                                */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                                                 */
/******************************************************************************************************************************************************************/
ES_t  HCLCD_errSendNumber( HCLCD_SignedNumber Copy_uddtDecimalNumber )
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
	/*
	 * Maximum Integer Value: 2147483647
	 * Minimum Integer Value: -2147483648
	 */
	s32 Local_u8Temp= 0;
	u8   Local_u8arr[Size_of_Int]={0};
	u8   Local_u8counter=Size_of_Int ;
	if(Copy_uddtDecimalNumber == NULL_inNumberMode )
	{
		Local_uddtError=HCLCD_errSendData ( '\0' ) ;
		return  Local_uddtError;
	}
	else if(Copy_uddtDecimalNumber == 0 )
	{
		Local_uddtError=HCLCD_errSendData ( '0' ) ;      /* Call LCD data write */
		return Local_uddtError;
	}
	else if (Copy_uddtDecimalNumber < 0)
	{
		Local_uddtError=HCLCD_errSendData ( '-' ) ;
		Copy_uddtDecimalNumber  = Copy_uddtDecimalNumber*(-1);
	}
	while( Copy_uddtDecimalNumber != 0 )   /* 1234 */
	{
		Local_u8Temp    =   Copy_uddtDecimalNumber  ;      /* 1234 */
		Copy_uddtDecimalNumber    /=   10   ;                      /* 123  */
		Local_u8Temp   = Local_u8Temp - ( Copy_uddtDecimalNumber*10);    /* 1234-1230 =  4  */
		Local_u8arr[--Local_u8counter]= Local_u8Temp;
	}
	while(Local_u8counter < Size_of_Int )
	{
		Local_uddtError=HCLCD_errSendData ( (Local_u8arr[Local_u8counter++]+'0')) ;      /* Call LCD data write */
	}
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                07_ HCLCD_errGoToPostion                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Send command to LCD  to change the cursor position @ref   LCD Data sheet                     */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtColumn  moving from left to right      @ref HCLCD_uddtSPosition                                                                                */
/*               @param : Copy_uddtRow        writing in TOP or BOT      @ref HCLCD_uddtSPosition                                                                                */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                                                 */
/******************************************************************************************************************************************************************/
ES_t  HCLCD_errGoToPostion(HCLCD_uddtSPosition Copy_uddtColumn , HCLCD_uddtSPosition Copy_uddtRow)
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
	while( Copy_uddtColumn >= 16 )
	{
		Copy_uddtColumn -= 16;
	}
	if((Copy_uddtRow & 1) == 0 )
	{
		Local_uddtError=HCLCD_errSendCommand((HLCD_DDRAM__First_CMD+Copy_uddtColumn));
	}
	else
	{
		Local_uddtError=HCLCD_errSendCommand((HLCD_DDRAM__Sec_CMD+Copy_uddtColumn));
	}
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                08_ HCLCD_errSendSpecialChar                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Send command to LCD  configure new character and print it  @ref   LCD Data sheet                                                   */
/* 2- Function Input                                                                                                                                              */
/*               @param : Copy_uddtArr  pointer to array of special character      @ref HCLCD_SpecialCharArr                                                       */
/*               @param : Copy_uddtBlockNumber  number of block in CGRAM to save the character     @ref HCLCD_uddtCGRAMBlock                                       */
/*               @param : Copy_uddtColumn  moving from left to right      @ref HCLCD_uddtSPosition                                                       */
/*               @param : Copy_uddtRow        writing in TOP or BOT      @ref HCLCD_uddtSPosition                                                       */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (Any Error State From MCAL ) : Using functions from MCAL returns  Error State                                                                 */
/******************************************************************************************************************************************************************/
ES_t  HCLCD_errSendSpecialChar(HCLCD_SpecialCharArr Copy_uddtArr , HCLCD_uddtCGRAMBlock Copy_uddtBlockNumber , HCLCD_uddtSPosition Copy_uddtColumn  ,HCLCD_uddtSPosition Copy_uddtRow  )
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
	u8 LOC_uddtCounter =0 ;
	Local_uddtError=HCLCD_errSendCommand(( (Copy_uddtBlockNumber<< 3 ) | 0x40 ));
	for(LOC_uddtCounter = 0 ; LOC_uddtCounter <8 ; LOC_uddtCounter++)
	{
		Local_uddtError=HCLCD_errSendData(*(Copy_uddtArr + LOC_uddtCounter));
	}
	Local_uddtError=HCLCD_errGoToPostion(Copy_uddtColumn,Copy_uddtRow);
	Local_uddtError=HCLCD_errSendData(Copy_uddtBlockNumber);
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
/******************************************************************************************************************************************************************/
/*                                                09_ PrintMYname                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Example to print your name , this function print my name in Arabic language       */
/* 2- Function Return                                                                                                                                             */
/*               @return void                                                                                                             */
/******************************************************************************************************************************************************************/
//void PrintMYname( )
//{
//	   u8 count = 0;
//	   u8 c = 0;
//	   char M[8]=       {0b00000111,0b00001111,0b00001111,0b00011111,0b00000000,0b00000000,0b00000000};
//		char dash[8]=  {0b00000000,0b00000000,0b00000000,0b00011111,0b00000000,0b00000000,0b00000000};
//		char H[8]=       {0b00011000,0b00000100,0b00000010,0b00011111,0b00000000,0b00000000,0b00000000};
//		char D[8]=       {0b00000011,0b00000011,0b00000011,0b00011111,0b00000000,0b00000000,0b00000000};
//		char Y[8]=        {0b00000011,0b00000011,0b00000011,0b00011111,0b00000000,0b00001010,0b00000000};
//		char Yy[8]=      {0b00010000,0b00011000,0b00011011,0b00011111,0b00000000,0b00001010,0b00000000};
//		char dash0[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
//
//		HCLCD_errSendSpecialChar( Yy, HCLCD_BLOCK5 , count+0, c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 , count+1, c);
//		HCLCD_errSendSpecialChar( Y, HCLCD_BLOCK4 ,count+ 2,c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 , count+3, c);
//		HCLCD_errSendSpecialChar( H, HCLCD_BLOCK2, count+4,  c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 , count+5, c);
//		HCLCD_errSendSpecialChar( Y, HCLCD_BLOCK4 , count+6,c);

//		HCLCD_errSendSpecialChar( D, HCLCD_BLOCK3 ,count+ 9,c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 ,count+ 10,c);
//		HCLCD_errSendSpecialChar( M , HCLCD_BLOCK0 , count+11,c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 , count+12, c);
//		HCLCD_errSendSpecialChar( H, HCLCD_BLOCK2 , count+13,c);
//		HCLCD_errSendSpecialChar( dash, HCLCD_BLOCK1 , count+14,c);
//		HCLCD_errSendSpecialChar( M , HCLCD_BLOCK0 ,(count+ 15),c);
//}
/******************************************************************************************************************************************************************/
/*                                                                               The   End                                                                        */
/******************************************************************************************************************************************************************/
/*################################################################################################################################################################*/




