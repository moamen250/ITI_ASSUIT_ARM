/***********************************************************************************************************/
/* Author :                           Mohamed Yehia El-Greatly                                             */
/* Description :                         MEXTI_Program.c                                                   */
/***********************************************************************************************************/
/* Version :V1.0.0                                                                                         */
/* Date :     19 May 2023                                                                                  */
/***********************************************************************************************************/

/***********************************************************************************************************/
/*                                          Include  LIB Files                                             */
/***********************************************************************************************************/
#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"
/***********************************************************************************************************/
/*                                        Include Peripherals Files                                        */
/***********************************************************************************************************/

#include  "MEXTI_Private.h"
#include  "MEXTI_Config.h"
#include  "MEXTI_Interface.h"
#include  "MRCC_Interface.h"
#include "MGPIO_Inteface.h"
#include "MNVIC_Interface.h"
/***********************************************************************************************************/
/*                                      MEXTI  Functions implementation                                    */
/***********************************************************************************************************/

void (*EXTI0_PFunk_CallBack)(void);
void (*EXTI1_PFunk_CallBack)(void);

ES_t   MEXTI_errInit(void)
{
// TODO -> Ghada with config File
       ES_t Loc_State=ES_OK;

#if    EXT_INT_LEVEL==MEXTI_RISING_


       SET_BIT(MEXTI->RTSR ,EXT_INT_LINE_NUM ) ;
       CLR_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;

#elif  EXT_INT_LEVEL==MEXTI_FALLING_

       SET_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;
       CLR_BIT(MEXTI->RTSR , EXT_INT_LINE_NUM ) ;

#elif  EXT_INT_LEVEL== MEXTI_ON_CH

       SET_BIT(MEXTI->RTSR , EXT_INT_LINE_NUM ) ;
       SET_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;
#else
       Loc_State=ES_NOK;
#endif
      return Loc_State;
}
ES_t       MEXTI_errEnableExtiLine(u8 Copy_u8Line , MGPIO_uddtPortNum Copy_u8Port)
{
	
	u8 Local_u8RegIndex = ES_OK ;
  if (Copy_u8Line >  MGPIO_PIN15  ||  Copy_u8Port  > MGPIO_PORTC )
  {
	  Local_u8RegIndex = ES_OUT_OF_RANGE_EXTI_LINES;
  }
  else{
	 SYSCFG_EXTICR((Copy_u8Line))  &= ~((0b1111U) << ((Copy_u8Line%4)*4));
	 SYSCFG_EXTICR((Copy_u8Line))  |= ((Copy_u8Port) << ((Copy_u8Line%4)*4));
	 SET_BIT(MEXTI -> IMR , Copy_u8Line);
	 SET_BIT(MEXTI ->EMR  , Copy_u8Line);
  }
	return Local_u8RegIndex;
}

ES_t       MEXTI_errDisableExtiLine(u8 Copy_u8Line , u8 Copy_u8Port)            
{
	u8 Local_u8RegIndex = 0;
	
	if (Copy_u8Line >  MGPIO_PIN15  ||  Copy_u8Port  > MGPIO_PORTC) {
		 Local_u8RegIndex = ES_OUT_OF_RANGE_EXTI_LINES;
		  }
		  else{
			 SYSCFG_EXTICR((Copy_u8Line))  &= ~((0b1111U) << ((Copy_u8Line%4)*4));
			 CLR_BIT(MEXTI -> IMR , Copy_u8Line);
			 CLR_BIT(MEXTI ->EMR  , Copy_u8Line);


		  }
			return Local_u8RegIndex;
}
/***********************************************************************************************************/
/*                                         03_ MEXTI_errSetSoftwareExtiLine                                */
/*                                           @Written by : Moussa Mokhlef                                  */
/***********************************************************************************************************/
/* 1- Function Description                                                                                 */
/*               @brief : SET INTERRUPT BY SOFTWARE                                                        */
/* 2- Function Input                                                                                       */
/*               @param : Copy_uddtExit_Inter_Num                                                          */
/* 3- Function Return                                                                                      */
/*               @return Error status of the function                                                      */
/*                              (E_OK)  : The function done successfully                                   */
/*                              (ES_NOK : The function doesn't done successfully                           */
/***********************************************************************************************************/
ES_t     MEXTI_errSetSoftwareExtiLine(EXTI_INTR_N  Copy_uddtExit_Inter_Num)
{
// TODO -> Mousa
	ES_t Local_ErrorState = ES_OK ;
	if(Copy_uddtExit_Inter_Num > EXTI_INTR_22 )
	{
		Local_ErrorState=ES_NOK;
	}
	SET_BIT(MEXTI->SWIER,Copy_uddtExit_Inter_Num)  ;
	return Local_ErrorState;
}
ES_t       MEXTI_errSetCallBackEXTI0(void (*PFunc) (void))
{
	EXTI0_PFunk_CallBack=PFunc;
}
ES_t       MEXTI_errSetCallBackEXTI1(void (*PFunc) (void))
{
	EXTI1_PFunk_CallBack=PFunc;
}
ES_t       MEXTI_errSetSenseLevel(EXTI_LINE_t Copy_uddtLine , EXTI_Sense_t Copy_uddtSenseType)
{
//DONE___| Ahmed Reda:  
    ES_t Local_uddtSenseErr =ES_OK ;
    
    /* check if the entered EXTI line is within the valid range (Lin0_Line15) */
    if (Copy_uddtLine> EXTI_INVALID_LINE)
    {
        Local_uddtSenseErr=ES_OUT_OF_RANGE_EXTI_LINES;
    }
    else
    {
        /* Disable EXTI line interrupts to change sensing level. */
        CLR_BIT(MEXTI->IMR , Copy_uddtLine ) ;
    
        switch(Copy_uddtSenseType)
        {
            case MEXTI_RISING_EDGE:
                /* Set rising edge trigger for the EXTI line */
                SET_BIT(MEXTI->RTSR , Copy_uddtLine ) ;
                CLR_BIT(MEXTI->FTSR , Copy_uddtLine ) ;
                break;

            case MEXTI_FALLING_EDGE:
                /* Set falling edge trigger for the EXTI line */
                CLR_BIT(MEXTI->RTSR , Copy_uddtLine ) ;
                SET_BIT(MEXTI->FTSR , Copy_uddtLine ) ;
                break;

            case MEXTI_ON_CHANGE:
                /* Set On change trigger for the EXTI line */
                SET_BIT(MEXTI->RTSR , Copy_uddtLine ) ;
                SET_BIT(MEXTI->FTSR , Copy_uddtLine ) ;
                break;

            default:
                Local_uddtSenseErr = ES_INVALID_EXTI_SENSE_LEVEL;
                break;
        }

        /* Enable EXTI line interrupts again after set new sensing level. */
        SET_BIT(MEXTI->IMR , Copy_uddtLine ) ;
    }
    
    return Local_uddtSenseErr;
}

ES_t       MEXTI_errClearPeningEXTI(EXTI_INTR_N Copy_uddEXTI_Num)					
{
	ES_t Local_ErrorState = ES_OK ;
	if (Copy_uddEXTI_Num <= EXTI_INTR_1) { MEXTI->PR = (1U << Copy_uddEXTI_Num);}
	else{Local_ErrorState = ES_WRONG_MODE_VALUE;}
	return Local_ErrorState;
}


void EXTI0_IRQHandler(void)
{
	EXTI0_PFunk_CallBack();

	MEXTI->PR = 0x01;
}
void EXTI1_IRQHandler(void)
{
	EXTI1_PFunk_CallBack();

}

