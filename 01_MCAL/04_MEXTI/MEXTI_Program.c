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

/***********************************************************************************************************/
/*                                      MEXTI  Functions implementation                                    */
/***********************************************************************************************************/


ES_t   MEXTI_errInit(void)
{
// TODO -> Ghada with config File
       ES_t Loc_State=ES_OK;
#if    EXT_INT_LEVEL==MEXTI_RISING_EDGE
       SET_BIT(MEXTI->RTSR ,EXT_INT_LINE_NUM ) ;
       CLR_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;

#elif  EXT_INT_LEVEL==MEXTI_FALLING_EDGE
       SET_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;
       CLR_BIT(MEXTI->RTSR , EXT_INT_LINE_NUM ) ;

#elif  EXT_INT_LEVEL==MEXTI_ON_CHANGE
       SET_BIT(MEXTI->RTSR , EXT_INT_LINE_NUM ) ;
       SET_BIT(MEXTI->FTSR ,EXT_INT_LINE_NUM ) ;
#else
       ES_t Loc_State=ES_NOK;
#endif
      return Loc_State;
}
ES_t       MEXTI_errEnableExtiLine(u8 Copy_u8Line , u8 Copy_u8Port)
{
	u8 Local_u8RegIndex = 0;
	
	if (Copy_u8Line > MAXEXTILINES) {
		return ES_NOK; 
	}else if (Copy_u8Line <= 3){
		Local_u8RegIndex = 0;
	}else if (Copy_u8Line <= 7){
		Local_u8RegIndex = 1;
		Copy_u8Port -= 4;
	}else if (Copy_u8Line <= 11){
		Local_u8RegIndex = 2;
		Copy_u8Port -= 8;
	}else if (Copy_u8Line <= 15){
		Local_u8RegIndex = 3;
		Copy_u8Port -= 12;
	}
	
	EXTI -> EXTICR[Copy_u8Line] &~ = ((0b1111) << ((Copy_u8Line*4));
	EXTI -> EXTICR[Copy_u8Line] |= ((Copy_u8Port) << ((Copy_u8Line*4));
	SET_BIT(MEXTI -> IMR , Copy_u8Line);
	return ES_OK;	
}

ES_t       MEXTI_errDisableExtiLine(u8 Copy_u8Line , u8 Copy_u8Port)            
{
	u8 Local_u8RegIndex = 0;
	
	if (Copy_u8Line > MAXEXTILINES) {
		return ES_NOK; 
	}else if (Copy_u8Line <= 3){
		Local_u8RegIndex = 0;
	}else if (Copy_u8Line <= 7){
		Local_u8RegIndex = 1;
		Copy_u8Port -= 4;
	}else if (Copy_u8Line <= 11){
		Local_u8RegIndex = 2;
		Copy_u8Port -= 8;
	}else if (Copy_u8Line <= 15){
		Local_u8RegIndex = 3;
		Copy_u8Port -= 12;
	}
	
	EXTI -> EXTICR[Copy_u8Line] &~ = ((0b1111) << ((Copy_u8Line*4));
	
	CLR_BIT(MEXTI -> IMR , Copy_u8Line);
	
	return ES_OK;
}
ES_t       MEXTI_errSetSoftwareExtiLine(u8 Copy_u8Line)
{
// TODO -> Mousa
}
ES_t       MEXTI_errSetCallBackEXTI0(void (*PFunc) (void))
{
// TODO  -> Mohamed Said
}
ES_t       MEXTI_errSetCallBackEXTI1(void (*PFunc) (void))
{
// TODO  -> Mohamed Said
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




void EXTI0_IRQHandler(void)
{
	// TODO  -> Mohamed Said

}
void EXTI1_IRQHandler(void)
{
	// TODO  -> Mohamed Said

}
