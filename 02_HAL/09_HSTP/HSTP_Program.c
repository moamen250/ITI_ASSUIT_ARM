
/**************************************************************************/
/*Author            : Amr Wahba & Momen Mamdouh                           */
/*Version           : V1.0.0                                              */
/*Date              : 26 MAY 2023                                         */
/*Description       :HSTP_Program.c                                       */
/*Features          :                                                     */
/*         		   - HSTP_voidInit()                                      */
/*       		   - HSTP_voidSendData()                                  */
/*       	       - HKEYPAD_u8GetPressed()                               */
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
static void HSTP_voidSendPulse(u8 Copy_u8Port,u8 Copy_u8Pin)
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
void HSTP_void_LedMatrix(u8 *ptr_u8Data)
{
	s8 i,j;
		for(j=0;j<8;j++)
		{
			for(i=7;i>=0;i--)
			{
				MGPIO_errSetPinData(HSTP_PORT ,HSTP_PIN_DS,GET_BIT(ptr_u8Data[j],i));
				HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_SHCP);
			}
			for(i=7;i>=0;i--)
			{

				MGPIO_errSetPinData(HSTP_PORT ,HSTP_PIN_DS,GET_BIT(~(1<<j),i));
				HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_SHCP);
			}
			HSTP_voidSendPulse(HSTP_PORT,HSTP_PIN_STCP);
			_delay_ms(1);
		}
}
