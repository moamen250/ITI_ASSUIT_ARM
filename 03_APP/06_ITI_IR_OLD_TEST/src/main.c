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
#include "MEXTI_Interface.h"
/**************************************************************************/
/*                            APP Layer                                   */
/**************************************************************************/


/**************************************************************************/
/*                       Applications Macros                              */
/**************************************************************************/

#define    EXTI0         6

volatile u8 Counter = 0 ;
volatile u8 Start_Flag = 0 ;
volatile u32 Readings[50] = {0} ;
volatile u8 IR_Data = 0 ;


/**************************************************************************/
/*                   Application Function ProtoType                       */
/**************************************************************************/
void App_voidPlay(void)
{
	switch(IR_Data)
	{
	case 10 : MGPIO_errSetPinData(MGPIO_PORTA,MGPIO_PIN1,MGPIO_PIN_HIGH) ; break ;
	case 11 : MGPIO_errSetPinData(MGPIO_PORTA,MGPIO_PIN1,MGPIO_PIN_LOW) ; break ;
	default : /*Do Nothing*/ break ;
	}
}

void App_voidFillData(void)
{
    //Systick Firing -> Single Interval
	/*Step 1 : Check is valid start bit*/
	if((Readings[0] >= 10000) && (Readings[0] <= 14000))
	{
		/*Collect 8 bit IR_DATA*/
		for(u8 i = 0 ; i < 8 ; i++)
		{
			if((Readings[17+i] >= 1000) && (Readings[17+i] <= 1200))
			{
				// Logical 0
				CLR_BIT(IR_Data,i) ;
			}
			else if((Readings[17+i] >= 2000) && (Readings[17+i] <= 2500))
			{
				// Logical 1
				SET_BIT(IR_Data,i) ;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		// Call Application
		App_voidPlay() ;
	}
	else
	{
	   /*Invalid Frame*/
	}
  Start_Flag = 0 ;
  IR_Data = 0 ;
  Counter = 0 ;
}
void App_voidGetFrame(void)
{
  /*Get Readings for each bit*/
	if(Start_Flag == 0)
	{
		//First Time
		Start_Flag = 1 ;
		// Start Timer
		MSTK_voidSetIntervalSingle(1000000, App_voidFillData) ;
	}
	else
	{
		/*Read The Bit Time --> SB =13500 , logical 1 = 2250 , logical0 = 1120*/
		Readings[Counter] = MSTK_u32GetTime() ;
		// Start Timer
		MSTK_voidSetIntervalSingle(1000000, App_voidFillData) ;
		// increament Counter
		Counter++ ;
	}
}

int main(void)
{
	/*Step 1 : SystemClock is 16 MHZ from HSI*/
	MRCC_errInitSystemClk() ;
	/*Step 2 : Enable GPIOA Clock*/
	MRCC_errEnablePeripherialClk(MRCC_AHB1,MRCC_GPIOA_EN) ;
	/*Step 3: PA0 --> Input/float --> EXTI0*/
	MGPIO_errSetPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_MODE_INPUT) ;
	MGPIO_errSetPullType(MGPIO_PORTA,MGPIO_PIN0,MGPIO_PULL_OFF) ;
	/*Step 4: PA1 --> output , Out put Push Pull*/
	MGPIO_errSetPinMode(MGPIO_PORTA,MGPIO_PIN1,MGPIO_MODE_OUTPUT) ;
	MGPIO_errSetPinOutType(MGPIO_PORTA,MGPIO_PIN1,MGPIO_OUTPUT_PUSHPULL) ;
	/*Step 5: Set EXTI0 -> Failing Edge*/
	MEXTI_errSetSenseLevel(EXTI_LINE0,MEXTI_FALLING_EDGE);
	/*Step 6: Set Call back Function*/
	MEXTI_errSetCallBackEXTI0(App_voidGetFrame) ;
	/*Step 7: Enable EXTI from the Peripherial*/
	MEXTI_errEnableExtiLine(EXTI_LINE0,MGPIO_PORTA) ;
	/*Step 8: Enable EXTI from the NVIC*/
    MNVIC_errEnablePerInterrupt(EXTI0) ;
    /*Step 9 : Initialize Timer -> AHB/8 -> 1 tick = 0.5 microsecond*/
	MSTK_Init() ;
	while(1)
	{
		/*Do Nothing*/
	}
}

