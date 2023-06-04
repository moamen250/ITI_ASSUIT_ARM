/*
 * APARSER_Program.c
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

#include "APARSER_Interface.h"
#include "MFDI_Interface.h"


static u32 GLOB_u32Address = 0X08000000 ;   //0x08000 0000 | 0x4000 -> 0x08004000
u16 GLOB_u16Data[50] = {0} ;


u8 APARSER_u8AsciToHex(u8 Copy_u8Asci)
{
	u8 LOC_u8Result = 100 ;
	if((Copy_u8Asci >= '0') && (Copy_u8Asci <= '9'))
	{
		LOC_u8Result = Copy_u8Asci - '0' ;
	}
	else if((Copy_u8Asci >= 'A') && (Copy_u8Asci <= 'F'))
	{
		LOC_u8Result = Copy_u8Asci - 55 ;
	}
	else
	{
	//Do Nothing
	}
	return LOC_u8Result ;
}
void APARSER_voidParseRecord(u8* Copy_pu8RecordBuf)
{
  switch(Copy_pu8RecordBuf[8])
  {
  case '0' : APARSER_voidParseData(Copy_pu8RecordBuf) ; break ; //Data Record
  case '1' : /*End Of File*/ ; break ;
  case '4' : /*Set High Address*/   break ;
  }
}
void APARSER_voidParseData(u8* Copy_pu8RecordBuf)
{
	u8 LOC_u8CC = 0  , LOC_u8DigitLow , LOC_u8DigitHigh ;
    u8 LOC_u8Digit1 , LOC_u8Digit2 , LOC_u8Digit3 , LOC_u8Digit4 ;
    u8 LOC_u8Iterator = 0 ;
    //Character Counts  CC -> Copy_pu8RecordBuf[1] , [2]  0x10
	LOC_u8DigitHigh= APARSER_u8AsciToHex(Copy_pu8RecordBuf[1]) ;
	LOC_u8DigitLow = APARSER_u8AsciToHex(Copy_pu8RecordBuf[2]) ;

	LOC_u8CC  = (LOC_u8DigitHigh << 4 ) | LOC_u8DigitLow ;

	//Address LSB EX 0x4000 ->  Copy_pu8RecordBuf[3]-[6]  0x4000 -> 0100 0000 0000 0000
	LOC_u8Digit1 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[3]) ;  //4
	LOC_u8Digit2 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[4]) ;  //0
	LOC_u8Digit3 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[5]) ;  //0
	LOC_u8Digit4 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[6]) ;  //0

	GLOB_u32Address =  GLOB_u32Address & 0xFFFF0000 ;

	GLOB_u32Address = (GLOB_u32Address) | (LOC_u8Digit1 << 12) | (LOC_u8Digit2 << 8) | (LOC_u8Digit3 << 4 ) | (LOC_u8Digit3) ;
	//Data    -> Copy_pu8RecordBuf[9] + CC
	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < LOC_u8CC /2 ; LOC_u8Iterator++  )
	{
		// Copy_pu8RecordBuf[9] [10] -> 31 82  : 82 31  Half word

		LOC_u8Digit1 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[4 * LOC_u8Iterator +  9]) ;  //3
		LOC_u8Digit2 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[4 * LOC_u8Iterator + 10]) ;  //1
		LOC_u8Digit3 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[4 * LOC_u8Iterator + 11]);   //8
		LOC_u8Digit4 = APARSER_u8AsciToHex(Copy_pu8RecordBuf[4 * LOC_u8Iterator + 12]) ;  //2

		// Copy_pu8RecordBuf[9] [10] -> 31 82  : 82 31  Half word  // 82 31 : 1000 0010 0011 0001
		GLOB_u16Data[LOC_u8Iterator] = (LOC_u8Digit3 << 12) |  (LOC_u8Digit4 <<8) | (LOC_u8Digit1 <<4)  | (LOC_u8Digit2) ;
	}
	// Send Data FDI to write it and start from specific location
	MFDI_voidFlashWrite(GLOB_u32Address , GLOB_u16Data, LOC_u8CC /2) ;
}
