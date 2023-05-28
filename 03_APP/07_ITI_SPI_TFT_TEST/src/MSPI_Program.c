/*
 * MSPI_Program.c
 *
 *  Created on: May 28, 2023
 *      Author: Ahmed Khaled Hammad
 */

/***********************************************************************************************************/
/*                                          Include  LIB Files                                             */
/***********************************************************************************************************/
#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"
/***********************************************************************************************************/
/*                                        Include Peripherals Files                                        */
/***********************************************************************************************************/
#include  "MGPIO_Inteface.h"

#include  "MSPI_Private.h"
#include  "MSPI_Config.h"
#include  "MSPI_Interface.h"


/***********************************************************************************************************/
/*                                      MEXTI  Functions implementation                                    */
/***********************************************************************************************************/


static void (*MSPI1_CallBack)(void) = NULL ;

void MSPI_voidInit(void)
{
	/*
	 *SPI Configuration :
	 *- Master Mode
	 *- Clk Frequancy [bouad Rate]
	 *- MSB First
	 *- CPOL = 1
	 *- CPHA = 1
	 *- SSI  = 1
	 *- SSM  = 1
	 *- DF   = 8
	 *- SPI  = Enable
	 * **/
	//MSPI1->CR1 = 0x0347 ;

	// Initialize The Slave Select pin
	MGPIO_errSetPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_MODE_OUTPUT) ;
	MGPIO_errSetPinOutType(MGPIO_PORTA,MGPIO_PIN0,MGPIO_OUTPUT_PUSHPULL) ;
	MGPIO_errSetPinData(MGPIO_PORTA,MGPIO_PIN0,MGPIO_PIN_HIGH) ; //Disable Slave
}

u8 MSPI_u8SendReceive(u8 Copy_u8Data)
{
	/*Clear Signal for Slave Select*/
	MGPIO_errSetPinData(MGPIO_PORTA,MGPIO_PIN0,MGPIO_PIN_LOW) ;
	/*Send Data*/
	//MSPI1->DR = Copy_u8Data ;
	// wait Busy Flag to finish
	//while(GET_BIT(MSPI1->DR,7)) ;
	/*Set Signal for Slave release*/
	MGPIO_errSetPinData(MGPIO_PORTA,MGPIO_PIN0,MGPIO_PIN_HIGH) ;
	//return MSPI1->DR ;
}

void MSPI1_voidSetCallBack(void(*Fptr)(void))
{
	//Check if not equal null
	MSPI1_CallBack = Fptr ;
}


void SPI1_IRQHandler(void)
{
	// check if not equal NULL
	MSPI1_CallBack() ;
}

