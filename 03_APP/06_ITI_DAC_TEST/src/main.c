/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"


/**************************************************************************/
/*                        HAL Layer                                       */
/**************************************************************************/


/**************************************************************************/
/*                        MCAL Layer                                      */
/**************************************************************************/
#include "MRCC_Interface.h"
#include "MGPIO_Inteface.h"
#include "MSTK_Interface.h"
#include "MNVIC_Interface.h"
#include "MGPIO_Private.h"
/**************************************************************************/
/*                            APP Layer                                   */
/**************************************************************************/
#include "ASSUIT_FADY.h"




/**************************************************************************/
/*                       Applications Macros                              */
/**************************************************************************/
volatile u32 GLB_u32Iterator = 0 ;

/**************************************************************************/
/*                   Application Function ProtoType                       */
/**************************************************************************/
void App_voidSetDAC(void) ;

int main(void)
{
	/*Step 1 : SystemClock is 16 MHZ from HSI*/
	MRCC_errInitSystemClk() ;
	/*Step 2 : Enable GPIOA Clock*/
	MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOA_EN) ;
	/*Step 3: PORTA --> Output Push pull*/
	for(u8 pin = 0 ; pin < 8 ; pin++)
	{
		/*Set Pin Mode --> Output*/
		MGPIO_errSetPinMode(MGPIO_PORTA,pin,MGPIO_MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_errSetPinOutType(MGPIO_PORTA,pin,MGPIO_OUTPUT_PUSHPULL) ;
	}
	/*Step 4: Init STK[Timer] -> AHB_8 -> 1 tick = 0.5 microSecond*/
	MSTK_Init() ;
	/*Step 5: Enable Interrupt For 125 MicroSecond*/
	MSTK_INT_Enable(0.125);
	/*Step 6: Set CallBack*/
	MSTK_errSetCallBackSTK(App_voidSetDAC) ;

	while(1)
	{
		/*Do Nothing*/
	}
}

// ISR --> for sampling
void App_voidSetDAC(void)
{
	MGPIOA->ODR =  (u8)ASSUIT_FADY_raw[GLB_u32Iterator] ;
	GLB_u32Iterator++;
	if(GLB_u32Iterator == 158048)
	{
		GLB_u32Iterator = 0 ;
	}
}
