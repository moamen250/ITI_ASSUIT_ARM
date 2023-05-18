/*#########################################################################################################*/
/**************************************************************************/
/*Author            : 3'ada m7moud                                       */
/*Version           : V1.0.0                                              */
/*Date              : 14 May 2023                                       */
/*Description       : HDCMOTOR_Interface.h                                  */

/**************************************************************************/


/*###########################################################################################################*/
/*@Features  :                                                                                               */
/*                  -
 *        - HDCMOTOR_DCMOTOR_Init()                                                                          */
/*        - HDCMOTOR_DCMOTOR_Set_CLKWise()                                                                   */
/*        - HDCMOTOR_DCMOTOR_Set_ACLKWise
 *        - HDCMOTOR_DCMOTOR_OFF()                                                                   */
/*@Future Update :                                                                                           */
/*                  - Write More APIs                                                                        */
/*###########################################################################################################*/


/*##########################################################################################################*/
/*    - What i sell To customer ?                                         */
/*               * The Architect Give The APIs                            */
/*                          1-  The Name of Function                      */
/*                          2-  what is the input                         */
/*                          3-  Return Type                               */
/*                                                  */
/**************************************************************************/
#ifndef HDCMOTOR_INTERFACE_H_
#define HDCMOTOR_INTERFACE_H_


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"
#include "MGPIO_Inteface.h"

/*
 * chose dc motor port-->MRCC_GPIOA_EN,MRCC_GPIOB_EN,MRCC_GPIOC_EN
 *
 * */

#define DCMOTOR_PORT    MRCC_GPIOA_EN



/*************************************************************************************************************/
/*                                         Function Prototypes                                               */
/*************************************************************************************************************/

void HDCMOTOR_DCMOTOR_Init(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2,u8 Copy_u8PinMode);
void HDCMOTOR_DCMOTOR_Set_CLKWise(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2);
void HDCMOTOR_DCMOTOR_Set_ACLKWise(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2);
void HDCMOTOR_DCMOTOR_OFF(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2);

#endif /* HDCMOTOR_INTERFACE_H_ */
