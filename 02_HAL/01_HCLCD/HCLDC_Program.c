/***********************************************************************************************************************************************/
/* Author :                             Mohamed Yehia El-Greatly                                             */
/* Description :                          HCLCD_Program.c                                                  */
/***********************************************************************************************************************************************/
/* Version :V1.0.0                                                                                        */
/* Date :     13 May 2023                                                                                     */
/***********************************************************************************************************************************************/
/**************************************************************************/
/*                                Include  LIB Files                                    */
/**************************************************************************/
#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"
/**************************************************************************/
/*                           Include Peripherals Files                           */
/**************************************************************************/
#include  "MRCC_Interface.h"
#include  "MGPIO_Inteface.h"
#include  "MSTK_Interface.h"
#include  "HCLCD_Private.h"
#include  "HCLCD_Config.h"
#include  "HCLCD_Interface.h"
/***********************************************************************************************************************************************************************/
/*                                                                                   MGPIO Functions implementation                                                                                                              */
/******************************************************************************************************************************************************************/
/*                                                          01_ HCLCD_errInit                                                                                      */
/*                                           @Written by : Mohamed Yehia El-Greatly                                                                               */
/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Initialize the operation mode of group of pins  ( INPUT or OUTPUT  or ALTF or ANALOG )   @ref MGPIO_PinMode                     */
/* 2- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (E_OK) : The function done successfully                                                                                           */
/*                              (ES_WRONG_PINs_VALUE)    : The user enter value of PINs equal to zero ( no pins to configure ), or PINs not in PORT C           */
/*                              (ES_OUT_OF_RANGE_PORT)  : The user enter number of PORT more than MC PORTs  or negative number                                   */
/*                              (ES_WRONG_MODE_VALUE) : The user enter wrong value to configure specific mode or negative value                                 */
/******************************************************************************************************************************************************************/
ES_t HCLCD_errInit (void)
{
	/*	Initiate  the error state variable to detect any error then return it  */
	ES_t Local_uddtError= ES_OK;
	/******************************************************************************************************************************************************************/
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )
	/******************************************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORT_CLOCK);
	Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_D4,HCLCD_D7) , MGPIO_MODE_OUTPUT);
	Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To( HCLCD_RS , HCLCD_E ) , MGPIO_MODE_OUTPUT);
	 _delay_ms(40)  ;
	 Local_uddtError = HCLCD_errSendCommand(HLCD_4BITM_CMD);
	 Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	 Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	 Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	 Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
	 Local_uddtError = HCLCD_errSendCommand(HLCD_DDRAM__First_CMD);
	/******************************************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )
	/******************************************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTData_CLK);
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTControl_CLK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_DataPINs , MGPIO_PINs_From_To(HCLCD_D4 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ControlPINs , MGPIO_PINs_From_To(HCLCD_RS ,HCLCD_E )  , MGPIO_MODE_OUTPUT);
	_delay_ms(40)  ;
   Local_uddtError = HCLCD_errSendCommand(HLCD_4BITM_CMD);
   Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
   Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
   Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
   Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
   Local_uddtError = HCLCD_errSendCommand(HLCD_DDRAM__First_CMD);
	/******************************************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )
	/******************************************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORT_CLOCK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_D0 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ALLPINs , MGPIO_PINs_From_To(HCLCD_RS,HCLCD_E) , MGPIO_MODE_OUTPUT);
	_delay_ms(40)  ;
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
	/******************************************************************************************************************************************************************/
#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )
	/******************************************************************************************************************************************************************/
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTData_CLK);
	Local_uddtError = MRCC_errEnablePeripherialClk(  MRCC_AHB1 , HCLCD_PORTControl_CLK);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_DataPINs , MGPIO_PINs_From_To(HCLCD_D0 ,HCLCD_D7 ) , MGPIO_MODE_OUTPUT);
	Local_uddtError = Local_uddtError = MGPIO_errSetPINsGroupMode(HCLCD_PORT_ControlPINs , MGPIO_PINs_From_To(HCLCD_RS,HCLCD_E)  , MGPIO_MODE_OUTPUT);
	_delay_ms(40)  ;
	Local_uddtError = HCLCD_errSendCommand(HLCD_FUNCSET_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_DOC_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_CLR_CMD);
	Local_uddtError = HCLCD_errSendCommand(HLCD_EMS_CMD);
	/******************************************************************************************************************************************************************/
#endif
	/******************************************************************************************************************************************************************/
	return Local_uddtError;
}
ES_t  HCLCD_errClearDisplay(void)
{
   HCLCD_errSendCommand(0x01);
}
ES_t  HCLCD_errSendData( HCLCD_Char  Copy_uddtData )
{
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData>>4)<<HCLCD_D4));
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
		_delay_ms(1)  ;
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
		_delay_ms(1)  ;
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtData)<<HCLCD_D4));

		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
		_delay_ms(1)  ;
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
		_delay_ms(2)  ;

#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_DATA<<HCLCD_RS));
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtData<<HCLCD_D0));
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
		_delay_ms(2)  ;
		MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

#endif
}
ES_t HCLCD_errSendString( HCLCD_String Copy_uddtString )
{
	while(( *Copy_uddtString ) != '\0')      /* Send each char of string till the NULL */
	{
		HCLCD_errSendData ( *Copy_uddtString ) ;      /* Call LCD data write */
		Copy_uddtString++;
	}
}
ES_t  HCLCD_errSendCommand( HCLCD_Command Copy_uddtCommand )
{
#if ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand>>4)<<HCLCD_D4));
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(1)  ;
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(1)  ;
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D4 , HCLCD_D7), ((Copy_uddtCommand)<<HCLCD_D4));

	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(1)  ;
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));
	_delay_ms(2)  ;

#elif ( HCLCD_MODE                       ==            _4_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _ONE_PORT_ )

	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_RS , HCLCD_RW), (RW_WRITE_RS_COMMAND<<HCLCD_RS));
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_D0 , HCLCD_D7), (Copy_uddtCommand<<HCLCD_D0));
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_HIGH<<HCLCD_E));
	_delay_ms(2)  ;
	MGPIO_errSetPINsGroupData( HCLCD_PORT_ALLPINs, MGPIO_PINs_From_To( HCLCD_E , HCLCD_E), (EN_LOW<<HCLCD_E));

#elif ( HCLCD_MODE                       ==            _8_BIT_MODE_  ) && (  HCLCD_PORT_MODE         ==         _TWO_PORT_ )

#endif
}
ES_t  HCLCD_errSendNumber( HCLCD_SignedNumber Copy_uddtDecimalNumber )
{
	 /*
	    * Maximum Integer Value: 2147483647
	    * Minimum Integer Value: -2147483648
	    */

		s32 Local_u8Temp= 0;
		u8   Local_u8arr[Size_of_Int]={0};
	    u8   Local_u8counter=Size_of_Int ;
	    if(Copy_uddtDecimalNumber == NULL_inNumberMode )
	    {
	    	HCLCD_errSendData ( '\0' ) ;
	    	return  ES_OK;
	    }
	    else if(Copy_uddtDecimalNumber == 0 )
		{
	    	HCLCD_errSendData ( '0' ) ;      /* Call LCD data write */
			return ES_OK;
		}
		else if (Copy_uddtDecimalNumber < 0)
		{
			HCLCD_errSendData ( '-' ) ;
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
			HCLCD_errSendData ( (Local_u8arr[Local_u8counter++]+'0')) ;      /* Call LCD data write */
		}

}
ES_t  HCLCD_errGoToPostion(HCLCD_uddtSPosition Copy_uddtColumn , HCLCD_uddtSPosition Copy_uddtRow)
{
	while( Copy_uddtColumn >= 16 )
	{
		Copy_uddtColumn -= 16;
	}
	if((Copy_uddtRow & 1) == 0 )
	{
		HCLCD_errSendCommand((HLCD_DDRAM__First_CMD+Copy_uddtColumn));
	}
	else
	{
		HCLCD_errSendCommand((HLCD_DDRAM__Sec_CMD+Copy_uddtColumn));
	}

}


ES_t  HCLCD_errSendSpecialChar(HCLCD_SpecialCharArr Copy_uddtArr , HCLCD_uddtCGRAMBlock Copy_uddtBlockNumber , HCLCD_uddtSPosition Copy_uddtColumn  ,HCLCD_uddtSPosition Copy_uddtRow  )
{
	u8 LOC_uddtCounter =0 ;
	HCLCD_errSendCommand(( (Copy_uddtBlockNumber<< 3 ) | 0x40 ));
		for(LOC_uddtCounter = 0 ; LOC_uddtCounter <8 ; LOC_uddtCounter++)
			{
			HCLCD_errSendData(*(Copy_uddtArr + LOC_uddtCounter));
			}
		HCLCD_errGoToPostion(Copy_uddtColumn,Copy_uddtRow);
		HCLCD_errSendData(Copy_uddtBlockNumber);
}






/*
void PrintMYname( )
{
	   u8 count = 0;
	   u8 c = 0;
	   char M[8]=       {0b00000111,0b00001111,0b00001111,0b00011111,0b00000000,0b00000000,0b00000000};
		char dash[8]=  {0b00000000,0b00000000,0b00000000,0b00011111,0b00000000,0b00000000,0b00000000};
		char H[8]=       {0b00011000,0b00000100,0b00000010,0b00011111,0b00000000,0b00000000,0b00000000};
		char D[8]=       {0b00000011,0b00000011,0b00000011,0b00011111,0b00000000,0b00000000,0b00000000};
		char Y[8]=        {0b00000011,0b00000011,0b00000011,0b00011111,0b00000000,0b00001010,0b00000000};
		char Yy[8]=      {0b00010000,0b00011000,0b00011011,0b00011111,0b00000000,0b00001010,0b00000000};
		char dash0[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};

	     HLCD_voidSendSpecialChar( Yy, 5 , count+0, c);
		 HLCD_voidSendSpecialChar( dash, 1 , count+1, c);
		 HLCD_voidSendSpecialChar( Y, 4 ,count+ 2,c);
		 HLCD_voidSendSpecialChar( dash, 1 , count+3, c);
		 HLCD_voidSendSpecialChar( H, 2 , count+4,  c);
		 HLCD_voidSendSpecialChar( dash, 1 , count+5, c);
		 HLCD_voidSendSpecialChar( Y, 4 , count+6,c);
			//HLCD_voidSendSpecialChar( dash0, 6 , count+7,c);
		 HLCD_voidSendSpecialChar( D, 3 ,count+ 9,c);
		 HLCD_voidSendSpecialChar( dash, 1 ,count+ 10,c);
		 HLCD_voidSendSpecialChar( M , 0 , count+11,c);
		 HLCD_voidSendSpecialChar( dash, 1 , count+12, c);
		 HLCD_voidSendSpecialChar( H, 2 , count+13,c);
		  HLCD_voidSendSpecialChar( dash, 1 , count+14,c);
		 HLCD_voidSendSpecialChar( M , 0 ,(count+ 15),c);
}

*/





