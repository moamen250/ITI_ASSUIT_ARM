/***********************************************************************************************************/
/* Author :                             Mohamed Yehia El-Greatly                                           */
/* Description :                          MEXTI_Interface.h                                                */
/***********************************************************************************************************/
/* Version :V1.0.0                                                                                         */
/* Date :     13 May 2023                                                                                  */
/***********************************************************************************************************/

/*###########################################################################################################*/
/* @Description  :                                                                                           */
/*            The external interrupt/event controller consists of up to 23 edge detectors for generating     */
/*            event/interrupt requests. Each input line can be independently configured to select the type   */
/*            (interrupt or event) and the corresponding trigger event (rising or falling or both). Each line*/
/*            can also masked independently. A pending register maintains the status line of the interrupt   */
/*            requests.                                                                                      */
/*                                                                                                           */
/*     EXTI main features  :   - Independent trigger and mask on each interrupt/event line                   */
/*                             - Dedicated status bit for each interrupt line                                */
/*                             - Generation of up to 23 software event/interrupt requests                    */
/*                             - Detection of external signals with a pulse width lower than the APB2 clock  */
 /*                              period. Refer to the electrical characteristics section of the STM32F4xx    */
/*                               datasheets for details on this parameter.                                   */
/*###########################################################################################################*/
/*@Features  :                                                                                               */
/*                  -  MEXTI_errInit()                                                                       */
/*                  -  MEXTI_errEnableExtiLine()                                                             */
/*                  -  MEXTI_errDisableExtiLine()                                                            */
/*                  -  MEXTI_errSetSoftwareExtiLine()                                                        */
/*                  -  MEXTI_errSetCallBack()                                                                */
/*                  -  MEXTI_errSetSenseLevel()                                                              */
/*@Future Update :                                                                                           */
/*                  - Write Some APIs                                                                        */
/*###########################################################################################################*/
/*************************************************************************************************************/
/*  The Architect Give The APIs                                                                              */
/*                   1-  The Name of Function                                                                */
/*                   2-  What is the input                                                                   */
/*                   3-  Return Type  "Error State"                                                          */
/*                   4-  Object Like Macros                                                                  */
/*************************************************************************************************************/


/*************************************************************************************************************/
/*                             Guard for calling one time in .c files                                        */
/*************************************************************************************************************/
/*#########################################################################################################*/
#ifndef INCLUDE_MEXTI_INTERFACE_H_
#define INCLUDE_MEXTI_INTERFACE_H_
/*#########################################################################################################*/

typedef enum
{
   MEXTI_RISING_EDGE = 0 ,
   MEXTI_FALLING_EDGE    ,
   MEXTI_ON_CHANGE       ,
   MEXTI_SENSE_INVALID
}EXTI_Sense_t ;


typedef enum
{
	EXTI_LINE0 =0,
	EXTI_LINE1   ,
	EXTI_LINE2   ,
	EXTI_LINE3   ,
	EXTI_LINE4   ,
	EXTI_LINE5   ,
	EXTI_LINE6   ,
	EXTI_LINE7   ,
	EXTI_LINE8   ,
	EXTI_LINE9   ,
	EXTI_LINE10  ,
	EXTI_LINE11  ,
	EXTI_LINE12  ,
	EXTI_LINE13  ,
	EXTI_LINE14  ,
	EXTI_LINE15
}EXTI_LINE_t;

ES_t       MEXTI_errInit(void)                       ;
ES_t       MEXTI_errEnableExtiLine(u8 Copy_u8Line , u8 Copy_u8Port)             ;
ES_t       MEXTI_errDisableExtiLine(u8 Copy_u8Line , u8 Copy_u8Port)            ;
ES_t       MEXTI_errSetSoftwareExtiLine(u8 Copy_u8Line)        ;
ES_t       MEXTI_errSetCallBackEXTI0(void (*PFunc) (void))                ;
ES_t       MEXTI_errSetCallBackEXTI1(void (*PFunc) (void))                ;
ES_t       MEXTI_errSetSenseLevel(u8 Copy_u8Line , EXTI_Sense_t Copy_uddtSenseType)              ;


/*************************************************************************************************************/
/*                                   THE END OF DIFINITION                                                   */
/*************************************************************************************************************/
/*#########################################################################################################*/
#endif /* INCLUDE_MEXTI_INTERFACE_H_ */
/*#########################################################################################################*/
