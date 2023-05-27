
/**************************************************************************/
/*Author            : Amr Wahba                                           */
/*Version           : V1.0.0                                              */
/*Date              : 26 MAY 2023                                         */
/*Description       :HSTP_Program.c                                       */
/*Features          :                                                     */
/*         		   -01_ HSTP_voidInit                                     */
/*       		   -02_ HSTP_voidSendPulse                                */
/* 				   -03_ HSTP_voidSendDatat                                */
/*       	       -04_ HSTP_void_LedMatrix                               */
/**************************************************************************/



/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            INCLUDE MCAL LAYER                          */
/**************************************************************************/

#include      "MGPIO_Inteface.h"
#include      "MRCC_Interface.h"
#include      "MSTK_Interface.h"
/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/
#include "HSTP_Interface.h"
#include "HSTP_Configh.h"


/******************************************************************************/
/*                           01_ HSTP_voidSendPulse                           */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> THIS Function Just Generate PULSE               */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_u8Port                                     */
/*                     @param Copy_u8Pin                                      */
/* 3- Function Return      -> @return  Void                                   */
/******************************************************************************/
 void HSTP_voidSendPulse(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	 MGPIO_errSetPinData(Copy_u8Port,Copy_u8Pin,MGPIO_PIN_HIGH);
	 _delay_us(5);
	 MGPIO_errSetPinData(Copy_u8Port,Copy_u8Pin,MGPIO_PIN_LOW);
}

/******************************************************************************/
/*                           02_ HSTP_voidInit                                */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> THIS Function Initialized PORT AND MODE         */
/* 2- Function Input       ->                                                 */
/*                     @param void                                            */
/* 3- Function Return      -> @return  Void                                   */
/******************************************************************************/
void HSTP_voidInit(void)
{

	MRCC_errEnablePeripherialClk(MRCC_AHB1,HSTP_PORT);

	MGPIO_errSetPinMode(HSTP_PORT,HSTP_PIN_DS,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(HSTP_PORT,HSTP_PIN_SHCP,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(HSTP_PORT,HSTP_PIN_STCP,MGPIO_MODE_OUTPUT);

}
/******************************************************************************/
/*                           03_ HSTP_voidSendData                            */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> THIS Function Send one Byte on one Pin          */
/* 2- Function Input       ->                                                 */
/*                     @param Copy_u8Data                                     */
/* 3- Function Return      -> @return  Void                                   */
/******************************************************************************/
void HSTP_voidSendData(u8 Copy_u8Data)
{
   s8 local_u8Iteration=7;
   for(local_u8Iteration=7;local_u8Iteration>=0;local_u8Iteration--)
   {
	   MGPIO_errSetPinData(HSTP_PORT,HSTP_PIN_DS,GET_BIT(Copy_u8Data,local_u8Iteration));

	   HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_SHCP);
   }
   HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_STCP);
}

/******************************************************************************/
/*                           04_ HSTP_void_LedMatrix                          */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> THIS Function Send array of byte and send  with */
/* active column                                                              */
/* 2- Function Input       ->                                                 */
/*                     @param ptr_u8Data                                      */
/* 3- Function Return      -> @return  Void                                   */
/******************************************************************************/
ES_t HSTP_void_LedMatrix(u8 *ptr_u8Data)
{
	u8 Copy_u8Start=7;
	u8 Copy_u8End=0;
	u8 Copy_u8Counter=0;
	u8 Copy_u8EndCounter=8;
	ES_t Local_Error_state=ES_OK;
	if(ptr_u8Data!=NULL)
	{

		for(Copy_u8Counter=0;Copy_u8Counter<Copy_u8EndCounter;Copy_u8Counter++)
		{
			for(Copy_u8Start=7;Copy_u8Start>=Copy_u8End;Copy_u8Start--)
			{
				MGPIO_errSetPinData(HSTP_PORT ,HSTP_PIN_DS,GET_BIT(ptr_u8Data[Copy_u8Counter],Copy_u8Start));
				HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_SHCP);
			}
			for(Copy_u8Start=7;Copy_u8Start>=Copy_u8End;Copy_u8Start--)
			{

				MGPIO_errSetPinData(HSTP_PORT ,HSTP_PIN_DS,GET_BIT(~(1<<Copy_u8Counter),Copy_u8Start));
				HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_SHCP);
			}
			HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_STCP);
			_delay_ms(1);
		}
	}
	else
	{
		Local_Error_state=ES_NOK;
	}
	return Local_Error_state;


}
