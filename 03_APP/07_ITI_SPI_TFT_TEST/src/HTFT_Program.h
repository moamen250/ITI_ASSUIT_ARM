/*
 * HTFT_Program.h
 *
 *  Created on: May 28, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HTFT_PROGRAM_H_
#define HTFT_PROGRAM_H_


/***********************************************************************************************************/
/*                                          Include  LIB Files                                             */
/***********************************************************************************************************/
#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"

/***********************************************************************************************************/
/*                                   Include MCAL Peripherals Files                                        */
/***********************************************************************************************************/

#include  "MGPIO_Inteface.h"
#include  "MSTK_Interface.h"

/***********************************************************************************************************/
/*                                        Include Peripherals Files                                        */
/***********************************************************************************************************/
#include  "HTFT_Config.h"
#include  "HTFT_Private.h"
#include  "HTFT_Interface.h"


void HTFT_voidInit(void)
{
	//TODO
}
void HTFT_voidDisplayImage(u16* Copy_pu16Image)
{
	//TODO
}
static void HTFT_voidWriteCmd(u8 Copy_u8Cmd)
{
	//TODO
}
static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	//TODO
}
static void HTFT_voidResetSeq(void)
{
	//TODO
}

#endif /* HTFT_PROGRAM_H_ */
