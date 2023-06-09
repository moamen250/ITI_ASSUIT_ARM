/***************************************************************************/
/* Author       : John Makkar                                              */
/* Version      : V0.0.0                                                   */
/*  Date        :  8 Jun 2023                                              */
/*  Author      : John                                                     */
/*  Description : Driver Functions Implementation                          */
/*  Features    :                                                          */
/***************************************************************************/

/***************************************************************************/
/*                        Standard Types LIB                               */
/***************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"
/***************************************************************************/
/*                           MCAL Components                               */
/***************************************************************************/
#include "MUSART_Interface.h"
#include "MUSART_Config.h"
#include "MUSART_Private.h"
/***************************************************************************/
/*                        Functions Implementations                        */
/***************************************************************************/

ES_t MUSART_voidInit(void)
{
	ES_t errState = ES_OK;
#if(USART_USED == USART1)
	/*Select BaudRate -> 9600*/
	USART1_REG ->BRR = 0x683;

	/* Select Stop Bits As 1-BIT */
	USART1_REG -> CR2.STOP |= (USART1_ONE_STOP_BITS << 12);

	/* ENABLE RX */
	USART1_REG ->CR1.RE = 1;

	/* ENABLE TX */
	USART1_REG ->CR1.TE = 1;

	/* Select No Sending BREAK */
	USART1_REG ->CR1.SBK = 0 ;

	/* Select Disable Parity */
	USART1_REG ->CR1.PCE = 0;

	/* SELECT WORD LENGHT AS 8DATA-BITS */
	USART1_REG ->CR1.M = _8DATA_LENGTH_ ;

	/*SELECT OVER SAMPLING BY 16*/
	USART1_REG ->CR1.OVER8 = 0;
#endif

#if (USART_USED == USART2)
	/*Select BaudRate -> 9600*/
	USART2_REG ->BRR = 0x683;

	/* Select Stop Bits As 1-BIT */
	USART2_REG -> CR2.STOP |= (USART1_ONE_STOP_BITS << 12);

	/* ENABLE RX */
	USART2_REG ->CR1.RE = 1;

	/* ENABLE TX */
	USART2_REG ->CR1.TE = 1;

	/* Select No Sending BREAK */
	USART2_REG ->CR1.SBK = 0 ;

	/* Select Disable Parity */
	USART2_REG ->CR1.PCE = 0;

	/* SELECT WORD LENGHT AS 8DATA-BITS */
	USART2_REG ->CR1.M = _8DATA_LENGTH_ ;

	/*SELECT OVER SAMPLING BY 16*/
	USART2_REG ->CR1.OVER8 = 0;
#endif

#if (USART_USED == USART6)
	/*Select BaudRate -> 9600*/
	USART6_REG ->BRR = 0x683;

	/* Select Stop Bits As 1-BIT */
	USART6_REG -> CR2.STOP |= (USART1_ONE_STOP_BITS << 12);

	/* ENABLE RX */
	USART6_REG ->CR1.RE = 1;

	/* ENABLE TX */
	USART6_REG ->CR1.TE = 1;

	/* Select No Sending BREAK */
	USART6_REG ->CR1.SBK = 0 ;

	/* Select Disable Parity */
	USART6_REG ->CR1.PCE = 0;

	/* SELECT WORD LENGHT AS 8DATA-BITS */
	USART6_REG ->CR1.M = _8DATA_LENGTH_ ;

	/*SELECT OVER SAMPLING BY 16*/
	USART6_REG ->CR1.OVER8 = 0;
#endif
	if (errState != ES_OK)
	{
		errState = ES_NOK;
	}
	return errState;
}
ES_t MUSART_voidEnable(u8 Copy_u8Index)
{
	ES_t errState = ES_OK;
	switch(Copy_u8Index)
	{
	case 1: USART1_REG ->CR1.UE = 1 ; break;
	case 2: USART2_REG ->CR1.UE = 1 ; break;
	case 3: USART6_REG ->CR1.UE = 1 ; break;
	default: errState = ES_NOK; break;
	}
	return errState;
}
ES_t MUSART_voidDisable(u8 Copy_u8Index)
{
	ES_t errState = ES_OK;
	switch(Copy_u8Index)
	{
	case 1: USART1_REG ->CR1.UE = 0 ; break;
	case 2: USART2_REG ->CR1.UE = 0 ; break;
	case 3: USART6_REG ->CR1.UE = 0 ; break;
	default: errState = ES_NOK; break;
	}
	return errState;
}



ES_t MUSART_voidSendData(u8 Copy_u8Index , u8 *Copy_Pu8Data , u8 Copy_u8Lenght)
{
	ES_t errState = ES_OK;
	u8 LOC_u8Counter;
	switch (Copy_u8Index)
	{
	case 1: for(LOC_u8Counter = 0; LOC_u8Counter < Copy_u8Lenght; LOC_u8Counter++)
			{
				USART1_REG ->DR    = Copy_Pu8Data[LOC_u8Counter];
				while(GET_BIT(USART1_REG ->SR,6) == 0);
			}
			break;
	case 2: for(LOC_u8Counter = 0; LOC_u8Counter < Copy_u8Lenght; LOC_u8Counter++)
			{
				USART2_REG ->DR    = Copy_Pu8Data[LOC_u8Counter];
				while(GET_BIT(USART2_REG ->SR,6) == 0);
			}
			break;
	case 6: for(LOC_u8Counter = 0; LOC_u8Counter < Copy_u8Lenght; LOC_u8Counter++)
			{
				USART6_REG ->DR    = Copy_Pu8Data[LOC_u8Counter];
				while(GET_BIT(USART6_REG ->SR,6) == 0);
			}
			break;
	default:errState = ES_NOK;
			break;
	}
	return errState;
}
u8 MUSART_voidReceiveData(u8 Copy_u8Index)
{
	u8 LOC_u8ReadData;
	switch(Copy_u8Index)
	{
	case 1: LOC_u8ReadData = (USART1_REG ->DR); break;
	case 2: LOC_u8ReadData = (USART2_REG ->DR); break;
	case 6: LOC_u8ReadData = (USART6_REG ->DR); break;
	default:         /* DO NO-THING */          break;
	}
	return (u8)LOC_u8ReadData;
}

