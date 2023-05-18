/**************************************************************************/
/*Author            : Ahmed Reda Morsi                                    */
/*Version           : V1.0.0                                              */
/*Date              : 17 MAY 2023                                         */
/*Description       : implementation of LED matrix Driver                 */
/*Features          :                                                     */
/*        -HLEDMATRIX_errInit(void) 									  */
/* 		  -HLEDMATRIX_SetPattern(u8* Copy_u8pPattern)                     */
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

#include "HLEDMATRIX_Private.h"
#include "HLEDMATRIX_Config.h"
#include "HLEDMATRIX_Interface.h"

#include "MSTK_Interface.h"
#include "MRCC_Interface.h"
#include "MGPIO_Inteface.h"


/**************************************************************************/
/*                   HLEDMATRIX Functions implementation                                                                                                              */
/**************************************************************************/


ES_t HLEDMATRIX_errInit(void)
{
	ES_t LOC_uddtState = ES_OK ;
	// enable clock for LED Matrix GPIO PORTS
	LOC_uddtState=MRCC_errEnablePeripherialClk(MRCC_AHB1,HLEDMATRIX_COLUMNPORT);
	LOC_uddtState=MRCC_errEnablePeripherialClk(MRCC_AHB1,HLEDMATRIX_ROWPORT);

	//set row and column pins as output mode
	LOC_uddtState=MGPIO_errSetPINsGroupMode(HLEDMATRIX_COLUMNPORT,MGPIO_PINs_From_To(HLEDMATRIX_COLUMN_0,HLEDMATRIX_COLUMN_7),MGPIO_MODE_OUTPUT);
	LOC_uddtState=MGPIO_errSetPINsGroupMode(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),MGPIO_MODE_OUTPUT);

	// set row and column pins with high value
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),0xFFFF);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_COLUMNPORT,MGPIO_PINs_From_To(HLEDMATRIX_COLUMN_0,HLEDMATRIX_COLUMN_7),0xFFFF);

	return LOC_uddtState;
}
ES_t HLEDMATRIX_SetPattern(u8* Copy_u8pPattern)
{
	ES_t LOC_uddtState = ES_OK ;
	
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[0]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_0,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_0,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[1]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_1,MGPIO_PIN_LOW);
	_delay_ms(LOC_FrameDelay);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_1,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[2]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_2,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_2,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[3]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_3,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_3,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[4]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_4,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_4,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[5]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_5,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_5,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[6]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_6,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);

	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_6,MGPIO_PIN_HIGH);
	LOC_uddtState=MGPIO_errSetPINsGroupData(HLEDMATRIX_ROWPORT,MGPIO_PINs_From_To(HLEDMATRIX_ROW_0,HLEDMATRIX_ROW_7),Copy_u8pPattern[7]);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_7,MGPIO_PIN_LOW);
	_delay_ms(FRAME_DELAY_MS);
	LOC_uddtState=MGPIO_errSetPinData(HLEDMATRIX_COLUMNPORT,HLEDMATRIX_COLUMN_7,MGPIO_PIN_HIGH);

	return LOC_uddtState;

}
