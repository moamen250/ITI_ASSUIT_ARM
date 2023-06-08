/*
 * MFDI_Program.c
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed Khaled Hammad
 */



/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MFDI_Private.h"
#include "MFDI_Config.h"
#include "MFDI_Interface.h"


void MFDI_voidSectorErase(u8 copy_u8SectorNum)
{
	// Step 1 : wait till Busy flag = 0
	while(GET_BIT(MFDI->SR,16) == 1 ) ;

	// Step Check Flash CR  is UNLOCK
	if(GET_BIT(MFDI->CR,31) == 1 )
	{
		//UNLOCK
		MFDI->KEYR = 0x45670123 ;
		MFDI->KEYR = 0xCDEF89AB ;
	}
	else
	{
		/*Already UNLOCK*/
	}
	// Step 2 : Set SER bit to activate sector Erase
	SET_BIT(MFDI->CR,1) ;

	// Step 3 : Select The Sector Number From 0 : 5
	MFDI ->CR &= 0xFFFFFF87 ;
	MFDI ->CR |= (copy_u8SectorNum <<3 ) ;

	// Step 4 : Set the STRT bit in the FLASH_CR register
	SET_BIT(MFDI->CR,16) ;

	// Step 5 : wait till Busy flag = 0
	while(GET_BIT(MFDI->SR,16) == 1 ) ;

	// Step 6 : CLEAR SER bit to deactivate sector Erase
	CLR_BIT(MFDI->CR,1) ;

	// Step 7 : SET EOP bit (End of operation)
	SET_BIT(MFDI->SR,0) ;
}

void MFDI_voidFlashWrite(u32 copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length)
{
	u8 LOC_u8Iterator = 0;
	// Step 1 : wait till Busy flag = 0
	while(GET_BIT(MFDI->SR,16) == 1 ) ;

	// Step Check Flash CR  is UNLOCK
	if(GET_BIT(MFDI->CR,31) == 1 )
	{
		//UNLOCK
		MFDI->KEYR = 0x45670123 ;
		MFDI->KEYR = 0xCDEF89AB ;
	}
	else
	{
		/*Already UNLOCK*/
	}

	// Step 2 : Select The Program size byte [Halfword-word-DoubleWord]
	MFDI ->CR &= 0xFFFFFCFF ; // Mask
	MFDI ->CR |= (1 << 8) ;  //HalfWord

	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < Copy_u8Length ; LOC_u8Iterator++ )
	{
		// Step 3 : Set the PG bit in the FLASH_CR register active Programming Mode
		SET_BIT(MFDI->CR,0) ;
		*((volatile u16*)copy_u32Address) = Copy_pu16Data[LOC_u8Iterator] ;
		copy_u32Address +=2 ; //Decimal
		// Step 4 : wait till Busy flag = 0
		while(GET_BIT(MFDI->SR,16) == 1 ) ;
		// Step 6 : CLEAR PG bit to deactivate sector Erase
		CLR_BIT(MFDI->CR,0) ;
		// Step 7 : SET EOP bit (End of operation)
		SET_BIT(MFDI->SR,0) ;
	}
}
void MFDI_voidAppErase(void)
{
	u8 LOC_u8Iterator = 1 ;
	for(LOC_u8Iterator = 1 ; LOC_u8Iterator < 6 ; LOC_u8Iterator++  )
	{
		MFDI_voidSectorErase(LOC_u8Iterator) ;
	}
}
