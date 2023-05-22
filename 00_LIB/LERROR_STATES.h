/***********************************************************************************************************/
/* Author :                           Mohamed Yehia El-Greatly                                             */
/* Description :                          LERROR_STATES.h                                                  */
/***********************************************************************************************************/
/* Version : V1.0.0                                                                                        */
/* Date : 28 Apri 2023                                                                                     */
/***********************************************************************************************************/
/* Version : V1.0.1                                                                                        */
/* Date : 13 may 2023                                                                                      */
/***********************************************************************************************************/

/***********************************************************************************************************/
/*                               Guard of file with Call on Time in .c                                     */
/***********************************************************************************************************/


#ifndef ERROR_STATES_H
#define ERROR_STATES_H
       
/***********************************************************************************************************/
/*                                     Enumerators for Errors                                              */
/***********************************************************************************************************/

typedef enum 
{
	ES_NOK,                 //The function dosen't work successfully
	ES_OK ,                 //The function done successfully
	ES_OUT_OF_RANGE_PIN,    //The user enter number of PIN more than PORT PINs    or negative number
	ES_OUT_OF_RANGE_EXTI_LINES, //The user enter number of EXTI Line more than valid range(0-15) or negative number
	ES_OUT_OF_RANGE_PORT,   //The user enter number of PORT more than MC PORTs  or negative number
	ES_OUT_OF_RANGE_PRE_INT,//The user enter number of INT more than PRE INT or negative number
	ES_WRONG_PINs_VALUE,    //The user enter wrong value to assign group of PINs      or negative value
	ES_WRONG_MODE_VALUE,    //The user enter wrong value to configure specific mode or negative value
	ES_INVALID_PIN_SPEED,
	ES_INVALID_EXTI_SENSE_LEVEL,  //The user enter wrong value to configure EXTI LINE sensing mode or negative value
	ES_NULL_POINTER,         //The user enter  NULL pointer  ,  detect it before accessing  it
}ES_t ; 

#endif 
