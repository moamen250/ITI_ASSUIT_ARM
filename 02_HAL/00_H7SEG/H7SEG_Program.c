/**************************************************************************/
/*Author            : Mariam Ayman                                        */
/*Version           : V1.0.0                                              */
/*Date              : 13 MAY 2023                                         */
/*Description       : H7SEG_Program.c                                     */
/*Features          :                                                     */
/*        - H7SEG_Init()                                                  */
/*        - H7SEG_Display_Number()                                        */
/**************************************************************************/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                           INCLUDE MCAL LAYER                           */
/**************************************************************************/

#include "MGPIO_Inteface.h"
#include "MRCC_Interface.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "H7SEG_Private.h"
#include "H7SEG_Config.h"
#include "H7SEG_Interface.h"

/******************************************************************************/
/*                 H7SEG Functions implementation                             */
/******************************************************************************/

ES_t H7SEG_Init (void)
{
	ES_t Local_errState = ES_OK;
	MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOA_EN);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_A ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_B ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_C ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_D ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_E ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_F ,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(H7SEG_PORT , H7SEG_PIN_G ,MGPIO_MODE_OUTPUT);

	if (Local_errState != ES_OK)
	{
		Local_errState = ES_NOK;
	}
	return Local_errState;
}

ES_t H7SEG_Display_Number(u8 Copy_u8Number)
{
	ES_t Local_errState = ES_OK;
	switch (Copy_u8Number)
	{
	case ZERO:  MGPIO_errSetPortData(H7SEG_PORT, NUMBER_ZERO);  break;
	case ONE:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_ONE);  break;
	case TWO:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_TWO);  break;
	case THREE:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_THREE);  break;
	case FOUR:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_FOUR);  break;
	case FIVE:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_FIVE);  break;
	case SIX:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_SIX);  break;
	case SEVEN:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_SEVEN);  break;
	case EIGHT:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_EIGHT);  break;
	case NINE:   MGPIO_errSetPortData(H7SEG_PORT, NUMBER_NINE);  break;
	}
	if (Local_errState != ES_OK)
	{
		Local_errState = ES_NOK;
	}
	return Local_errState;
}
